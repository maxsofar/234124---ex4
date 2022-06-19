#ifndef EX4_CARDFACTORY_H
#define EX4_CARDFACTORY_H

#include "Card.h"
#include <string>
#include <unordered_map>
#include <memory>

namespace CardFactory {

    class Factory {
    public:
        /*
         * Default D'tor
         */
        virtual ~Factory() = default;

        /*
         * Explicitly deleted Copy C'tor and assigment operator
         */
        Factory(const Factory&) = delete;
        Factory& operator=(const Factory&) = delete;

        /*
         * !Pure virtual function!
         * Create pointer to instance of Card
         *
         * @return
         *      Pointer of type Card
         */
        virtual std::unique_ptr<Card> createInstance() const = 0;
    protected:
        /*
         * C'tor of Factory class
         *
         * @return
         *      A new instance of Factory.
         */
        Factory() = default;

    };

    template<class CardType>
    class CardFactory : public Factory {
    public:
        /*
         * C'tor of CardFactory class
         *
         * @return
         *      A new instance of CardFactory.
         */
        CardFactory() = default;

        /*
         * Default D'tor
         */
        ~CardFactory() override = default;

        /*
         * Explicitly deleted Copy C'tor and assigment operator
         */
        CardFactory(const CardFactory&) = delete;
        CardFactory& operator=(const CardFactory&) = delete;

        /*
         * Create pointer to instance of Card
         *
         * @return
         *      Pointer of type Card
         */
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

        /*
         * C'tor of CardsMap class
         *
         * @return
         *      A new instance of CardsMap.
         */
        CardsMap();

        /*
         * Default D'tor
         */
        ~CardsMap() = default;

        /*
         * Explicitly deleted Copy C'tor and assigment operator
         */
        CardsMap(const CardsMap&) = delete;
        CardsMap& operator=(const CardsMap&) = delete;

        /*
         * [] operator overloading
         *
         * @param cardName - the name(type) of card factory
         * @return
         *      Pointer to Factory instance
         */
        std::unique_ptr<Factory>& operator[](const std::string &cardName);

    private:
        std::unordered_map<std::string, std::unique_ptr<Factory>> cardsMap;
    };
}
#endif //EX4_CARDFACTORY_H
