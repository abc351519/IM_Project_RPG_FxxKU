// clang++ test.cpp "-I/opt/homebrew/Cellar/ncurses/6.4/include" "-L/opt/homebrew/Cellar/ncurses/6.4/lib" -lpanel -lncurses
//#include <ncurses.h>
#include "animation.h"
#include <iostream>
#include "enemy.h"
#include "player.h"

int main()
{   
    std::cout << "\n\n\n";
    std::cout << "   HP";
    ani::HMP_Loading(100, 100, "\033[41m");
    std::cout << '\n';
    std::cout << "   MP";
    ani::HMP_Loading(500, 269, "\033[44m");
    return 0;
}