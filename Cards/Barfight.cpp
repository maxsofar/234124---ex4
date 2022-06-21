#include "Barfight.h"

Barfight::Barfight() : Card(CardStats (0, HP_LOSS, 0, 0), "Barfight")
{}

void Barfight::applyEncounter(Player &player) const
{
    if (player.getCharacter() == Character::Fighter) {
        printBarfightMessage(true);
    } else {
        player.damage(m_stats.hpLossOnDefeat);
        printBarfightMessage(false);
    }
}
