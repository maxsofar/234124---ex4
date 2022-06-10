#include "Wizard.h"
#include "utilities.h"

Wizard::Wizard(std::string playerName)
    : Player(playerName, Character::Wizard)
{}

void Wizard::heal(int hpAmount)
{

    if (hpAmount < 0) {
        return;
    }
    else if (2*hpAmount > m_HP.getMaxHP() - m_HP.getHP()) {
        m_HP = m_HP.getMaxHP();
    } else {
        m_HP += 2*hpAmount;
    }
}