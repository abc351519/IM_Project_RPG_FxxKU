#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"

class Enemy : public Creature
{
private:
    short coolDown;
    short skillPoint;
public:
    Enemy(){};
    ~Enemy();
    friend class Event;
    virtual void skill() = 0; //敵人的技能
    virtual void attack() = 0; //一般攻擊模式
};


#endif