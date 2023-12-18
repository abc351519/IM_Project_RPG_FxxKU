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
    Enemy(std::string n)
        : Creature(n)
    {};
    ~Enemy(){};
    friend class Battle;
    virtual void skill() = 0; //敵人的技能
    virtual void attack() = 0; //一般攻擊模式
};


#endif