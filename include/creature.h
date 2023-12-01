#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>

class Creature
{
private:
    std::string name; // name
    short hp; // health
    short lv; // level
    short att; // attack
    short def; // defend
    bool isCharge; // charge
public:
    Creature(); // constructor
    Creature(std::string n); // init name
    Creature(short enemyHp, short enemyLv, short enemyAtt, short enemyDef, bool enemyIsCharge);
    ~Creature(); // distructor
    void attackEnemy();
    void defend();
    void charge();
    void reverse();
};

#endif