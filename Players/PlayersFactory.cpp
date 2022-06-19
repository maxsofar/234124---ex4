#include "PlayersFactory.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"

using namespace PlayersFactory;
using std::unique_ptr;

PlayersMap::PlayersMap()
{
    playersMap["Fighter"] = unique_ptr<PlayerFactory<Fighter>>(new PlayerFactory<Fighter>());
    playersMap["Rogue"] = unique_ptr<PlayerFactory<Rogue>>(new PlayerFactory<Rogue>());
    playersMap["Wizard"] = unique_ptr<PlayerFactory<Wizard>>(new PlayerFactory<Wizard>());
}

unique_ptr<Factory>& PlayersMap::operator[](const std::string &playerClass)
{
    return playersMap[playerClass];
}