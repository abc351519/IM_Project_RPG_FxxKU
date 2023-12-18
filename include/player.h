#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "creature.h"
#include "rune.h"

class Player : public Creature
{
private:
    RuneBag* myRunes;
    short lvThreshold[9];
    short exp;
    short runePoint;
public:
    Player(std::string n);
    ~Player();
    friend class Event;
    void startGameValueSet();
    bool refreshExp(short enemyLv); //return if level up
    void sellToGetRunePoints(short gainPoints);
    void endBattle();
};

#endif