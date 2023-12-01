#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"

class Enemy : public Creature
{
private:
    /* data */
public:
    Enemy(std::string n);
    Enemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
    ~Enemy();
    void attackPlayer(Player& mainPlayer);
};


#endif