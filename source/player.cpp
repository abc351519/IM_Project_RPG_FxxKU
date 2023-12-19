#include "player.h"

Player::Player(std::string n) : Creature(n)
{
    myRunes = nullptr;
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
}

void Player::startGameValueSet(){
    runePoint = INIT_RUNEPOINTS;
    nowHp = maxHp;
    myRunes = new RuneBag();
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

void Player::sellToGetRunePoints(short gainPoints){ runePoint += gainPoints; }

void Player::endBattle(){
    delete myRunes;
    myRunes = nullptr;
}