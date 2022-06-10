#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include "HealthPoints.h"

enum class Character{Wizard, Rogue, Fighter};

class Player {
public:
    /*
     * C'tor of the player:
     *
     * @param playerName   - The name of the player.
     * @param initialForce - Initial force value of the player.
     * @param maxHP        - The maximum value of HP for the player.
     * @result
     *      An instance of Player
     */
    Player(std::string playerName, Character someCharacter);

    /*
     * Default D'tor, copy C'tor, assignment operator overload
     */
    virtual ~Player() = default;

    Player(const Player &) = default;

    Player &operator=(const Player &) = default;

    std::string whatCharacter() const;

    std::string getName() const;

    int getCoins() const;

    int getHP() const;

    /*
     * Print the following player parameters:
     *  - Name
     *  - Level
     *  - Force
     *  - HP
     *  - Coins
     *
     * @return
     *      void
     */
    void printInfo();

    /*
     * Promote the player one level
     *
     * @return
     *      void
     */
    void levelUp();

    void loseForce();

    /*
     * Get the player's current level:
     *
     * @return
     *      the current level of the player
     */
    int getLevel();

    /*
     * Increase the player's force by given number of points
     * @param buffVal the number of points to be added
     *
     * @return
     *      void
     */
    void buff(int buffVal);

    /*
     * Increase the player's HP by given number of points with the limit of maxHP
     * @param hpAmount the number of points to be added
     *
     * @return
     *      void
     */
    virtual void heal(int hpAmount);

    /*
     * Decrease the player's HP by given number of points, with bottom limit 0
     * @param damageVal the number of points to be subtracted
     *
     * @return
     *      void
     */
    void damage(int damageVal);

    /*
     * Check if player is knocked out - HP is 0
     *
     * @return
     *      True if player's HP amount is 0
     *      False otherwise
     */
    bool isKnockedOut();

    /*
     * Increase the amount of player's coins by given number
     * @param amount - number of coins to be added
     *
     * @return
     *      void
     */
    virtual void addCoins(int amount);

    /*
     * Decrease the amount of player's coins by given number
     * @param amount - number of coins to be subtracted
     *
     * @return
     *      True if the player has enough coins
     *      False otherwise
     */
    bool pay(int amount);

    /*
     * Get the attack strength of the player
     *
     * @return
     *      the sum of force points and player's level
     */
    virtual int getAttackStrength();

protected:
    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_HP;
    int m_coins;
    Character m_character;
    int m_rank;

private:
    static const int DEFAULT_FORCE = 5;
    static const int INITIAL_LEVEL = 1;
    static const int MAX_LEVEL = 10;
    static const int INITIAL_COINS_AMOUNT = 10;
    int m_maxHP; //TODO: Check if needed

    friend std::ostream& operator<<(std::ostream& os, const Player& somePlayer);
};
#endif //EX4_PLAYER_H
