#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    /*
     * Default D'tor
     */
    ~BattleCard() override = default;

    virtual bool applyGangEncounter(Player &player, bool isLost) const;

protected:
    /*
     * C'tor of BattleCard class
     *
     * @param stats - The numeral stats of the card.
     * @param name  - The name of playing card.
     * @return
     *      A new instance of BattleCard.
    */
    BattleCard(const CardStats& stats, const std::string& name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCard(const BattleCard&) = default;
    BattleCard& operator=(const BattleCard& other) = default;

private:
    /*
     * Prints card info
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @return
     *      I\O stream
    */
    void print(std::ostream& os) const override;

    /*
     * << operator overloading
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @param Card - Card instance that called the operator.
     * @return
     *      I\O stream
    */
    friend std::ostream& operator<<(std::ostream& os, const BattleCard&);
};

#endif //EX4_BATTLECARD_H
