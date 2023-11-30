#include "animation.h"
#include <iostream>
#include "def.h"
#include <ctime>
#include <thread>
#include <chrono>
const int HMP_run_time = 750;
const int WIN_LOAD_TIME = 1000;

void ani::clearScreen() //清除螢幕
{
    std::cout << CLEANWIN;
    //std::cout <<
    return;
}
//\033[y;xH 设置光标位置
void ani::setPos(short x, short y) //設定游標輸出位置
{
    std::cout << "\033["<< y << ';' << x << 'H';
    return;
}
//移動游標
void moveCurse(short option, short unit)
{
    std::cout << "\033[" << unit;
    switch ( option )
    {
    case CurserMove::MOVEUP:
        std::cout << 'A';
        break;
    case CurserMove::MOVEDOWN:
        std::cout << 'B';
        break;
    case CurserMove::MOVERIGHT:
        std::cout << 'C';
        break;
    case CurserMove::MOVELEFT:
        std::cout << 'D';
        break;
    default:
        break;
    }
    // for ( short i = 0; i < unit; i++ )
    //     std::cout << move;
    return;
}

void ani::loadWindow(const char* color)
{
    const short blockWidth = 2; //一格寬2字元
    short totalBlockCNT =  2*(Global::Screen::winHeight+Global::Screen::winWith/blockWidth);
    short BlockTimePerRun = WIN_LOAD_TIME/totalBlockCNT;
    ani::clearScreen(); //清除螢幕
    ani::setPos(Global::Screen::winStartPosX,Global::Screen::winStartPosY); //設定起始位置
    std::cout << color; //設定顏色
    for ( short i = 0; i < Global::Screen::winWith/blockWidth; i++ ) //從左到右
    {   
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
    }
    for ( short i = 0; i < Global::Screen::winHeight; i++ ) //從上到下
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVEDOWN,1);
        
    }
    for ( short i = 0; i < Global::Screen::winWith/blockWidth; i++ ) //從右到左
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVELEFT,blockWidth); //向左移動
    }
    moveCurse(CurserMove::MOVERIGHT,blockWidth); //向左移動
    for ( short i = 0; i < Global::Screen::winHeight; i++ ) //由下到上
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVEUP,1); //向上移動
    }
    std::cout << Global::Screen::winHeight/blockWidth;
    std::cout << RESET;
    ani::setPos(Global::Screen::winStartPosX,Global::Screen::winStartPosY); //設定起始位置
    for ( short i = 0; i < Global::Screen::winWith/blockWidth; i++ ) //從左到右
    {   
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
    }
    for ( short i = 0; i < Global::Screen::winHeight; i++ ) //從上到下
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVEDOWN,1);
        
    }
    for ( short i = 0; i < Global::Screen::winWith/blockWidth; i++ ) //從右到左
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVELEFT,blockWidth); //向左移動
    }
    moveCurse(CurserMove::MOVERIGHT,blockWidth); //向左移動
    for ( short i = 0; i < Global::Screen::winHeight; i++ ) //由下到上
    {   
        //重設位置
        moveCurse(CurserMove::MOVELEFT,blockWidth); 
        for ( short j = 0; j < blockWidth; j++ ) 
            std::cout << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockTimePerRun));
        moveCurse(CurserMove::MOVEUP,1); //向上移動
    }
    return;
}

void ani::HMP_Loading(const short maxHMP, const short nowHMP, const char* color)
{
    short amountPerChar = maxHMP/Global::maxHMPSize;
    short howManyChar = nowHMP/amountPerChar;
    if ( !howManyChar && nowHMP ) //如果為零則至少顯示一格血，且血量不為零
        howManyChar++;
    for ( short i = 0; i < howManyChar; i++ )
    {
        std::cout << color  << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(HMP_run_time/howManyChar));
    }
    for ( short i = 0; i < Global::maxHMPSize - howManyChar; i++ )
        std::cout << ' ';
    std::cout << nowHMP << '/' << maxHMP;
    std::cout << RESET; //回復原廠設定
    return;
}