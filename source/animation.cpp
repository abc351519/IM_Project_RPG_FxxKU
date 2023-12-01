#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "animation.h"
#include "def.h"



void ani::clearScreen() //清除螢幕
{
    std::cout << CLEANWIN;
    return;
}
//設定游標位置（"\033[y;xH"）
void ani::setPos(short x, short y) //設定游標輸出位置
{
    std::cout << "\033["<< y << ';' << x << 'H';
    return;
}
//繪畫直線
void ani::drawLine(short length, short direction, short timePerBlock)
{
    switch ( direction )
    {
    case CurserMove::MOVEUP:
        for ( short i = 0; i < length; i++ ) //由下到上
        {   
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            moveCurse(CurserMove::MOVEUP,1); //向上移動
            moveCurse(CurserMove::MOVELEFT,blockWidth); 
            fflush(stdout); //刷新紀錄
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVEDOWN:
        for ( short i = 0; i < length; i++ ) //從上到下
        {   
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            moveCurse(CurserMove::MOVEDOWN,1);
            moveCurse(CurserMove::MOVELEFT,blockWidth); 
            fflush(stdout); //刷新紀錄
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVERIGHT: //向右畫線
        for ( short i = 0; i < length; i++ )
        {   
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            fflush(stdout); //刷新紀錄
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVELEFT:
        for ( short i = 0; i < length; i++ ) //從右到左
        {   
            moveCurse(CurserMove::MOVELEFT,blockWidth); //向左移動
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            moveCurse(CurserMove::MOVELEFT,blockWidth); //向左移動
            fflush(stdout); //刷新紀錄
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    default:
        //可以用exception and throw
        return;
    }
    return;
}
void ani::drawRectangle(short width, short height, short timePerBlock)
{
    short totalBlockCNT =  2 * (height + width);

    ani::drawLine(width,CurserMove::MOVERIGHT,timePerBlock);
    
    ani::moveCurse(CurserMove::MOVELEFT,blockWidth);
    ani::drawLine(height,CurserMove::MOVEDOWN,timePerBlock);

    ani::moveCurse(CurserMove::MOVERIGHT,blockWidth);
    ani::moveCurse(CurserMove::MOVEUP,1);
    ani::drawLine(width,CurserMove::MOVELEFT,timePerBlock);

    ani::drawLine(height,CurserMove::MOVEUP,timePerBlock);

    return;
}
//移動游標
void ani::moveCurse(short option, short unit)
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
        //可以用exception
        break;
    }
    return;
}
//開啟關閉游標
void ani::curserShow(bool isON)
{
    if ( isON )
        std::cout << SHOW_CURSER;
    else 
        std::cout << HIDE_CURSER;
    return;
}
void ani::loadWindow(const char* color)
{
    short totalBlockCNT =  2 * (Global::Screen::winHeight + Global::Screen::winWith/blockWidth); //總方塊數
    short BlockTimePerRun = ani::WIN_LOAD_TIME/totalBlockCNT; //每次跑的時間
    ani::clearScreen(); //清除螢幕
    std::cout << color; //設定顏色
    ani::setPos(Global::Screen::winStartPosX,Global::Screen::winStartPosY); //設定起始位置
    ani::drawRectangle(Global::Screen::winWith/ani::blockWidth,Global::Screen::winHeight,BlockTimePerRun);

    //清除輸出，重複
    std::cout << RESET;
    ani::setPos(Global::Screen::winStartPosX,Global::Screen::winStartPosY);
    ani::drawRectangle(Global::Screen::winWith/ani::blockWidth,Global::Screen::winHeight,BlockTimePerRun);
    return;
}

void ani::HMP_Loading(const short maxHMP, const short nowHMP, const char* color)
{
    short amountPerChar = maxHMP/ani::maxHMPSize;
    short howManyChar = nowHMP/amountPerChar;

    short BlockLoadTime = ani::HMP_run_time/ani::maxHMPSize;

    if ( !howManyChar && nowHMP ) //如果為零則至少顯示一格血，且血量不為零
        howManyChar++;
    for ( short i = 0; i < howManyChar; i++ )
    {
        std::cout << color  << ' ';
        fflush(stdout); //刷新紀錄
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockLoadTime));
    }
    std::cout << RESET; //回復原廠設定
    for ( short i = 0; i < ani::maxHMPSize - howManyChar; i++ ){
        std::cout << ' ';
        std::this_thread::sleep_for(std::chrono::milliseconds(BlockLoadTime));
    }
    std::string numStr = std::to_string(nowHMP);
    ani::moveCurse(CurserMove::MOVERIGHT,ani::HP_CHAR_WIDTH - numStr.length());
    std::cout << nowHMP << '/' << maxHMP;
    return;
}