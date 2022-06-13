#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

struct CardStats{
    int force;  // The force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of hp you lose when losing the battle
    int cost; // The cost of a "Buff/Heal" card
    int heal; // The amount of HP you get when buying a "HEAL" card

    /*
     *C'tor of CardStats:
     *
     * @param force - The force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param cost - The cost of the card when is type is "Buff" or "Heal".
     * @param heal - The amount of HP is given when buying a "Heal" card.
     * @param buff - The amount of force is given when buying a "Buff" card.
     * @param loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int cost = 0, int heal = 0, int loot = 0)
    {
        this->force = force;
        this->hpLossOnDefeat = hpLoss;
        this->cost = cost;
        this->heal = heal;
        this->loot = loot;
    }
};

class Card {
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) = 0;
    virtual ~Card() = default;

protected:
    /*
     * C'tor of Card class
     *
     * @param stats - The numeral stats of the card.
     * @param name  - The name of playing card.
     * @return
     *      A new instance of Card.
    */
    Card(const CardStats& stats, const std::string& name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    //virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    CardStats m_stats;

private:
    std::string m_name;

    /*
     * << operator overloading
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @param Card - Card instance that called the operator.
     * @return
     *      I\O stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Card&);
};

#endif //EX4_CARD_H