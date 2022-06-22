#include "Rogue.h"
#include "../utilities.h"

Rogue::Rogue(const std::string& playerName)
        : Player(playerName)
{}

void Rogue::addCoins(int amount)
{
    if (amount < 0) {
        return;
    }
    m_coins += LOOT_MULTIPLIER * amount;
}

void Rogue::print(std::ostream &os) const
{
    printPlayerDetails(os, m_name, "Rogue", m_level, m_force,m_HP.getHP(), m_coins);
}
