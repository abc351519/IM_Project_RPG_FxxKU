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
    
    Player p("Hsiang Dick");
    Goblin e("GOBU");
    Battle b(&p,&e);
    
    b.gameLoop();
    FLUSH;

    return 0;
}