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
    explicit Rogue(const std::string& playerName);

    /*
     * Increase the amount of player's coins by given number
     * @param amount - number of coins to be added
     *
     * @return
     *      void
     */
    void addCoins(int amount) override;

    /*
     * Default D'tor
     */
    ~Rogue() override = default;

    /*
     * Explicitly deleted Copy C'tor and Assignment operator
     */
    Rogue(const Rogue&) = delete;
    Rogue& operator=(const Rogue&) = delete;

private:
    static const int LOOT_MULTIPLIER = 2;
};

#endif //EX4_ROGUE_H
