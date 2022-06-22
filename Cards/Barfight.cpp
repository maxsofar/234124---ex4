#include "Barfight.h"
#include "../Players/Fighter.h"

Barfight::Barfight() : Card(CardStats (0, HP_LOSS, 0, 0), "Barfight")
{}

void Barfight::applyEncounter(Player &player) const
{
    const Fighter* ptr = dynamic_cast<const Fighter*>(&player);

    if (ptr != nullptr) {
        printBarfightMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printBarfightMessage(false);
    }
}
