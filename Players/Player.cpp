#include "Player.h"
#include <utility>
#include "../utilities.h"

Player::Player(const std::string& playerName, Character someCharacter)
        : m_name(playerName), m_level(INITIAL_LEVEL), m_force(DEFAULT_FORCE), m_HP(HealthPoints()),
        m_coins(INITIAL_COINS_AMOUNT), m_character(someCharacter)
{}

std::string Player::getCharacter() const
{
    switch (m_character) {

        case Character::Wizard:
            return "Wizard";
        case Character::Rogue:
            return "Rogue";
        case Character::Fighter:
            return "Fighter";
        default:
            return " ";
    }
}

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

void Player::loseForce()
{
    if (m_force > 0) {
        --m_force;
    }
}

void Player::buff(int buffVal)
{
    if (buffVal < 0) {
        return;
    }
    m_force += buffVal;
}

int Player::getLevel() const
{
    return m_level;
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

bool Player::isKnockedOut() const
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
    printPlayerDetails(os, somePlayer.m_name, somePlayer.getCharacter(), somePlayer.m_level, somePlayer.m_force,
                       somePlayer.m_HP.getHP(), somePlayer.m_coins);
    return os;
}
