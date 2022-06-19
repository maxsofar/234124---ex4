#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    /*
     * C'tor of Merchant class
     *
     * @return
     *      A new instance of Merchant card.
    */
    Merchant();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Merchant() override = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant&) = default;

    /*
     * Handling the player's applyEncounter with the Merchant card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
};
#endif //EX4_MERCHANT_H
