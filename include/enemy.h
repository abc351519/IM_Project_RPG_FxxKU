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

enum class Skill{

};

class Enemy : public Creature
{
protected:
    short coolDown;
    short skillPoint;
    std::string skillName;
    EnemyElement element;
public:
    Enemy(std::string n)
        : Creature(n)
    {};
    ~Enemy(){};
    friend class Battle;
    std::string getSkillName();
    virtual short skill() = 0; //敵人的技能
    virtual short attack() = 0; //一般攻擊模式
};

class Goblin : public Enemy
{
    private:
    public:
    Goblin(std::string n);
    ~Goblin();
    friend class Battle; 
    short skill() override;
    short attack() override;
};
#endif