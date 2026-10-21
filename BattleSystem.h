
#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Player.h"
#include "Enemy.h"

class BattleSystem {
public:
    void startBattle(Player& player, Enemy& enemy);
};

#endif
