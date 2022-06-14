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
#include <memory>

namespace CardFactory {

    class Factory {
    public:
        virtual ~Factory() = default;
        Factory(const Factory&) = delete;
        Factory& operator=(const Factory&) = delete;

        virtual std::unique_ptr<Card> createInstance() const = 0;
    protected:
        Factory() = default;

    };

    template<class CardType>
    class CardFactory : public Factory {
    public:
        CardFactory() = default;
        ~CardFactory() override = default;
        CardFactory(const CardFactory&) = delete;
        CardFactory& operator=(const CardFactory&) = delete;

        std::unique_ptr<Card> createInstance() const override;
    };

    template<class CardType>
    std::unique_ptr<Card> CardFactory<CardType>::createInstance() const
    {
        std::unique_ptr<Card> ptr = std::unique_ptr<Card>(new CardType());
        return ptr;
    }

    class CardsMap {
    public:
        CardsMap();

        ~CardsMap() = default;
        CardsMap(const CardsMap&) = delete;
        CardsMap& operator=(const CardsMap&) = delete;

        std::unique_ptr<Factory>& operator[](const std::string &cardName);

    private:

        std::unordered_map<std::string, std::unique_ptr<Factory>> cardsMap;
    };
}
#endif //EX4_OBJECTFACTORY_H
