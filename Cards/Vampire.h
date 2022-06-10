#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card {
public:
    Vampire();
    ~Vampire() override = default;
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire&) = default;
    void applyEncounter(Player& player) override;


private:
    friend std::ostream& operator<<(std::ostream& os, const Vampire&);
};


#endif //EX4_VAMPIRE_H
