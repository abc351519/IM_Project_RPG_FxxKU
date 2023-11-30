#include "animation.h"
#include <iostream>
#include "def.h"
#include <ctime>
#include <thread>
#include <chrono>
const int HMP_run_time = 750;

void ani::HMP_Loading(const short maxHMP, const short nowHMP, const char* color)
{
    short amountPerChar = maxHMP/Global::maxHMPSize;
    short howManyChar = nowHMP/amountPerChar;
    for ( short i = 0; i < howManyChar; i++ )
    {
        std::cout << color  << ' ';
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(HMP_run_time/howManyChar));
    }
    
    std::cout << "\033[0m";
    
    return;
}