#include "creature.h"

Creature::Creature(std::string n){
    name = n; // name
    maxHp = 100; // health
    nowHp = 100; 
    lv = 10; // level
    atk = 100; // attack
    def = 20; // defend
}

bool Creature::normalAttackDamageIsDead(short damage){
    nowHp -= static_cast<short>(static_cast<double>(damage)*(100.0/static_cast<double>(100+def)));
    if ( nowHp < 0 ) { //這是完完全全的死了
        nowHp = 0;
        return true;
    }
    return false;
}