#include "creature.h"

Creature::Creature(std::string n){
    name = n; // name
    atkbuff = 0;
    defbuff = 0;
}

bool Creature::normalAttackDamageIsDead(short damage){
    nowHp -= static_cast<short>(static_cast<double>(damage)*(100.0/static_cast<double>(100+this->getDef())));
    if ( nowHp <= 0 ) { //這是完完全全的死了
        nowHp = 0;
        return true;
    }
    return false;
}

short Creature::getAtk()
{
    return atk + atkbuff;
}

short Creature::getDef()
{
    return def + defbuff;
}