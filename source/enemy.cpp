#include "enemy.h"
#include <iostream>

std::string Enemy::getSkillName()
{
    return skillName;
}

Goblin::Goblin(std::string n)
    : Enemy(n)
{
    coolDown = 3;
    skillPoint = 0;
    lv = 1;
    maxHp = creature::creatureHpByLv[lv];
    element = EnemyElement::VITALITY;
}


Goblin::~Goblin(){}

short Goblin::skill()
{
    skillPoint = 0;
    return 2*atk;
}


short Goblin::attack()
{
    if ( skillPoint >= coolDown ) {
        return skill();
    }
    skillPoint++;
    return atk;
}