#include "Mtmchkin.h"
#include "Exception.h"
#include <fstream>
#include "utilities.h"

using namespace std;

static const std::string gameClasses[] = {"Fighter", "Rogue", "Wizard"}; //TODO: Move

Mtmchkin::Mtmchkin(const string fileName) : m_roundCounter(0)
{
    getCardDeck(fileName);
    getPlayers();

}

void Mtmchkin::getPlayers()
{
    playerFactoryMapper(playersMap);
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
            //cin.ignore(); //TODO: ignore \n from manual input?
            getline(cin, inputName, ' ');
            getline(cin, inputClass);
            if (checkName(inputName) || checkClass(inputClass)) {
                printInvalidClass();
            } else {
                m_players.push_back(playersMap[inputClass]->createInstance(inputName));
                break;
            }
        }
    } while(--counter > 0);
}

static void cardCheck(const string& card, int line)
{
    if (card.length() > 15) {
        throw(DeckFileFormatError(line));
    }

    for (char i : card) {
        if (!((i <= 'z' && i >= 'a') || (i <= 'Z' && i >= 'A'))) {
            throw (DeckFileFormatError(line));
        }
    }
}

void Mtmchkin::getCardDeck(const string& fileName)
{
    ifstream source(fileName);
    if (!source) {
        throw(DeckFileNotFound());
    }
    cardFactoryMapper(cardsMap);
    string card;
    int cardCount = 1;
    for (; getline(source, card); ++cardCount) {
        cardCheck(card, cardCount);
        m_cardDeck.push_back(cardsMap[card]->createInstance());
    }
    if (cardCount < 5) {
        throw(DeckFileInvalidSize());
    }
}

bool Mtmchkin::checkName(string& name) {
    if (name.length() > 15) {
        return true;
    }
    return false;
}

bool Mtmchkin::checkClass(string& playerClass) {
    for (const string& gameClass : gameClasses) {
        if (playerClass == gameClass) {
            return false;
        }
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCounter;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = 1;
    for (const Player* player : m_winners) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }

    for (const Player* player : m_players) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }

    for (const Player* player : m_losers) {
        printPlayerLeaderBoard(ranking, *player);
        ++ranking;
    }
}

bool Mtmchkin::isGameOver() const
{
    if (!m_players.size()) {
        return true;
    }
    return false;
}

void Mtmchkin::playNextCard(Player& somePlayer)
{
    m_cardDeck.front()->applyEncounter(somePlayer);
    m_cardDeck.push_back(m_cardDeck.front());
    m_cardDeck.pop_front();
    //rotate(m_cardDeck.begin(),m_cardDeck.begin() + 1, m_cardDeck.end());
}

void Mtmchkin::playRound()
{
    ++m_roundCounter;
    printRoundStartMessage(getNumberOfRounds());
    for (int i = m_numOfPlayers; i > 0; --i) {
        printTurnStartMessage(m_players.front()->getName());
        playNextCard(*m_players.front());
        if (m_players.front()->isKnockedOut()) {
            m_losers.push_front(m_players.front());
            m_players.pop_front();
            --m_numOfPlayers;
        } else if (m_players.front()->getLevel() == 10) {
            m_winners.push_back(m_players.front());
            m_players.pop_front();
            --m_numOfPlayers;
        }
        m_players.push_back(m_players.front());
        m_players.pop_front();
    }
    if(isGameOver()) {
        printGameEndMessage();
    }
}