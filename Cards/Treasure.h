#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();
    ~Treasure() = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure&) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_TREASURE_H
