#include "Dragon.h"

Dragon::Dragon() : Card(CardStats (FORCE, HP_LOSS, 0, LOOT), "Dragon")
{}

std::ostream& operator<<(std::ostream& os, const Dragon& dragon)
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, dragon.m_stats.force, dragon.m_stats.hpLossOnDefeat,
                        dragon.m_stats.loot, true);
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