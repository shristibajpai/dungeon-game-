
#include "BattleSystem.h"
#include <iostream>
using namespace std;

void BattleSystem::startBattle(Player& player, Enemy& enemy) {
    cout << "\n========== BATTLE START ==========" << endl;

    // Show both characters' stats
    player.showStats();
    enemy.showStats();

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {

        // Player's turn
        cout << "\n--- Player's Turn ---" << endl;

        cout << player.getName() << " attacks "
             << enemy.getName() << "!" << endl;

        enemy.takeDamage(player.getAttackPower());

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

        player.takeDamage(enemy.getAttackPower());

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
