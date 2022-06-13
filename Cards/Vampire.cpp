#include "Vampire.h"

static CardStats getStats()
{
    CardStats vampireStats(10, 10, 0, 0, 2);
    return  vampireStats;
}

Vampire::Vampire() : Card(getStats(), "Vampire")
{}

std::ostream& operator<<(std::ostream& os, const Vampire&)
{
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, getStats().force, getStats().hpLossOnDefeat, getStats().loot);
    printEndOfCardDetails(os);
    return os;
}

void Vampire::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.force) {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Vampire");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        player.loseForce();
        printLossBattle(player.getName(), "Vampire");
    }
}
