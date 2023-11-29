#include "creature.h"
#include <iostream>
#include <string>
Creature::Creature()
{
    name = "Unknown player";
    hp = 100;
    lv = 0;
}

Creature::Creature(std::string n)
{
    name = n;
    hp = 100;
    lv = 0;
}

Creature::~Creature()
{

}