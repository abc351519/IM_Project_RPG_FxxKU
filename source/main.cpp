#include "animation.h"
#include "graph.h"
#include "battle.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace dick{
    void init()
    {
        graph::init();
    }
};

int main()
{   
    dick::init();

    ani::curserShow(false);
    ani::clearScreen();
    
    Player p("HSIANG");
    Goblin e("Dick GOBU");
    Battle b(&p,&e);
    
    b.gameLoop();
    FLUSH;
 //   ani::loadWindow(ansi_color::background::RUNE_AQUA_STONE_DARK);

    SLEEP(1000000);

    return 0;
}