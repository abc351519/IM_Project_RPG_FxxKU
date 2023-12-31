#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
#include "rune.h"

namespace creature{
    const short creatureHpByLv[11] = {0,100,200,330,500,700,900,1120,1400,1710,2000};
    const short creatureAtkByLv[11] = {0,25,50,75,100,125,150,175,200,225,250};
    const short creatureDefByLv[11] = {0,10,12,15,20,25,30,40,50,60,75};
};

class Event;
class Battle;

class Creature
{
protected:
    RuneEffect effect = RuneEffect::USELESS;
    std::string name; // name
    short maxHp; // health
    short nowHp; 
    short lv; // level
    short atk; // attack
    short def; // defend
    short atkbuff;
    short defbuff;

public:
    Creature(){};
    Creature(std::string n); // constructor
    ~Creature(){}; // distructor
    bool normalAttackDamageIsDead(short damage); //根據對方的攻擊損失血量  
    void heal(double rate);
    short getDef();
    short getAtk();
};

#endif