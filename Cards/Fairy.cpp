#include "Fairy.h"
#include "../Players/Wizard.h"

Fairy::Fairy() : Card(CardStats (0, 0, HEAL_AMOUNT, 0), "Fairy")
{}

void Fairy::applyEncounter(Player &player) const
{
    const Wizard* ptr = dynamic_cast<const Wizard*>(&player);

    if (ptr != nullptr) {
        player.heal(m_stats.heal);
        printFairyMessage(true);
    } else {
        printFairyMessage(false);
    }
}