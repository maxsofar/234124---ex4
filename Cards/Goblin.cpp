#include "Goblin.h"
#include "utilities.h"

static CardStats getStats()
{
    CardStats goblinStats(6, 10, 0, 0, 2);
    return  goblinStats;
}

Goblin::Goblin() : Card(getStats(), "Goblin")
{}

std::ostream& operator<<(std::ostream& os, const Goblin&)
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, getStats().force, getStats().hpLossOnDefeat, getStats().loot);
    printEndOfCardDetails(os);
    return os;
}

void Goblin::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.force) {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Goblin");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), "Goblin");
    }
}