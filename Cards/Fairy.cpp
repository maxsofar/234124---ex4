#include "Fairy.h"

Fairy::Fairy() : Card(CardStats (0, 0, HEAL_AMOUNT, 0), "Fairy")
{}

void Fairy::applyEncounter(Player &player) const
{
    if (player.getCharacter() == Character::Wizard) {
        player.heal(m_stats.heal);
        printFairyMessage(true);
    } else {
        printFairyMessage(false);
    }
}