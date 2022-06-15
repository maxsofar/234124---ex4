#include "Dragon.h"

static CardStats getStats()
{
    static const CardStats dragonStats(25, 999999, 0, 1000);
    return  dragonStats;
}

Dragon::Dragon() : Card(getStats(), "Dragon")
{}

std::ostream& operator<<(std::ostream& os, const Dragon&)
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, getStats().m_force, getStats().m_hpLossOnDefeat, getStats().m_loot, true);
    printEndOfCardDetails(os);
    return os;
}

void Dragon::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.m_force) {
        player.levelUp();
        player.addCoins(m_stats.m_loot);
        printWinBattle(player.getName(), "Dragon");
    } else {
        player.damage(m_stats.m_hpLossOnDefeat);
        printLossBattle(player.getName(), "Dragon");
    }
}