#include "Vampire.h"

Vampire::Vampire() : BattleCard(CardStats (FORCE, HP_LOSS, 0, LOOT), "Vampire")
{}

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
