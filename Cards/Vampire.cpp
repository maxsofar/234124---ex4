#include "Vampire.h"

Vampire::Vampire() : Card(CardStats (10, 10, 0, 2), "Vampire")
{}

std::ostream& operator<<(std::ostream& os, const Vampire& vampire)
{
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, vampire.m_stats.force, vampire.m_stats.hpLossOnDefeat,
                        vampire.m_stats.loot);
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
