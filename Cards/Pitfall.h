#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"
class Pitfall : public Card {
public:
    Pitfall();
    ~Pitfall() = default;
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall&) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_PITFALL_H
