#include "CardFactory.h"
#include "Barfight.h"
#include "Vampire.h"
#include "Fairy.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Pitfall.h"
#include "Treasure.h"
#include "Merchant.h"

using namespace CardFactory;
using std::unique_ptr;

CardsMap::CardsMap()
{
    cardsMap["Barfight"] = unique_ptr<CardFactory<Barfight>>(new CardFactory<Barfight>());
    cardsMap["Vampire"] = unique_ptr<CardFactory<Vampire>>(new CardFactory<Vampire>());
    cardsMap["Dragon"] = unique_ptr<CardFactory<Dragon>>(new CardFactory<Dragon>());
    cardsMap["Fairy"] = unique_ptr<CardFactory<Fairy>>(new CardFactory<Fairy>());
    cardsMap["Pitfall"] = unique_ptr<CardFactory<Pitfall>>(new CardFactory<Pitfall>());
    cardsMap["Goblin"] = unique_ptr<CardFactory<Goblin>>(new CardFactory<Goblin>());
    cardsMap["Merchant"] = unique_ptr<CardFactory<Merchant>>(new CardFactory<Merchant>());
    cardsMap["Treasure"] = unique_ptr<CardFactory<Treasure>>(new CardFactory<Treasure>());
}

unique_ptr<Factory>& CardsMap::operator[](const std::string &cardName)
{
    return cardsMap[cardName];
}
