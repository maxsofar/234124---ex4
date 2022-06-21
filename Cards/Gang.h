#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "BattleCard.h"
#include <deque>
#include <string>
#include <memory>

class Gang : public BattleCard {
public:
    /*
     * C'tor of Gang class
     *
     * @return
     *      A new instance of Gang card.
    */
    Gang();

    /*
    * Defaukt D'tor
   */
    ~Gang() override = default;

    /*
     * Explicitly deleted Copy C'tor and assignment operator
     */
    Gang(const Gang&) = delete;
    Gang& operator=(const Gang&) = delete;

    /*
     * Receives and stores cards belongs to the Gang
     *
     * @param cardPtr - pointer to card instance
     * @return
     *          void
     */
    void setCardStack(std::unique_ptr<Card> cardPtr);

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
