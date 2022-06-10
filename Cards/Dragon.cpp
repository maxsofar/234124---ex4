#include "Dragon.h"

static const CardStats dragonStats(25, 1000, 0, 0, 1000); //TODO: dragon hpLoss amount?

Dragon::Dragon() : Card(CardType::Battle, dragonStats, "Dragon")
{}

std::ostream& operator<<(std::ostream& os, const Dragon&)
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, dragonStats.force, dragonStats.hpLossOnDefeat, dragonStats.loot);
    printEndOfCardDetails(os);
    return os;
}

void Dragon::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.force) {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Dragon");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), "Dragon");
    }
}