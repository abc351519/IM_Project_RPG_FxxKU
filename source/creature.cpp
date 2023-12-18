#include "creature.h"

Creature::Creature(std::string n){
    name = n; // name
    maxHp = 100; // health
    nowHp = 100; 
    lv = 10; // level
    atk = 100; // attack
    def = 20; // defend
}

void Creature::normalAttackDamage(short damage){
    nowHp -= damage*(def/(100+def));
}