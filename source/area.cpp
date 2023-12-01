#include <iostream>
#include <string>
#include "area.h"
#include "enemy.h"


Area::Area(std::string n)
{
    areaName = n;
    enemyCnt = 0;
    enemyGroup = new Enemy*[3];
}

Area::~Area()
{
    for(int i = 0; i < 3; i++)
        delete enemyGroup[i];
    delete[] enemyGroup;
    enemyGroup = nullptr;
}

void Area::createEnemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge){
    enemyGroup[enemyCnt] = new Enemy(enemyHp, enemyMp, enemyLv, enemyAtt, enemyDef, enemyIsCharge);
    enemyCnt++;
}