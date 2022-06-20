#include "Vampire.h"

Vampire::Vampire() : BattleCard(CardStats (FORCE, HP_LOSS, 0, LOOT), "Vampire")
{}

void Vampire::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_stats.force) {
        player.addCoins(m_stats.loot);
        player.levelUp();
        printWinBattle(player.getName(), "Vampire");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        player.loseForce();
        printLossBattle(player.getName(), "Vampire");
    }
}

bool Vampire::applyGangEncounter(Player &player, bool isLost) const
{
    if (!isLost && player.getAttackStrength() >= m_stats.force) {
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Vampire");
        return false;
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        player.loseForce();
        printLossBattle(player.getName(), "Vampire");
        return true;
    }
}
