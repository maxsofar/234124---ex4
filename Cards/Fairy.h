#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    Fairy();
    ~Fairy() = default;
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy&) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_FAIRY_H
