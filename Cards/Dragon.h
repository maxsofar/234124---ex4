#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
    /*
     * C'tor of Dragon class
     *
     * @return
     *      A new instance of Dragon card.
    */
    Dragon();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Dragon() override = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon&) = default;

    /*
     * Handling the player's applyEncounter with the Dragon card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;


private:
    static const int FORCE = 25;
    static const int HP_LOSS = 999999;
    static const int LOOT = 1000;

    /*
     * << operator overloading
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @param Card - Card instance that called the operator.
     * @return
     *      I\O stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Dragon&);
};
#endif //EX4_DRAGON_H
