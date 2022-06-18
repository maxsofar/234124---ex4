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
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Vampire() override = default;
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire&) = default;

    /*
     * Handling the player's applyEncounter with the Vampire card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;

private:
    static const int FORCE = 10;
    static const int HP_LOSS = 10;
    static const int LOOT = 2;
};


#endif //EX4_VAMPIRE_H
