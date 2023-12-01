#include <iostream>
#include "area.h"
#include "enemy.h"

Area::Area()
{
    enemyCnt = 0;
    enemyGroup = new Enemy*[5];
}

Area::~Area()
{
    for(int i = 0; i < 5; i++)
        delete enemyGroup[i];
    delete[] enemyGroup;
    enemyGroup = nullptr;
}

void Area::createEnemy(short enemyHp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge){
    enemyGroup[enemyCnt] = new Enemy(enemyHp, enemyLv, enemyAtt, enemyDef, enemyIsCharge);
    enemyCnt++;
}