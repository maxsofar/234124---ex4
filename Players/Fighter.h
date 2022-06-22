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
    explicit Fighter(const std::string& playerName);

    /*
     * Get the attack strength of the player
     *
     * @return
     *      the sum of force points and player's level
     */
    int getAttackStrength() const override;

    /*
     * Auxiliary printing function
     *
     * @return
     *          void
     */
    void print(std::ostream& os) const override;

    /*
     * Default D'tor
     */
    ~Fighter() override = default;

    /*
     * Explicitly deleted Copy C'tor and Assignment operator
     */
    Fighter(const Fighter&) = delete;
    Fighter& operator=(const Fighter&) = delete;

private:
    static const int FORCE_MULTIPLIER = 2;
};
#endif //EX4_FIGHTER_H
