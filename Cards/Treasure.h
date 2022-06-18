#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    /*
     * C'tor of Treasure class
     *
     * @return
     *      A new instance of Treasure card.
    */
    Treasure();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Treasure() override = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure&) = default;

    /*
     * Handling the player's applyEncounter with the Treasure card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;

private:
    static const int LOOT = 10;
};
#endif //EX4_TREASURE_H
