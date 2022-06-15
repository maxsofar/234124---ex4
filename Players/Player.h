#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include "HealthPoints.h"

enum class Character{Wizard, Rogue, Fighter};

class Player {
public:

    /*
     * Returns the name of the player's character
     *
     * @return
     *      String with name of a character
     */
    std::string getCharacter() const;

    /*
     * Returns the name of the player
     *
     * @return
     *      String with name of a player
     */
    std::string getName() const;

    /*
     * Returns the amount of player's coins
     *
     * @return
     *      Amount of coins
     */
    int getCoins() const;

    /*
     * Promotes the player one level
     *
     * @return
     *      void
     */
    void levelUp();

    /*
     * Decreases player's m_force one point
     *
     * @return
     *      void
     */
    void loseForce();

    /*
     * Increase the player's m_force by given number of points
     * @param buffVal the number of points to be added
     *
     * @return
     *      void
     */
    void buff(int buffVal);

    /*
     * Get the player's current level:
     *
     * @return
     *      the current level of the player
     */
    int getLevel() const;

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
    bool isKnockedOut() const;

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
     *      the sum of m_force points and player's level
     */
    virtual int getAttackStrength();

    /*
     * Default D'tor
     */
    virtual ~Player() = default;

protected:
    /*
     * C'tor of the player:
     *
     * @param playerName    - The name of the player.
     * @param someCharacter - Enum representation of one's of the game characters.
     * @return
     *      An instance of Player
     */
    Player(const std::string& playerName, Character someCharacter);

    /*
     * copy C'tor, assignment operator overload
     */

    Player(const Player &) = default;

    Player &operator=(const Player &) = default;

    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_HP;
    int m_coins;
    Character m_character;

private:
    static const int DEFAULT_FORCE = 5;
    static const int INITIAL_LEVEL = 1;
    static const int MAX_LEVEL = 10;
    static const int INITIAL_COINS_AMOUNT = 10;

    friend std::ostream& operator<<(std::ostream& os, const Player& somePlayer);
};
#endif //EX4_PLAYER_H
