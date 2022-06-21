#include "Dragon.h"

Dragon::Dragon() : BattleCard(CardStats (FORCE, HP_LOSS, 0, LOOT), "Dragon")
{}

void Dragon::print(std::ostream &os) const
{
    printMonsterDetails(os, m_stats.force, m_stats.hpLossOnDefeat,m_stats.loot, true);
    printEndOfCardDetails(os);
}
