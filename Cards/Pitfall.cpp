#include "Pitfall.h"

static const CardStats pitfallStats(0, 10, 0, 0, 0);

Pitfall::Pitfall() : Card(CardType::Pitfall, pitfallStats, "Pitfall")
{}

void Pitfall::applyEncounter(Player &player)
{
    if (player.whatCharacter() == "Rogue") {
        printPitfallMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printPitfallMessage(false);
    }
}