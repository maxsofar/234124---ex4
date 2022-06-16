#include "Mtmchkin.h"
#include "Exception.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "utilities.h"


using std::string;
using std::unique_ptr;
using std::ifstream;
using std::cin;


Mtmchkin::Mtmchkin(const string fileName) : m_roundCounter(0), m_numOfPlayers(0)
{
    getCardDeck(fileName);
    getPlayers();
}

static bool checkName(const string& name) {
    if (name.length() > 15) {
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

static bool checkClass(const string& playerClass) {
    std::vector<string> gameClasses{"Fighter", "Rogue", "Wizard"};

    if (std::find(gameClasses.begin(), gameClasses.end(), playerClass) != gameClasses.end()) {
        return true;
    }

    return false;
}

static void checkCard(const string& card, int line)
{
    std::vector<string> cards {"Barfight", "Dragon", "Fairy", "Goblin", "Merchant",
                                          "Pitfall", "Treasure", "Vampire"};

    if (std::find(cards.begin(), cards.end(), card) == cards.end()) {
        throw(DeckFileFormatError(line));
    }
}

void Mtmchkin::getPlayers()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    while(true) {
        cin >> m_numOfPlayers;
        if (m_numOfPlayers < 2 || m_numOfPlayers > 6) {
            printInvalidTeamSize();
        } else {
            cin.ignore();
            break;
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
            } else if (!checkClass(inputClass)) {
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
    int cardCount = 1;
    for (; getline(source, card); ++cardCount) {
        checkCard(card, cardCount);
        m_cardDeck.push_back(move(m_cardsMap[card]->createInstance()));
    }
    if (cardCount < 5) {
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
        } else if (m_players.front()->getLevel() == 10) {
            m_winners.push_back(move(m_players.front()));
            m_players.pop_front();
            --m_numOfPlayers;
        }
        if (m_numOfPlayers > 1) {
            m_players.push_back(move(m_players.front()));
            m_players.pop_front();
        }
    }
    if(isGameOver()) {
        printGameEndMessage();
    }
}
