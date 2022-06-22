#include "Fighter.h"
#include "../utilities.h"

Fighter::Fighter(const std::string& playerName)
        : Player(playerName)
{}

int Fighter::getAttackStrength() const
{
    return FORCE_MULTIPLIER*m_force + m_level;
}

void Fighter::print(std::ostream &os) const
{
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force,m_HP.getHP(), m_coins);
}