#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "BattleCard.h"

class Vampire : public BattleCard {
public:
    /*
     * C'tor of Vampire class
     *
     * @return
     *      A new instance of Vampire card.
    */
    Vampire();

    /*
     * Handling the player's applyEncounter with the Vampire card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Handles Gang card
     *
     * @param player - the player that encountered the card
     * @param isLost - indicator for lose to one of the cards in Gang
     */
    bool applyGangEncounter(Player& player, bool isLost) const override;

    /*
     * Default D'tor
     */
    ~Vampire() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Vampire(const Vampire&) = delete;
    Vampire& operator=(const Vampire&) = delete;

private:
    static const int FORCE = 10;
    static const int HP_LOSS = 10;
    static const int LOOT = 2;
};


#endif //EX4_VAMPIRE_H
