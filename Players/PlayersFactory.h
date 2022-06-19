#ifndef EX4_PLAYERSFACTORY_H
#define EX4_PLAYERSFACTORY_H

#include "Player.h"
#include <string>
#include <unordered_map>
#include <memory>

namespace PlayersFactory {

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
         * Create pointer to instance of Player
         *
         * @param playerName - The name of a player.
         * @return
         *      Pointer of type Player
         */
        virtual std::unique_ptr<Player> createInstance(const std::string &playerName) const = 0;

    protected:
        /*
         * C'tor of Factory class
         *
         * @return
         *      A new instance of Factory.
        */
        Factory() = default;

    };

    template<class PlayerType>
    class PlayerFactory : public Factory {
    public:
        PlayerFactory() = default;

        /*
         * Default D'tor
         */
        ~PlayerFactory() override = default;

        /*
         * Explicitly deleted Copy C'tor and assigment operator
         */
        PlayerFactory(const PlayerFactory&) = delete;
        PlayerFactory& operator=(const PlayerFactory&) = delete;

        /*
         * Create pointer to instance of Player
         *
         * @param playerName - The name of a player.
         * @return
         *      Pointer of type Player
         */
        std::unique_ptr<Player> createInstance(const std::string &playerName) const override;
    };

    template<class PlayerType>
    std::unique_ptr<Player> PlayerFactory<PlayerType>::createInstance(const std::string &playerName) const
    {
        std::unique_ptr<Player> ptr = std::unique_ptr<Player>(new PlayerType(playerName));
        return ptr;
    }

    class PlayersMap {
    public:
        /*
         * C'tor of PlayersMap class
         *
         * @return
         *      A new instance of PlayersMap.
        */
        PlayersMap();

        /*
         * Default D'tor
         */
        ~PlayersMap() = default;

        /*
         * Explicitly deleted Copy C'tor and assigment operator
         */
        PlayersMap(const PlayersMap&) = delete;
        PlayersMap& operator=(const PlayersMap&) = delete;

        /*
         * [] operator overloading
         *
         * @param playerClass - the class(type) of player factory
         * @return
         *      Pointer to Factory instance
         */
        std::unique_ptr<Factory>& operator[](const std::string &playerClass);

    private:
        std::unordered_map<std::string, std::unique_ptr<Factory>> playersMap;
    };
}

#endif //EX4_PLAYERSFACTORY_H
