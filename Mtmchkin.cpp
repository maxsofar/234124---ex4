#include "Mtmchkin.h"
#include "Exception.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "utilities.h"
#include "Cards/Gang.h"

#define MAX_NAME_LEN 15
#define TEAM_SIZE_RANGE "23456"

using std::string;
using std::unique_ptr;
using std::ifstream;
using std::cin;

Mtmchkin::Mtmchkin(const string fileName) : m_roundCounter(0), m_numOfPlayers(0),
m_cardTypes {"Barfight", "Fairy", "Merchant", "Pitfall", "Treasure", "Dragon", "Goblin", "Vampire"},
m_battleCardTypes {"Dragon", "Goblin", "Vampire"},
m_gameClasses{"Fighter", "Rogue", "Wizard"}
{
    printStartGameMessage();
    getCardDeck(fileName);
    getPlayers();
}

static bool checkName(const string& name) {
    if (name.length() > MAX_NAME_LEN) {
        return false;
    }
    if (std::all_of(name.begin(), name.end(), [](char c)
        {
            return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
        }))
    {
        return true;
    } else {
        return false;
    }
}

static bool checkClass(const std::vector<string>& gameClasses, const string& playerClass) {
    if (std::find(gameClasses.begin(), gameClasses.end(), playerClass) != gameClasses.end()) {
        return true;
    }

    return false;
}

void Mtmchkin::checkCard(const string& card, int line, bool isGang) const
{
    bool isCardInDeck = true;
    if (!isGang) {
        if (std::find(m_cardTypes.begin(), m_cardTypes.end(), card) == m_cardTypes.end()) {
            isCardInDeck = false;
        }
    } else {
        if (std::find(m_battleCardTypes.begin(), m_battleCardTypes.end(), card)
            == m_battleCardTypes.end())
        {
            isCardInDeck = false;
        }
    }
    
    if (!isCardInDeck) {
        throw(DeckFileFormatError(line));
    }

}

void Mtmchkin::getPlayers()
{
    string teamSize;
    while(true) {
        printEnterTeamSizeMessage();
        getline(cin, teamSize, '\n');
        if (cin.fail() || cin.eof() || teamSize.empty() || teamSize.find_first_not_of(TEAM_SIZE_RANGE) != string::npos) {
            printInvalidTeamSize();
        } else {
            int x = std::stoi(teamSize);
            if (x < 2 || x > 6) {
                printInvalidTeamSize();
            } else {
                m_numOfPlayers = x;
                break;
            }
        }
    }

    string inputName, inputClass;
    int counter = m_numOfPlayers;
    do {
        printInsertPlayerMessage();
        while (true) {
            getline(cin, inputName, ' ');
            getline(cin, inputClass);
            if (!checkName(inputName)) {
                printInvalidName();
            } else if (!checkClass(m_gameClasses, inputClass)) {
                printInvalidClass();
            } else {
                m_players.push_back(move(m_playersMap[inputClass]->createInstance(inputName)));
                break;
            }
        }
    } while(--counter > 0);
}

void Mtmchkin::getCardDeck(const string& fileName)
{
    ifstream source(fileName);
    if (!source) {
        throw(DeckFileNotFound());
    }
    string card;
    int cardCount = 0, gangCount = 0;
    for (; getline(source, card); ++cardCount)
    {
        if (card == "Gang")
        {
            unique_ptr<Gang> gang = unique_ptr<Gang>(new Gang());
            getline(source, card);

            while (card != "EndGang") {
                checkCard(card, cardCount + gangCount + 1, true);
                gang->setCardStack(m_cardsMap[card]->createInstance());
                getline(source, card);
                ++gangCount;
                ++cardCount;
                if (cin.eof()) {
                    throw (DeckFileFormatError(cardCount));
                }
            }
            m_cardDeck.push_back(move(gang));
            gangCount = 0;
        } else {
            checkCard(card, cardCount - gangCount + 1);
            m_cardDeck.push_back(move(m_cardsMap[card]->createInstance()));
        }
    }
    if (cardCount < MIN_DECK_SIZE) {
        throw(DeckFileInvalidSize());
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCounter;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = 1;
    for (const unique_ptr<Player>& player : m_winners) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }

    for (const unique_ptr<Player>& player : m_players) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }

    for (const unique_ptr<Player>& player : m_losers) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }
}

bool Mtmchkin::isGameOver() const
{
    if (m_players.empty()) {
        return true;
    }
    return false;
}

void Mtmchkin::playNextCard(Player& somePlayer)
{
    m_cardDeck.front()->applyEncounter(somePlayer);
    m_cardDeck.push_back(move(m_cardDeck.front()));
    m_cardDeck.pop_front();
}

void Mtmchkin::playRound()
{
    ++m_roundCounter;
    printRoundStartMessage(getNumberOfRounds());
    for (int i = m_numOfPlayers; i > 0; --i) {
        printTurnStartMessage(m_players.front()->getName());
        playNextCard(*m_players.front());
        if (m_players.front()->isKnockedOut()) {
            m_losers.push_front(move(m_players.front()));
            m_players.pop_front();
            --m_numOfPlayers;
        } else if (m_players.front()->getLevel() == MAX_LEVEL) {
            m_winners.push_back(move(m_players.front()));
            m_players.pop_front();
            --m_numOfPlayers;
        } else if (m_numOfPlayers > 1) {
            m_players.push_back(move(m_players.front()));
            m_players.pop_front();
        }
    }
    if(isGameOver()) {
        printGameEndMessage();
    }
}
