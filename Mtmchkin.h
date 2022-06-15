#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include "Cards/Card.h"
#include <vector>
#include <deque>
#include "Cards/CardFactory.h"
#include "Players/PlayersFactory.h"

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::unique_ptr<Card>> m_cardDeck;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;

    int m_roundCounter;
    int m_numOfPlayers;
    CardFactory::CardsMap m_cardsMap;
    PlayersFactory::PlayersMap m_playersMap;

    void getCardDeck(const std::string& fileName);
    void getPlayers();
    void playNextCard(Player& somePlayer);
};

#endif /* MTMCHKIN_H_ */
