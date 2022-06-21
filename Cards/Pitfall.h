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
     * Default D'tor
    */
    ~Pitfall() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Pitfall(const Pitfall&) = delete;
    Pitfall& operator=(const Pitfall&) = delete;

    /*
     * Handling the player's applyEncounter with the Pitfall card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int HP_LOSS = 10;
};
#endif //EX4_PITFALL_H
