#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"

enum EnemyAction
{
    ENEMY_ATTACK,
    ENEMY_DEFEND,
    //ENEMY_ULT,
}; 

class Enemy : public Creature
{
private:
    /* data */
public:
    Enemy(std::string n);
    Enemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
    ~Enemy();
    int startAction();
    void print() const;
};


#endif