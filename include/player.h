#ifndef PLAYER_H
#define PLAYER_H

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