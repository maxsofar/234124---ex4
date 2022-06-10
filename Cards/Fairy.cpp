#include "Fairy.h"


static const CardStats fairyStats(0, 0, 0, 10, 0);

Fairy::Fairy() : Card(CardType::Fairy, fairyStats, "Fairy")
{}

void Fairy::applyEncounter(Player &player)
{
    if (player.whatCharacter() == "Wizard") {
        player.heal(m_stats.heal);
        printFairyMessage(true);
    } else {
        printFairyMessage(false);
    }
}