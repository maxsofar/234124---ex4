#include "Goblin.h"
#include "utilities.h"

static const CardStats goblinStats(6, 10, 0, 0, 2);

Goblin::Goblin() : Card(CardType::Battle, goblinStats, "Goblin")
{}

std::ostream& operator<<(std::ostream& os, const Goblin&)
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, goblinStats.force, goblinStats.hpLossOnDefeat, goblinStats.loot);
    printEndOfCardDetails(os);
    return os;
}

void Goblin::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.force) { //TODO: Battle cards code duplication
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Goblin");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), "Goblin");
    }
}