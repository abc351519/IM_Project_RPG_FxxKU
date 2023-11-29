#include "animation.h"
#include <iostream>
#include "def.h"
#include <ctime>
//#include <thread>
//#include <chrono>

const int HMP_run_time = 750000;

void ani::HMP_Loading(const short maxHMP, const short nowHMP, const char* color)
{
    short amountPerChar = maxHMP/Global::maxHMPSize;
    short howManyChar = nowHMP/amountPerChar;
    for ( short i = 0; i < howManyChar; i++ )
    {
        std::cout << color  << ' ';
        fflush(stdout);
        delay(HMP_run_time/howManyChar);
    }
    
    std::cout << "\033[0m";
    /*
    
    std::cout << "\x1b[2J";
    std::cout << "\x1b[H";
    for ( int j = 0; j < 100; j++ )
    {
        std::cout << '\n';
        std::cout << j;
        sleep(1);
        std::cout << "\x1b[H";
    }*/
    return;
}

void ani::delay(int ms)
{   
    clock_t delayTime = static_cast<clock_t> (ms);
    clock_t initTime = clock();
    //單位10秒
    while ( true )
    {
        if ( clock() - initTime >= delayTime ) {
            break;
        }
    }
    return;
}