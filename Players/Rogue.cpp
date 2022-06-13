#include "Rogue.h"

Rogue::Rogue(const std::string& playerName)
        : Player(playerName, Character::Rogue)
{}

void Rogue::addCoins(int amount)
{
    if (amount < 0) {
        return;
    }
    m_coins += 2*amount;
}