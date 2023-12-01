#ifndef AREA_H
#define AREA_H
#include <iostream>
#include "enemy.h"

class Area
{
private:
    short enemyCnt;
    Enemy** enemyGroup;
public:
    Area();
    ~Area();
    void createEnemy(short enemyHp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
};


#endif