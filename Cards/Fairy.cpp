#include "Fairy.h"

static CardStats getStats()
{
    CardStats fairyStats(0, 0, 0, 10, 0);
    return  fairyStats;
}

Fairy::Fairy() : Card(getStats(), "Fairy")
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