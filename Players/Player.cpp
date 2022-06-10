#include "Player.h"
#include "utilities.h"

Player::Player(std::string playerName, Character someCharacter)
        : m_name(playerName), m_level(INITIAL_LEVEL), m_force(DEFAULT_FORCE), m_HP(HealthPoints()),
        m_coins(INITIAL_COINS_AMOUNT), m_character(someCharacter), m_rank(0)
{}

std::string Player::whatCharacter() const
{
    switch (m_character) {

        case Character::Wizard:
            return "Wizard";
        case Character::Rogue:
            return "Rogue";
        case Character::Fighter:
            return "Fighter";
    }
}

/*
void Player::printInfo() {
    const char *name = m_name.c_str();
    const char *job = m_name.c_str();
    printPlayerInfo(name, m_level, m_force, m_HP, m_coins);
}
*/

std::string Player::getName() const
{
    return m_name;
}

int Player::getCoins() const
{
    return m_coins;
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL) {
        ++m_level;
    }
}

int Player::getLevel()
{
    return m_level;
}

int Player::getHP() const
{
    return m_HP.getHP();
}

void Player::buff(int buffVal)
{
    if (buffVal < 0) {
        return;
    }
    m_force += buffVal;
}

void Player::heal(int hpAmount)
{
    if (hpAmount < 0) {
        return;
    }
    else if (hpAmount > m_HP.getMaxHP() - m_HP.getHP()) {
        m_HP = m_HP.getMaxHP();
    } else {
        m_HP += hpAmount;
    }
}

void Player::damage(int damageVal)
{
    if (damageVal < 0) {
        return;
    }else if(m_HP - damageVal < 0) {
        m_HP = 0;
    } else {
        m_HP -= damageVal;
    }
}

void Player::loseForce()
{
    if (m_force > 0) {
        --m_force;
    }
}

bool Player::isKnockedOut()
{
    if (m_HP.getHP()) {
        return false;
    } else {
        return true;
    }
}

void Player::addCoins(int amount)
{
    if (amount < 0) {
        return;
    }
    m_coins += amount;
}

bool Player::pay(int amount)
{
    if (amount <= 0) {
        return true;
    } else if (m_coins - amount < 0){
        return false;
    } else {
        m_coins -= amount;
        return true;
    }
}

int Player::getAttackStrength()
{
    return m_force + m_level;
}

std::ostream& operator<<(std::ostream& os, const Player& somePlayer)
{
    printPlayerDetails(os, somePlayer.m_name, somePlayer.whatCharacter(), somePlayer.m_level, somePlayer.m_force,
                       somePlayer.m_HP.getHP(), somePlayer.m_coins);
    return os;
}
