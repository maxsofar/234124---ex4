#include "Barfight.h"

Barfight::Barfight() : Card(CardStats (0, 10, 0, 0), "Barfight")
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