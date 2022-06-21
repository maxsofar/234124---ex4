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
     * Default D'tor
     */
    ~Wizard() override = default;

    /*
     * Explicitly deleted Copy C'tor and Assignment operator
     */
    Wizard(const Wizard&) = delete;
    Wizard& operator=(const Wizard&) = delete;

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
