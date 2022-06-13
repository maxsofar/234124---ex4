#include "Barfight.h"

static CardStats getStats()
{
    CardStats barfightStats(0, 10, 0, 10, 0);
    return  barfightStats;
}

Barfight::Barfight() : Card(getStats(), "Barfight")
{}

void Barfight::applyEncounter(Player &player)
{
    if (player.getCharacter() == "Fighter") {
        printBarfightMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printBarfightMessage(false);
    }
}