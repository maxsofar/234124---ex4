#include "Card.h"


Card::Card(CardType type, const CardStats& stats, const std::string& name)
    : m_effect(type), m_stats(stats), m_name(name)
{}

std::ostream& operator<<(std::ostream& os, const Card& someCard)
{
    printCardDetails(os, someCard.m_name);
    printEndOfCardDetails(os);
    return os;
}

/*
void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;

        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;

        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;

        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }
}
*/