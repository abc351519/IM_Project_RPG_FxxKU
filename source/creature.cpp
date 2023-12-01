#include "creature.h"
#include <iostream>
#include <string>
Creature::Creature()
{
    name = "Unknown player";
    hp = 100;
    lv = 0;
    att = 20;
    def = 10;
    isCharge = false;
}

Creature::Creature(std::string n)
{
    name = n;
    hp = 100;
    lv = 0;
    att = 20;
    def = 10;
    isCharge = false;
}

Creature::Creature(short Chp, short Clv, short Catt, short Cdef, bool CisCharge)
{
    hp = Chp;
    lv = Clv;
    att = Catt;
    def = Cdef;
    isCharge = CisCharge;
}

Creature::~Creature()
{

}

void Creature::attackEnemy()
{

}

void Creature::defend()
{

}
    
void Creature::charge()
{

}

void Creature::reverse()
{

}