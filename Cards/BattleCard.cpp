#include "BattleCard.h"

BattleCard::BattleCard(const CardStats& stats, const std::string& name) : Card(stats, name)
{}

void BattleCard::print(std::ostream &os) const
{
    bool isDragon = false;
    printCardDetails(os, m_name);
    if (m_name == "Dragon") {
        isDragon = true;
    }
    printMonsterDetails(os, m_stats.force, m_stats.hpLossOnDefeat,m_stats.loot, isDragon);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const BattleCard& someCard)
{
    someCard.print(os);
    return os;
}
