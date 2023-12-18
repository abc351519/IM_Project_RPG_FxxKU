#include "animation.h"
//#include "enemy.h"
//#include "player.h"
#include "graph.h"
#include "battle.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace dick{
    void init()
    {
        graph::init();
        srand(time(nullptr));
    }
};

int main()
{   
    dick::init();
    
    ani::curserShow(false);
    ani::clearScreen();
    
    Player p("uwhefuhehfugo");
    FirstEnemy e("aihsfhif");
    Battle b(&p,&e);
    
    b.init();
    FLUSH;
 //   ani::loadWindow(ansi_color::background::RUNE_AQUA_STONE_DARK);

    SLEEP(1000000);

    return 0;
}