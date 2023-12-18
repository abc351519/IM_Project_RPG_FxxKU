#include "creature.h"

void Creature::normalAttackDamage(short damage){
    nowHp -= damage*(def/(100+def));
}