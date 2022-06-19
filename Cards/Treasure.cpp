#include "Treasure.h"

Treasure::Treasure() : Card(CardStats (0, 0, 0, LOOT), "Treasure")
{}

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}