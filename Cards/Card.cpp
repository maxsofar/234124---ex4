#include "Card.h"

Card::Card(const CardStats& stats, const std::string& name)
        : m_stats(stats), m_name(name)
{}

std::ostream& operator<<(std::ostream& os, const Card& someCard)
{
    printCardDetails(os, someCard.m_name);
    printEndOfCardDetails(os);
    return os;
}