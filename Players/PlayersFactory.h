#ifndef EX4_PLAYERSFACTORY_H
#define EX4_PLAYERSFACTORY_H

#include "Player.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"
#include <string>
#include <unordered_map>
#include <memory>

namespace PlayersFactory {

    class Factory {
    public:
        virtual ~Factory() = default;
        Factory(const Factory&) = delete;
        Factory& operator=(const Factory&) = delete;

        virtual std::unique_ptr<Player> createInstance(const std::string &playerName) const = 0;

    protected:
        Factory() = default;

    };

    template<class PlayerType>
    class PlayerFactory : public Factory {
    public:
        PlayerFactory() = default;
        ~PlayerFactory() override = default;
        PlayerFactory(const PlayerFactory&) = delete;
        PlayerFactory& operator=(const PlayerFactory&) = delete;

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
        PlayersMap();
        ~PlayersMap() = default;
        PlayersMap(const PlayersMap&) = delete;
        PlayersMap& operator=(const PlayersMap&) = delete;

        std::unique_ptr<Factory>& operator[](const std::string &cardName);

    private:
        std::unordered_map<std::string, std::unique_ptr<Factory>> playersMap;
    };
}

#endif //EX4_PLAYERSFACTORY_H
