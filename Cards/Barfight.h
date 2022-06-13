#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    /*
     * C'tor of Barfight class
     *
     * @return
     *      A new instance of Barfight card.
    */
    Barfight();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Barfight() override = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight&) = default;

    /*
     * Handling the player's applyEncounter with the Barfight card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;
};
#endif //EX4_BARFIGHT_H
