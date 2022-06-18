#include "Pitfall.h"

Pitfall::Pitfall() : Card(CardStats (0, HP_LOSS, 0, 0), "Pitfall")
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