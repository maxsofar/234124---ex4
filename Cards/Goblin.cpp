#include "Goblin.h"

Goblin::Goblin() : Card(CardStats(6, 10, 0, 2), "Goblin")
{}

std::ostream& operator<<(std::ostream& os, const Goblin& goblin)
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, goblin.m_stats.force, goblin.m_stats.hpLossOnDefeat,
                        goblin.m_stats.loot);
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