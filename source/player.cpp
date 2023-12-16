#include "player.h"

Player::Player(std::string n) : Creature(n)
{
    myRunes = new RuneBag();
    lvThreshold[0] = 100;
    lvThreshold[1] = 150;
    lvThreshold[2] = 200;
    lvThreshold[3] = 275;
    lvThreshold[4] = 350;
    lvThreshold[5] = 425;
    lvThreshold[6] = 550;
    lvThreshold[7] = 675;
    lvThreshold[8] = 800;
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