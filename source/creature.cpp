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
    if ( atkbuff + atk < 0 ) {
        return 0;
    }
    return atk + atkbuff;
}

short Creature::getDef()
{
    if ( def + defbuff < 0 ) {
        return 0;
    }
    return def + defbuff;
}

void Creature::heal(double rate)
{
    nowHp += static_cast<short>(static_cast<double>(maxHp)*rate);
    if ( nowHp > maxHp ) {
        nowHp = maxHp;
    }
    return;
}