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
    bool isAlive;
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
    std::string getName() const;
    int getNowHp() const;
    int getNowMp() const;
    int getAtt() const;
    int getDef() const;
    bool getIsCharge() const;
    short getAreaLevel() const;
    bool getIsAlive() const;
};

#endif