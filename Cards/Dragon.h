#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
    Dragon();
    ~Dragon() override = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon&) = default;
    void applyEncounter(Player& player) override;


private:
    friend std::ostream& operator<<(std::ostream& os, const Dragon&);
};
#endif //EX4_DRAGON_H
