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
    * Default D'tor
   */
    ~Treasure() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Treasure(const Treasure&) = delete;
    Treasure& operator=(const Treasure&) = delete;

    /*
     * Handling the player's applyEncounter with the Treasure card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int LOOT = 10;
};
#endif //EX4_TREASURE_H
