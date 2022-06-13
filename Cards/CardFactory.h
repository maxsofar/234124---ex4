#ifndef EX4_OBJECTFACTORY_H
#define EX4_OBJECTFACTORY_H

#include "Card.h"
#include "Barfight.h"
#include "Vampire.h"
#include "Fairy.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Pitfall.h"
#include "Treasure.h"
#include "Merchant.h"
#include <string>
#include <unordered_map>

class cFactory {
public:
    virtual std::unique_ptr<Card> createInstance() = 0;
};

template <class CardType>
class CardFactory : public cFactory {
public:
    std::unique_ptr<Card> createInstance() override;
};

template <class CardType>
std::unique_ptr<Card> CardFactory<CardType>::createInstance()
{
    std::unique_ptr<Card> ptr = std::unique_ptr<Card>(new CardType());
    return ptr;
}

#endif //EX4_OBJECTFACTORY_H
