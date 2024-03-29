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
    static const int MAX_LEVEL = 10;
    static const int MIN_DECK_SIZE = 5;
    static const int TEAM_SIZE_LOWER_BOUND = 2;
    static const int TEAM_SIZE_UPPER_BOUND = 6;

    std::deque<std::unique_ptr<Card>> m_cardDeck;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;

    int m_roundCounter;
    int m_numOfPlayers;
    const std::vector<std::string> m_cardTypes;
    const std::vector<std::string> m_battleCardTypes;
    const std::vector<std::string> m_gameClasses;

    CardFactory::CardsMap m_cardsMap;
    PlayersFactory::PlayersMap m_playersMap;

    /*
    *  Parses cards from text file, and stores them
    *
    *  @param fileName - Name of the file that contains game cards names.
    *  @return
    *          void
    */
    void getCardDeck(const std::string& fileName);

    /*
    *   Receives and checks team size input.
    *
    *  @return
    *          void
    */
    void getTeamSize();

    /*
    *   Receives and checks players names.
    *
    *  @return
    *          void
    */
    void getPlayersNames();

    /*
    *  Plays next card with given player, and shuffles the card deck
    *
    *  @param somePlayer -Player that about to play the current card.
    *  @return
    *          void
    */
    void playNextCard(Player& somePlayer);

    /*
     * Checks if card has a right name
     * @param card   - card name to be checked
     * @param line   - line number
     * @param isGang - indicates if the card is part of Gang
     * @return
     *          void
     */
    void checkCard(const std::string& card, int line, bool isGang = false) const;

    /*
     * Explicitly deleted Copy C'tor and assingment operator overloading
     */
    Mtmchkin (const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin&) = delete;


};

#endif /* MTMCHKIN_H_ */
