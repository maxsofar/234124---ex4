#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"


class Rogue : public Player {
public:
    Rogue(std::string playerName);
    ~Rogue() = default;
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue&) = default;
    void addCoins(int amount) override;


private:
};

#endif //EX4_ROGUE_H
