#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    /*
     * C'tor of Dragon class
     *
     * @return
     *      A new instance of Dragon card.
    */
    Dragon();

    /*
    * Default D'tor
   */
    ~Dragon() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Dragon(const Dragon&) = delete;
    Dragon& operator=(const Dragon&) = delete;

    /*
     * Handling the player's applyEncounter with the Dragon card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int FORCE = 25;
    static const int HP_LOSS = 999999;
    static const int LOOT = 1000;
};
#endif //EX4_DRAGON_H
