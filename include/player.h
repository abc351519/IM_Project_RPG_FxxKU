#ifndef PLAYER_H
#define PLATER_H
#include <iostream>
#include <string>
#include "creature.h"

class Player : public Creature
{
private:
    /* data */
public:
    Player(std::string n);
    ~Player();
};

#endif