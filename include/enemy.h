#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"

class Enemy : public Creature
{
private:
    /* data */
public:
    Enemy();
    Enemy(short enemyHp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
    ~Enemy();
};


#endif