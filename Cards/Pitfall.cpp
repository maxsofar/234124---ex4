#include "Pitfall.h"

static CardStats getStats()
{
    CardStats pitfallStats(0, 10, 0, 0, 0);
    return  pitfallStats;
}

Pitfall::Pitfall() : Card(getStats(), "Pitfall")
{}

void Pitfall::applyEncounter(Player &player)
{
    if (player.getCharacter() == "Rogue") {
        printPitfallMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printPitfallMessage(false);
    }
}