#include "Barfight.h"

static const CardStats barfightStats(0, 10, 0, 10, 0);

Barfight::Barfight() : Card(CardType::Barfight, barfightStats, "Barfight")
{}

void Barfight::applyEncounter(Player &player)
{
    if (player.whatCharacter() == "Fighter") {
        printBarfightMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printBarfightMessage(false);
    }
}