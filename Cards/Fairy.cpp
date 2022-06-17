#include "Fairy.h"

Fairy::Fairy() : Card(CardStats (0, 0, 10, 0), "Fairy")
{}

void Fairy::applyEncounter(Player &player)
{
    if (player.getCharacter() == "Wizard") {
        player.heal(m_stats.heal);
        printFairyMessage(true);
    } else {
        printFairyMessage(false);
    }
}