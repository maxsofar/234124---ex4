#include "Treasure.h"

Treasure::Treasure() : Card(CardStats (0, 0, 0, 10), "Treasure")
{}

void Treasure::applyEncounter(Player &player)
{
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}