
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    int health;
    int attackPower;

public:
    // Constructor
    Player(string playerName);

    // Display player details
    void showStats();

    // Attack the enemy
    void attackEnemy(int& enemyHealth);

    // Enemy attacks the player
    void takeDamage(int damage);

    // Get player information
    string getName();
    int getHealth();
    int getAttackPower();
};

#endif
