#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card {
public:
    /*
     * C'tor of Vampire class
     *
     * @return
     *      A new instance of Vampire card.
    */
    Vampire();

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Vampire() override = default;
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire&) = default;

    /*
     * Handling the player's applyEncounter with the Vampire card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;

private:
    static const int FORCE = 10;
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
    friend std::ostream& operator<<(std::ostream& os, const Vampire&);
};


#endif //EX4_VAMPIRE_H
