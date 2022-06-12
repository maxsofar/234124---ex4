#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player {
public:

    /*
     * C'tor of the Fighter:
     *
     * @param playerName    - The name of the player.
     * @return
     *      An instance of Fighter
     */
    explicit Fighter(std::string playerName);

    /*
     * Default D'tor, copy C'tor, assignment operator overload
     */
    ~Fighter() override = default;
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter&) = default;

    /*
     * Get the attack strength of the player
     *
     * @return
     *      the sum of force points and player's level
     */
    int getAttackStrength() override;
};
#endif //EX4_FIGHTER_H
