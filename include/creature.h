#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>

enum class Element //屬性
{
    FLAME, //火
    AQUA, //水
    VITALITY, //木
    NONE //無屬
};

namespace creature{
    const short creatureHpByLv[11] = {0,100,200,330,500,700,900,1120,1400,1710,2000};
    const short creatureAtkByLv[11] = {0,50,100,150,200,250,300,350,400,450,500};
    const short creatureDefByLv[11] = {0,10,12,15,20,25,30,40,50,60,75};
};

class Event;
class Battle;

class Creature
{
protected:
    std::string name; // name
    short maxHp; // health
    short nowHp; 
    short lv; // level
    short atk; // attack
    short def; // defend
public:
    Creature(std::string n); // constructor
    ~Creature(){}; // distructor
    bool normalAttackDamageIsDead(short damage); //根據對方的攻擊損失血量  
};

#endif