#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "creature.h"
#include "rune.h"

const short lvThreshold[9] = {100,150,200,275,350,425,550,675,800};

class Player : public Creature
{
private:
    RuneBag* myRunes;
    
    short exp;
    short runePoint;
public:
    Player(std::string n);
    ~Player();
    friend class Battle;
    void startGameValueSet();
    void refreshRoundly();
    bool refreshExp(short enemyLv); //return if level up
    void sellToGetRunePoints(short gainPoints);
    void endBattle();
};

#endif