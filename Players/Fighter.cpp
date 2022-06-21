#include "Fighter.h"

Fighter::Fighter(const std::string& playerName)
        : Player(playerName, Character::Fighter)
{}

int Fighter::getAttackStrength() const
{
    return FORCE_MULTIPLIER*m_force + m_level;
}