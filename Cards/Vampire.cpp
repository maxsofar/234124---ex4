#include "Vampire.h"
#include "utilities.h"

static const CardStats vampireStats(10, 10, 0, 0, 2);

Vampire::Vampire() : Card(CardType::Battle, vampireStats, "Vampire")
{}

std::ostream& operator<<(std::ostream& os, const Vampire&)
{
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, vampireStats.force, vampireStats.hpLossOnDefeat, vampireStats.loot);
    printEndOfCardDetails(os);
    return os;
}

void Vampire::applyEncounter(Player &player)
{
    if (player.getAttackStrength() >= m_stats.force) { //TODO: Battle cards code duplication
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Vampire");
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        player.loseForce();
        printLossBattle(player.getName(), "Vampire");
    }
}
