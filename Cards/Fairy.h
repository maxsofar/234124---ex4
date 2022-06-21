#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    /*
     * C'tor of Fairy class
     *
     * @return
     *      A new instance of Fairy card.
    */
    Fairy();

    /*
     * Default D'tor
    */
    ~Fairy() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Fairy(const Fairy&) = delete;
    Fairy& operator=(const Fairy&) = delete;

    /*
     * Handling the player's applyEncounter with the Fairy card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int HEAL_AMOUNT = 10;
};
#endif //EX4_FAIRY_H
