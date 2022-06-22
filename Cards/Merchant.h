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
    * Default D'tor
   */
    ~Merchant() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Merchant(const Merchant&) = delete;
    Merchant& operator=(const Merchant&) = delete;

    /*
     * Handling the player's applyEncounter with the Merchant card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    static const int FORCE_BUFF_COST = 10;
    static const int FORCE_BUFF_AMOUNT = 1;
    static const int HP_BUFF_COST = 5;
    static const int HP_BUFF_AMOUNT = 1;
};
#endif //EX4_MERCHANT_H
