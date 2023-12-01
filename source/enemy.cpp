#include <iostream>
#include <string>
#include "enemy.h"
#include "player.h"


Enemy::Enemy(std::string n) : Creature(n)
{
    
}

Enemy::Enemy(short enemyHp, short enemyMp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge) : Creature(enemyHp, enemyMp, enemyLv, enemyAtt, enemyDef, enemyIsCharge)
{
    
}

void Enemy::attackPlayer(Player& mainPlayer){
    mainPlayer.lossHp(this->getAtt());
}

Enemy::~Enemy()
{
    
}