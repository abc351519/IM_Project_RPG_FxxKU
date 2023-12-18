#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

#include "animation.h"
#include "def.h"

std::mutex mtx;

Position::Position(const short x, const short y)
    : x(x), y(y)
{}

void Pixel::change(spSymbol letter, std::string backgroundColor, std::string fontColor)
{
    this->letter = letter;
    this->backgroundColor = backgroundColor;
    this->fontColor = fontColor;
    return;
}

void Pixel::change(spSymbol letter)
{
    this->letter = letter;
    return;
}

void Pixel::changeBackColor(std::string backgroundColor)
{
    this->backgroundColor = backgroundColor;
    return;
}

void Pixel::changeFontColor(std::string fontColor)
{
    this->fontColor = fontColor;
    return;
}

void Pixel::operator=(Pixel pixel)
{
    backgroundColor = pixel.backgroundColor;
    fontColor = pixel.fontColor;
    letter = pixel.letter;
}

void Pixel::render()
{
    std::cout << backgroundColor << fontColor;
#if defined(WIN32) || defined(WIN32) || defined(_WIN64) || defined(__CYGWIN) || defined(WIN32) || defined(_WIN32) || defined(MINGW32) || defined(WINNT) || defined(WINNT) || defined(__WINNT) || defined(X86) || defined(i386) || defined(__i386)    
    std::cout << "saihf";
#elif defined(__APPLE__) || defined(__MACH__)
    std::cout << letter;
#endif
}

Picture::Picture(short width, short height)
    : char_width(width), char_height(height)
{
    graph = new Pixel*[char_width];
    for ( int i = 0; i < char_width; i++ )
        graph[i] = new Pixel[char_height];
}

Picture::~Picture()
{
    for ( int i = 0; i < char_width; i++ )
    {    
        delete[] graph[i];
        graph[i] = nullptr;
    }
    delete[] graph;
    graph = nullptr;
}


void ani::clearScreen() //清除螢幕
{
    std::cout << CLEANWIN;
    return;
}
//設定游標位置（"\033[y;xH"）
void ani::setPos(short x, short y) //設定游標輸出位置
{
    std::cout << "\033[" << y << ';' << x << 'H';
    return;
}
void ani::setPos(const Position& pos)
{
    std::cout << "\033[" << pos.y << ';' << pos.x << 'H';
    return;
}

//繪畫直線
void ani::drawLine(const Position startPoint, short length, CurserMove direction, short timePerBlock)
{
    Position currentPos(startPoint);
    switch ( direction )
    {
    case CurserMove::MOVEUP:
        for ( short i = 0; i < length; i++ ) //由下到上
        {   
            mtx.lock();
            ani::setPos(currentPos);
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            currentPos.y--; //向上移動1
            fflush(stdout); 
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVEDOWN:
        for ( short i = 0; i < length; i++ ) //從上到下
        {   
            mtx.lock();
            ani::setPos(currentPos);
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            currentPos.y++; //向下移動1
            fflush(stdout); 
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVERIGHT: //向右畫線
        for ( short i = 0; i < length; i++ )
        {   
            mtx.lock();
            ani::setPos(currentPos);
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            currentPos.x += blockWidth; //向右移動2
            fflush(stdout);
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    case CurserMove::MOVELEFT:
        for ( short i = 0; i < length; i++ ) //從右到左
        {   
            mtx.lock();
            currentPos.x -= blockWidth; //先向左移動2
            ani::setPos(currentPos);
            for ( short j = 0; j < ani::blockWidth; j++ ) 
                std::cout << ' ';
            fflush(stdout); 
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(timePerBlock));
        }
        break;
    default:
        //可以用exception and throw
        return;
    }
    return;
}
void ani::drawRectangle(const Position startPoint, short width, short height, short totalRunTime)
{
    
    short totalBlockCNT =  2 * (height + width);
    short timePerBlock = totalRunTime / totalBlockCNT;

    Position currentPos(startPoint);

    ani::drawLine(currentPos,width,CurserMove::MOVERIGHT,timePerBlock); //畫第一條線

    currentPos.x += (width-1) * ani::blockWidth;
    ani::drawLine(currentPos,height,CurserMove::MOVEDOWN,timePerBlock); //第二條線

    currentPos.y += height-1;
    currentPos.x += ani::blockWidth;
    ani::drawLine(currentPos,width,CurserMove::MOVELEFT,timePerBlock);

    currentPos.x -= width * ani::blockWidth;
    ani::drawLine(currentPos,height,CurserMove::MOVEUP,timePerBlock);

    return;
}
//移動游標
void ani::moveCurse(CurserMove option, short unit)
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
void ani::loadWindow(std::string color)
{
    Position startPoint(Global::Screen::winStartPosX,Global::Screen::winStartPosY);
    ani::clearScreen(); //清除螢幕
    std::cout << color; //設定顏色
    ani::drawRectangle(startPoint,Global::Screen::winWith/ani::blockWidth,Global::Screen::winHeight,ani::WIN_LOAD_TIME);
    //清除輸出，重複
    std::cout << RESET; 
    ani::drawRectangle(startPoint,Global::Screen::winWith/ani::blockWidth,Global::Screen::winHeight,ani::WIN_LOAD_TIME);
    return;
}

void ani::HMP_Loading(const short maxHMP, const short nowHMP, std::string color)
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

void ani::renderGrapgh(Position startPoint, Picture& graph)
{
    Position currentPos(startPoint);
    for ( int i = 0; i < graph.char_height; i++ )
    {
        for ( int j = 0; j < graph.char_width; j++ )
        {
            ani::setPos(currentPos);
            graph.graph[j][i].render();
            currentPos.x++;
        }
        currentPos.x -= graph.char_width;
        currentPos.y++;
    }
    std::cout << RESET;
    return;
}
