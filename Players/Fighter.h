#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player {
public:
    Fighter(std::string playerName);
    ~Fighter() override = default;
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter&) = default;
    int getAttackStrength() override;


private:
};
#endif //EX4_FIGHTER_H
