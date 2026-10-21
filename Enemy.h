
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

class Enemy {
private:
    string name;
    int health;
    int attackPower;

public:
    // Constructor
    Enemy(string enemyName, int enemyHealth, int enemyAttackPower);

    // Display enemy information
    void showStats();

    // Battle functions
    void takeDamage(int damage);
    void attackPlayer(int& playerHealth);

    // Getter functions
    string getName();
    int getHealth();
    int getAttackPower();
};

#endif
