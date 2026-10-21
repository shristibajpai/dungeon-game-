
#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "BattleSystem.h"

using namespace std;

int main() {
    cout << "========================" << endl;
    cout << "    DUNGEON ADVENTURE   " << endl;
    cout << "========================" << endl;

    string playerName;

    cout << "\nEnter your adventurer name: ";
    cin >> playerName;

    // Create objects
    Player player1(playerName);
    Enemy enemy1("Austin", 60, 15);

    // Start the battle
    BattleSystem battle;
    battle.startBattle(player1, enemy1);

    return 0;
}
