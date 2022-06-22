#include "Pitfall.h"
#include "../Players/Rogue.h"

Pitfall::Pitfall() : Card(CardStats (0, HP_LOSS, 0, 0), "Pitfall")
{}

void Pitfall::applyEncounter(Player &player) const
{
    const Rogue* ptr = dynamic_cast<const Rogue*>(&player);
    if (ptr != nullptr) {
        printPitfallMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printPitfallMessage(false);
    }
}