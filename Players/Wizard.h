#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:
    /*
     * C'tor of the Wizard:
     *
     * @param playerName  - The name of the player.
     * @return
     *      An instance of Wizard
     */
    explicit Wizard(const std::string& playerName);

    /*
     * Default D'tor, copy C'tor, assignment operator overload
     */
    ~Wizard() override = default;
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard&) = default;

    /*
     * Increase the player's HP by given number of points with the limit of maxHP
     * @param hpAmount the number of points to be added
     *
     * @return
     *      void
     */
    void heal(int hpAmount) override;

private:
    static const int HEAL_MULTIPLIER = 2;
 };
#endif //EX4_WIZARD_H
