#include "player.h"

Player::Player(std::string n) : Creature(n)
{
    myRunes = new RuneBag();
    lvThreshold[9] = {100, 150, 200, 275, 350, 425, 550, 675, 800};
}

Player::~Player()
{
    delete myRunes;
}

bool Player::refreshExp(short enemyLv){
    if(lv == 10)
        return false;
    short rate = 20;
    exp += enemyLv * rate;
    if(exp >= lvThreshold[lv - 1]){
        exp -= lvThreshold[lv - 1];
        lv++;
        return true; // level up
    }
    return false;
}