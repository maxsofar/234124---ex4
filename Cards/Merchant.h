#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    Merchant();
    ~Merchant() = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant&) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_MERCHANT_H
