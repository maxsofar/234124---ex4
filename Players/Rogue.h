#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"


class Rogue : public Player {
public:
    /*
     * C'tor of the Rogue:
     *
     * @param playerName  - The name of the player.
     * @return
     *      An instance of Rogue
     */
    explicit Rogue(std::string playerName);

    /*
     * Default D'tor, copy C'tor, assignment operator overload
     */
    ~Rogue() override = default;
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue&) = default;

    /*
     * Increase the amount of player's coins by given number
     * @param amount - number of coins to be added
     *
     * @return
     *      void
     */
    void addCoins(int amount) override;
};

#endif //EX4_ROGUE_H
