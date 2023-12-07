#include "player.h"

Player::Player(std::string n) : Creature(n)
{
}

Player::~Player()
{
}

void Player::charge()
{
    canAttack = true;
    this->setIsChargeFalse();
}

void Player::finishAttack()
{
    canAttack = false;
    this->setIsChargeTrue();
}

bool Player::getCanAttack() const
{
    return canAttack;
}
