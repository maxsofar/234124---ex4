#include "Goblin.h"

static CardStats getStats()
{
    CardStats goblinStats(6, 10, 0, 2);
    return  goblinStats;
}

Goblin::Goblin() : Card(getStats(), "Goblin")
{}

std::ostream& operator<<(std::ostream& os, const Goblin&)
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, getStats().m_force, getStats().m_hpLossOnDefeat, getStats().m_loot);
    printEndOfCardDetails(os);
    return os;
}

void Goblin::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.m_force) {
        player.levelUp();
        player.addCoins(m_stats.m_loot);
        printWinBattle(player.getName(), "Goblin");
    } else {
        player.damage(m_stats.m_hpLossOnDefeat);
        printLossBattle(player.getName(), "Goblin");
    }
}