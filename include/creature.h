#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>

class Creature
{
private:
    std::string name; // name
    short maxHp; // health
    short nowHp;
    short maxMp; // magic
    short nowMp;
    short lv; // level
    short att; // attack
    short def; // defend
    bool isCharge; // charge
    short areaLevel;
public:
    Creature(); // constructor
    Creature(std::string n); // init name
    Creature(short Chp, short Cmp, short Clv, short Catt, short Cdef, bool CisCharge); // copy
    ~Creature(); // distructor
    void lossHp(short lossHpAmount);
    void lossMp(short lossMpAmount);
    void restoreMp();
    void defend();
    void charge();
    void returnDamage();
    //void changeArea(short areaNum);
    std::string getName();
    int getAtt();
    int getDef();
    bool getIsCharge();
    short getAreaLevel();

};

#endif