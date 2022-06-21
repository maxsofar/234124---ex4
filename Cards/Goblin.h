#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "BattleCard.h"

class Goblin : public BattleCard {
public:
    /*
     * C'tor of Goblin class
     *
     * @return
     *      A new instance of Goblin card.
    */
    Goblin();

    /*
    * Default D'tor
   */
    ~Goblin() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Goblin(const Goblin&) = delete;
    Goblin& operator=(const Goblin&) = delete;

    /*
     * Handling the player's applyEncounter with the Goblin card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int FORCE = 6;
    static const int HP_LOSS = 10;
    static const int LOOT = 2;

};
#endif //EX4_GOBLIN_H
