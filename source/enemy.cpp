#include "def.h"
#include "enemy.h"
#include <iostream>

std::string Enemy::getSkillName()
{
    return skillName;
}

bool Enemy::normalAttackDamageIsDead(short damage)
{
    return Creature::normalAttackDamageIsDead(damage);
}

Goblin::Goblin(std::string n)
    : Enemy(n)
{
    coolDown = 3;
    skillPoint = 0;
    lv = 1;
    maxHp = creature::creatureHpByLv[lv];
    nowHp = maxHp;
    def = creature::creatureDefByLv[lv];
    atk = creature::creatureAtkByLv[lv];
    element = EnemyElement::VITALITY;
}


Goblin::~Goblin(){}

short Goblin::skill(Skill& skill)
{
    skill = Skill::DOUBLE_CRITICAL;
    skillPoint = 0;
    return 2*atk;
}



short Goblin::attack(Skill& skil)
{
    
    if ( skillPoint >= coolDown ) {
        return skill(skil);
    }
    skil = Skill::NORMAL;
    skillPoint++;
    short odd = odds::rand()%100;
    double rate = 1.0;
    //一般60%
    if ( odd < 75 && odd >= 60 ) { //15%
        rate = 1.25;
    } else if ( odd >= 75 && odd < 90 ) { //15%
        rate = 0.8;
    } else if ( odd >=90 ) { //10%
        rate = 1.5;
    }
    return static_cast<short>(static_cast<double>(atk)*rate);
}