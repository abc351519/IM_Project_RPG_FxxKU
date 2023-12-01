#ifndef AREA_H
#define AREA_H
#include <iostream>
#include "enemy.h"
#include <string>

class Area
{
private:
    std::string areaName;
    short enemyCnt;
    Enemy** enemyGroup;
public:
    Area(std::string n);
    ~Area();
    void createEnemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
};


#endif