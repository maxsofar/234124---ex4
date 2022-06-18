#include "Card.h"

Card::Card(const CardStats& stats, const std::string& name)
        : m_stats(stats), m_name(name)
{}

void Card::print(std::ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const Card& someCard)
{
    someCard.print(os);
    return os;
}
