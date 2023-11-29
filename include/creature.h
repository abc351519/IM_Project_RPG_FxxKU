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
public:
    Creature(); // constructor
    Creature(std::string n); // init name
    ~Creature(); // distructor
};

#endif