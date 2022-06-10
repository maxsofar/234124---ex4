#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:
    Wizard(std::string playerName);
    ~Wizard() = default;
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard&) = default;
    void heal(int hpAmount) override;


private:
};
#endif //EX4_WIZARD_H
