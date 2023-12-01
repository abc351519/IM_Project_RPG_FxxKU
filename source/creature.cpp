#include "creature.h"
#include <iostream>
#include <string>
Creature::Creature()
{
    name = "Unknown player";
    maxHp = 100;
    nowHp = 100;
    maxMp = 100;
    nowMp = 100;
    lv = 0;
    att = 20;
    def = 10;
    isCharge = false;
    areaLevel = 0;
}

Creature::Creature(std::string n)
{
    name = n;
    maxHp = 100;
    nowHp = 100;
    maxMp = 100;
    nowMp = 100;
    lv = 0;
    att = 20;
    def = 10;
    isCharge = false;
    areaLevel = 0;
}

Creature::Creature(short Chp, short Cmp, short Clv, short Catt, short Cdef, bool CisCharge)
{
    maxHp = Chp;
    nowHp = Chp;
    maxMp = Cmp;
    nowMp = Cmp;
    lv = Clv;
    att = Catt;
    def = Cdef;
    isCharge = CisCharge;
}

Creature::~Creature()
{

}
void Creature::lossHp(short lossHpAmount){
    nowHp -= lossHpAmount;
}
void Creature::lossMp(short lossMpAmount){
    nowMp -= lossMpAmount;
}

void Creature::restoreMp(){
    nowMp += (maxMp / 10);
}

void Creature::defend()
{

}
    
void Creature::charge()
{

}

void Creature::returnDamage()
{

}
std::string Creature::getName()
{
    return name;
}

int Creature::getAtt()
{
    return att;
}

int Creature::getDef()
{
    return def;
}

bool Creature::getIsCharge()
{
    return isCharge;
}

short Creature::getAreaLevel()
{
    return areaLevel;
}