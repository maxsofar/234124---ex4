#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight();
    ~Barfight() override = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight&) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_BARFIGHT_H
