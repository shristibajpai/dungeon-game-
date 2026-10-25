#include "BattleSystem.h"
#include <chrono>
#include <iostream>
#include <random>
using namespace std;

void BattleSystem::startBattle(Player& player, Enemy& enemy) {
    cout << "\n========== BATTLE START ==========" << endl;

    random_device randomSource;
    seed_seq seed{
        randomSource(),
        randomSource(),
        static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count())
    };
    mt19937 rng(seed);
    auto rollDamage = [&rng](int attackPower, int maxMultiplier) {
        return uniform_int_distribution<int>(0, attackPower * maxMultiplier)(rng);
    };

    // Show both characters' stats
    player.showStats();
    enemy.showStats();

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {

        // Player's turn
        cout << "\n--- Player's Turn ---" << endl;

        cout << player.getName() << " attacks "
             << enemy.getName() << "!" << endl;

        int playerDamage = rollDamage(player.getAttackPower(), 2);
        cout << player.getName() << " deals " << playerDamage
             << " damage." << endl;
        enemy.takeDamage(playerDamage);

        cout << enemy.getName() << "'s remaining health: "
             << enemy.getHealth() << endl;

        if (enemy.getHealth() == 0) {
            cout << "\n" << enemy.getName()
                 << " has been defeated!" << endl;
            break;
        }

        // Enemy's turn
        cout << "\n--- Enemy's Turn ---" << endl;

        cout << enemy.getName() << " attacks "
             << player.getName() << "!" << endl;

        int enemyDamage = rollDamage(enemy.getAttackPower(), 2);
        cout << enemy.getName() << " deals " << enemyDamage
             << " damage." << endl;
        player.takeDamage(enemyDamage);

        cout << player.getName() << "'s remaining health: "
             << player.getHealth() << endl;

        if (player.getHealth() == 0) {
            cout << "\n" << player.getName()
                 << " has been defeated!" << endl;
            break;
        }
    }

    cout << "\n========== BATTLE RESULT ==========" << endl;

    if (player.getHealth() > 0) {
        cout << "Congratulations, " << player.getName()
             << "! You won!" << endl;
    } else {
        cout << "Game Over! Better luck next time." << endl;
    }
}
