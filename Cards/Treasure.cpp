#include "Treasure.h"

static const CardStats treasureStats(0, 0, 0, 0, 10);

Treasure::Treasure() : Card(CardType::Treasure, treasureStats, "Treasure")
{}

void Treasure::applyEncounter(Player &player)
{
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}