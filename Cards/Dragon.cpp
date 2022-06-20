#include "Dragon.h"

Dragon::Dragon() : BattleCard(CardStats (FORCE, HP_LOSS, 0, LOOT), "Dragon")
{}

void Dragon::applyEncounter(Player &player) const
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

bool Dragon::applyGangEncounter(Player &player, bool isLost) const
{
    if (!isLost && player.getAttackStrength() >= m_stats.force) {
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Dragon");
        return false;
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), "Dragon");
        return true;
    }
}