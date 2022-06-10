#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Goblin : public Card {
public:
    Goblin();
    ~Goblin() override = default;
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin&) = default;
    void applyEncounter(Player& player) override;


private:
    friend std::ostream& operator<<(std::ostream& os, const Goblin&);
};
#endif //EX4_GOBLIN_H
