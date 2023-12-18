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
    void normalAttackDamage(short damage); //根據對方的攻擊損失血量
    
};

#endif