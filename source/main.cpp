#include "animation.h"
//#include "enemy.h"
//#include "player.h"
#include "graph.h"
#include "battle.h"

#include <iostream>
#include <thread>
#include <chrono>

int main()
{   
    // Player player1("noob");
    // Enemy mob("goblin");
    // Battle begin(&player1, &mob);
    // begin.gameLoop();
    
    // Position a(7,4);
    // Position b(5,8);

    // std::thread t1(ani::loadWindow,ansi_color::background::RUNE_AQUA_STONE);
    // std::thread t2(ani::drawLine,a,10,CurserMove::MOVERIGHT,50);
    
    ani::clearScreen();
    
    // std::thread t3(ani::drawRectangle,b,10,6,1000);

    // t1.join();
    // t2.join();
    // t3.join();

    //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    // while (t1.joinable() || t2.joinable()) {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    // }
    
    Position c(40,15);
    graph::init();   
    ani::setPos(c);
    
    ani::renderGrapgh(c,BATTLE::ICON::RUNE_AQUA_ICON);

    c.x += 6;
    ani::renderGrapgh(c,BATTLE::ICON::RUNE_FLAME_ICON);
    
    
    
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000000000));
    return 0;
}