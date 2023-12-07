#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>
#include "enemy.h"
#include "player.h"


Enemy::Enemy(std::string n) : Creature(n)
{
}

Enemy::Enemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge) : Creature(enemyHp, enemyMp, enemyLv, enemyAtt, enemyDef, enemyIsCharge)
{
}

Enemy::~Enemy()
{
    
}

void Enemy::print() const
{
    std::cout << getName() << " " << getNowHp() << " " << getAtt() << " " << getDef() << " " << getIsAlive() << std::endl;
}

int Enemy::startAction()
{
    srand(time(NULL));
    std::random_device rd; // obtain a random seed from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 1); // define the range of values
    int random_num = distr(eng); // generate a random number
    if(random_num == 0)
        return EnemyAction::ENEMY_ATTACK;
    return EnemyAction::ENEMY_DEFEND;
}