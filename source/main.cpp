#include "animation.h"
#include "enemy.h"
#include "player.h"
#include "battle.h"
#include <iostream>


int main()
{   
    Player player1("noob");
    Enemy mob("goblin");
    Battle begin(&player1, &mob);
    begin.gameLoop();
    return 0;
}