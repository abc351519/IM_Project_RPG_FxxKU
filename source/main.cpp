// clang++ test.cpp "-I/opt/homebrew/Cellar/ncurses/6.4/include" "-L/opt/homebrew/Cellar/ncurses/6.4/lib" -lpanel -lncurses
//#include <ncurses.h>
#include "animation.h"
#include <iostream>
#include "enemy.h"
#include "player.h"

int main()
{   
    std::cout << "\033[0m";
    std::cout << "\n\n\n";
    std::cout << "   HP";
    ani::HMP_Loading(100, 1, "\033[41m");
    std::cout << '\n';
    std::cout << "   MP";
    ani::HMP_Loading(500, 0, "\033[44m");
    std::cin.ignore();
    ani::loadWindow("\033[48;5;177m");
    std::cin.ignore();
    return 0;
}