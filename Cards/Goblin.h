#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Goblin : public Card {
public:
    /*
     * C'tor of Goblin class
     *
     * @return
     *      A new instance of Goblin card.
    */
    Goblin();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Goblin() override = default;
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin&) = default;

    /*
     * Handling the player's applyEncounter with the Goblin card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;


private:
    static const int FORCE = 6;
    static const int HP_LOSS = 10;
    static const int LOOT = 2;

    /*
     * << operator overloading
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @param Card - Card instance that called the operator.
     * @return
     *      I\O stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Goblin&);
};
#endif //EX4_GOBLIN_H
