#include "animation.h"
#include "graph.h"
#include "battle.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace dick{
    void init(Player*& p)
    {
        graph::init();
        EVENT::init(p);
    }
};

int main()
{   
    Player* p;
    dick::init(p);

    ani::curserShow(false);
    ani::clearScreen();
    
    


    Goblin e("GOBU");
    Battle b(p,&e);
    
    b.gameLoop();
    FLUSH;

    return 0;
}