#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"


class Enemy : public Creature
{
protected:
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

class firstEnemy : public Enemy
{
    private:
    public:
    Enemy(std::string n)
        : Creature(n)
    {};
    ~Enemy(){};
    friend class Battle; 
    void skill(){};
    void attack(){};  
}
#endif