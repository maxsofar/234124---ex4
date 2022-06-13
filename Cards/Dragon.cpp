#include "Dragon.h"

static CardStats getStats()
{
    static const CardStats dragonStats(25, 999999, 0, 0, 1000);
    return  dragonStats;
}

Dragon::Dragon() : Card(getStats(), "Dragon")
{}

std::ostream& operator<<(std::ostream& os, const Dragon&)
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, getStats().force, getStats().hpLossOnDefeat, getStats().loot, true);
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