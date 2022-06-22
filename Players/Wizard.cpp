#include "Wizard.h"
#include "../utilities.h"

Wizard::Wizard(const std::string& playerName)
    : Player(playerName)
{}

void Wizard::heal(int hpAmount)
{
    if (hpAmount < 0) {
        return;
    }
    else if (HEAL_MULTIPLIER * hpAmount > m_HP.getMaxHP() - m_HP.getHP()) {
        m_HP = m_HP.getMaxHP();
    } else {
        m_HP += HEAL_MULTIPLIER * hpAmount;
    }
}

void Wizard::print(std::ostream &os) const
{
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force,m_HP.getHP(), m_coins);
}
