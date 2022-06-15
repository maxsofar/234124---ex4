#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

struct CardStats{
    int m_force;  // The m_force of the monster
    int m_loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int m_hpLossOnDefeat; // The amount of hp you lose when losing the battle
    int m_heal; // The amount of HP you get when buying a "HEAL" card

    /*
     *C'tor of CardStats:
     *
     * @param m_force - The m_force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param m_heal - The amount of HP is given when buying a "Heal" card.
     * @param m_loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int heal = 0, int loot = 0)
    {
        this->m_force = force;
        this->m_hpLossOnDefeat = hpLoss;
        this->m_heal = heal;
        this->m_loot = loot;
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

    /*
     * Default D'tor
     */
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
