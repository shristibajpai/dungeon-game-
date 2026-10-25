
#include "Player.h"
#include <iostream>
using namespace std;

// Constructor
Player::Player(string playerName) {
    name = playerName;
    health = 100;
    attackPower = 15;
}

// Display player details
void Player::showStats() {
    cout << "\n--- Player Stats ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
}

// Attack the enemy
void Player::attackEnemy(int& enemyHealth) {
    cout << name << " attacks the enemy!" << endl;

    enemyHealth = enemyHealth - attackPower;

    if (enemyHealth < 0) {
        enemyHealth = 0;
    }

    cout << "Enemy health: " << enemyHealth << endl;
}

// Receive damage from an enemy
void Player::takeDamage(int damage) {
    health = health - damage;

    if (health < 0) {
        health = 0;
    }

    cout << name << "'s health: " << health << endl;
}

// Getter functions
string Player::getName() {
    return name;
}

int Player::getHealth() {
    return health;
}

int Player::getAttackPower() {
    return attackPower;
}
