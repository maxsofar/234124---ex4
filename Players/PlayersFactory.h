#ifndef EX4_PLAYERSFACTORY_H
#define EX4_PLAYERSFACTORY_H

#include "Player.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"
#include <string>
#include <unordered_map>
#include <memory>

class pFactory {
public:
    virtual std::unique_ptr<Player> createInstance(std::string playerName) = 0;
};

template <class PlayerType>
class PlayerFactory : public pFactory {
public:
    std::unique_ptr<Player> createInstance(std::string playerName) override;
};

template <class PlayerType>
std::unique_ptr<Player> PlayerFactory<PlayerType>::createInstance(std::string playerName)
{
    std::unique_ptr<Player> ptr = std::unique_ptr<Player>(new PlayerType(playerName));
    return ptr;
}

#endif //EX4_PLAYERSFACTORY_H