
#include "Enemy.h"
#include <iostream>
using namespace std;

// Constructor
Enemy::Enemy(string enemyName, int enemyHealth, int enemyAttackPower) {
    name = enemyName;
    health = enemyHealth;
    attackPower = enemyAttackPower;
}

// Display enemy stats
void Enemy::showStats() {
    cout << "\n--- Enemy Stats ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
}

// Reduce enemy health
void Enemy::takeDamage(int damage) {
    health -= damage;

    if (health < 0) {
        health = 0;
    }
}

// Enemy attacks player
void Enemy::attackPlayer(int& playerHealth) {
    cout << name << " attacks the player!" << endl;

    playerHealth -= attackPower;

    if (playerHealth < 0) {
        playerHealth = 0;
    }
}

// Getters
string Enemy::getName() {
    return name;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getAttackPower() {
    return attackPower;
}
