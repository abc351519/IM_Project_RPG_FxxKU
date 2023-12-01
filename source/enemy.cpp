#include <iostream>
#include "enemy.h"


Enemy::Enemy() : Creature()
{
    
}

Enemy::Enemy(short enemyHp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge) : Creature(enemyHp, enemyLv, enemyAtt, enemyDef, enemyIsCharge)
{
    
}


Enemy::~Enemy()
{
    
}