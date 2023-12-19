#include "player.h"

Player::Player(std::string n)
{
    name = n;
    lv = 1;
    atk = creature::creatureAtkByLv[lv];
    def = creature::creatureDefByLv[lv];
    maxHp = creature::creatureHpByLv[lv];
    myRunes = nullptr;
}

Player::~Player()
{}

void Player::startGameValueSet(){
    runePoint = INIT_RUNEPOINTS;
    nowHp = maxHp;
    myRunes = new RuneBag();
}

void Player::refreshRoundly()
{
    myRunes->runeGet(); //增加符文
    runePoint += RUNEPOINT_GET_ROUNDLY; //增加點數
    return;
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