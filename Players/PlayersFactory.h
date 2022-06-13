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
    virtual Player* createInstance(std::string playerName) = 0;
};

template <class PlayerType>
class PlayerFactory : public pFactory {
public:
    Player* createInstance(std::string playerName) override;
};

template <class PlayerType>
Player* PlayerFactory<PlayerType>::createInstance(std::string playerName)
{
    return new PlayerType(playerName);
}

static void playerFactoryMapper(std::unordered_map<std::string, pFactory*>& factoryMap)
{
    factoryMap["Fighter"] = new PlayerFactory<Fighter>();
    factoryMap["Rogue"] = new PlayerFactory<Rogue>();
    factoryMap["Wizard"] = new PlayerFactory<Wizard>();
}
#endif //EX4_PLAYERSFACTORY_H
