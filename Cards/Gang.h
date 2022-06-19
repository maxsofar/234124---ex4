#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "BattleCard.h"
#include <deque>
#include <string>
#include <memory>

class Gang : public Card {
public:
    /*
     * C'tor of Gang class
     *
     * @return
     *      A new instance of Gang card.
    */
    Gang();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Gang() override = default;
    Gang(const Gang&) = default;
    Gang& operator=(const Gang&) = default;

    void setCardStack(std::unique_ptr<Card> cardPtr); //TODO: docs

    /*
     * Handling the player's applyEncounter with the Gang card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    std::deque<std::unique_ptr<BattleCard>> m_cardDeck;
    //std::deque<std::unique_ptr<Card>> m_cardDeck;
};

#endif //EX4_GANG_H
