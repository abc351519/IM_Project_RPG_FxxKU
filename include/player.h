#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "creature.h"

class Player : public Creature
{
private:
    bool canAttack = false;
public:
    Player(std::string n);
    ~Player();
    void finishAttack();
    void charge();
    bool getCanAttack() const;

};

#endif