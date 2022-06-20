#include "Goblin.h"

Goblin::Goblin() : BattleCard(CardStats(FORCE, HP_LOSS, 0, LOOT), "Goblin")
{}

void Goblin::applyEncounter(Player &player) const
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

bool Goblin::applyGangEncounter(Player &player, bool isLost) const
{
    if (!isLost && player.getAttackStrength() >= m_stats.force) {
        player.addCoins(m_stats.loot);
        return false;
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), "Goblin");
        return true;
    }
}