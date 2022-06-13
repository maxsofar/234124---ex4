#include "Treasure.h"

static CardStats getStats()
{
    CardStats treasureStats(0, 0, 0, 0, 10);
    return  treasureStats;
}

Treasure::Treasure() : Card(getStats(), "Treasure")
{}

void Treasure::applyEncounter(Player &player)
{
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}