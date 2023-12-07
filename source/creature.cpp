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
    isAlive = true;
    canDefend = true;
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
    isAlive = true;
    canDefend = true;
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
    isAlive = true;
    canDefend = true;
}

Creature::~Creature()
{

}

void Creature::lossHp(short lossHpAmount){
    nowHp -= lossHpAmount;
    if(nowHp <= 0)
        isAlive = false;
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

void Creature::returnDamage()
{

}

void Creature::defendFail(){
    canDefend = false;
}

void Creature::setIsChargeTrue()
{
    isCharge = true;
}

void Creature::setIsChargeFalse()
{
    isCharge = false;
}

std::string Creature::getName() const
{
    return name;
}

int Creature::getNowHp() const
{
    return nowHp;
}

int Creature::getNowMp() const
{
    return nowMp;
}

int Creature::getAtt() const
{
    return att;
}

int Creature::getDef() const
{
    return def;
}

bool Creature::getIsCharge() const
{
    return isCharge;
}

short Creature::getAreaLevel() const
{
    return areaLevel;
}

bool Creature::getIsAlive() const
{
    return isAlive;
}

bool Creature::getCanDefend() const
{
    return canDefend;
}