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
    virtual Card* createInstance() = 0;
};

template <class CardType>
class CardFactory : public cFactory {
public:
    Card* createInstance();
};

template <class CardType>
Card* CardFactory<CardType>::createInstance()
{
    return new CardType();
}

static void cardFactoryMapper(std::unordered_map<std::string, cFactory*>& factoryMap)
{
    factoryMap["Barfight"] = new CardFactory<Barfight>();
    factoryMap["Vampire"] = new CardFactory<Vampire>();
    factoryMap["Dragon"] = new CardFactory<Dragon>();
    factoryMap["Fairy"] = new CardFactory<Fairy>();
    factoryMap["Pitfall"] = new CardFactory<Pitfall>();
    factoryMap["Goblin"] = new CardFactory<Goblin>();
    factoryMap["Merchant"] = new CardFactory<Merchant>();
    factoryMap["Treasure"] = new CardFactory<Treasure>();
}
#endif //EX4_OBJECTFACTORY_H
