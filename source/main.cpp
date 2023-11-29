// clang++ test.cpp "-I/opt/homebrew/Cellar/ncurses/6.4/include" "-L/opt/homebrew/Cellar/ncurses/6.4/lib" -lpanel -lncurses
//#include <ncurses.h>
//#include "def.h"
#include "hello.h"
#include <iostream>
#include <string>
int main()
{   
    std::string player_name;
    std::cin >> player_name;
    std::cout << player_name;
    return 0;
}