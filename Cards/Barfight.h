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
     * Default D'tor
    */
    ~Barfight() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Barfight(const Barfight&) = delete;
    Barfight& operator=(const Barfight&) = delete;

    /*
     * Handling the player's applyEncounter with the Barfight card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int HP_LOSS = 10;
};
#endif //EX4_BARFIGHT_H
