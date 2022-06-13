#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card {
public:
    /*
     * C'tor of Pitfall class
     *
     * @return
     *      A new instance of Pitfall card.
    */
    Pitfall();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Pitfall() override = default;
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall&) = default;

    /*
     * Handling the player's applyEncounter with the Pitfall card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;
};
#endif //EX4_PITFALL_H
