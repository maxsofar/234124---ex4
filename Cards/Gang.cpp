#include "Gang.h"
#include <iostream>

typedef std::unique_ptr<BattleCard> CardPtr;

Gang::Gang() : BattleCard(CardStats (), "Gang")
{}

static void printWinMessage(Player &player)
{
    std::cout << "Player " << player.getName() << " has defeated Gang and rose 1 Level!" << std::endl;
}

void Gang::setCardStack(std::unique_ptr<Card> cardPtr)
{
    BattleCard* tmp = dynamic_cast<BattleCard*>(cardPtr.get());
    std::unique_ptr<BattleCard> battleCardPtr;
    if(tmp != nullptr) {
        cardPtr.release();
        battleCardPtr.reset(tmp);
    }
    m_cardDeck.push_back(move(battleCardPtr));
}

void Gang::applyEncounter(Player &player) const
{
    bool isLost = false;
    for (const CardPtr& card : m_cardDeck) {
        if (card->applyGangEncounter(player, isLost)) {
            isLost = true;
        }
    }
    if (!isLost) {
        player.levelUp();
        printWinMessage(player);
    }
}
