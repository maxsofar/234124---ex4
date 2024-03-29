#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {
public:

    /*
     * Handling the player's applyEncounter with Battle card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) const override;

    /*
     * Handles Gang card
     *
     * @param player - the player that encountered the card
     * @param isLost - indicator for lose to one of the cards in Gang
     */
    virtual bool applyGangEncounter(Player &player, bool isLost) const;

    /*
     * Default D'tor
     */
    ~BattleCard() override = default;

    /*
     * Deleted Copy C'tor and assignment operator
    */
    BattleCard(const BattleCard&) = delete;
    BattleCard& operator=(const BattleCard& other) = delete;

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

private:
    /*
     * Prints card info
     *
     * @param ostream - I/O stream the info will be forwarded to.
     * @return
     *          void
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
