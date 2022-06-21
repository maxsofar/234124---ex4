#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

struct CardStats{
    int force;  // The force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of hp you lose when losing the battle
    int heal; // The amount of HP you get when buying a "HEAL" card

    /*
     *C'tor of CardStats:
     *
     * @param force - The force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param heal - The amount of HP is given when buying a "Heal" card.
     * @param loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int heal = 0, int loot = 0)
    {
        this->force = force;
        this->hpLossOnDefeat = hpLoss;
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
    virtual void applyEncounter(Player& player) const = 0;

    /*
     * Default D'tor
     */
    virtual ~Card() = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    Card(const Card&) = delete;
    Card& operator=(const Card& other) = delete;

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

    CardStats m_stats;
    std::string m_name;
private:
    /*
     * Prints card info
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @return
     *          void
    */
    virtual void print(std::ostream& os) const;

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
