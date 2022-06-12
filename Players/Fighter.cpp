#include "Fighter.h"

Fighter::Fighter(std::string playerName)
        : Player(std::move(playerName), Character::Fighter)
{}

int Fighter::getAttackStrength()
{
    return 2*m_force + m_level;
}