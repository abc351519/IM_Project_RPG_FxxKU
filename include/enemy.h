#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"


enum class EnemyElement{
    AQUA,
    FLAME,
    VITALITY
};

class Enemy : public Creature
{
protected:
    short coolDown;
    short skillPoint;
    EnemyElement element;
public:
    Enemy(std::string n)
        : Creature(n)
    {};
    ~Enemy(){};
    friend class Battle;
    virtual void skill() = 0; //敵人的技能
    virtual void attack() = 0; //一般攻擊模式
};

class FirstEnemy : public Enemy
{
    private:
    public:
    FirstEnemy(std::string n)
        : Enemy(n)
    {
        element = EnemyElement::AQUA;
    };
    ~FirstEnemy(){};
    friend class Battle; 
    void skill(){};
    void attack(){};  
};
#endif