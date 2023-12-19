#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "graph.h"
#include "animation.h"
#include "def.h"

std::mutex mtx;

void printNiceLy(short number, short unit)
{
    std::string s = std::to_string(number);
    for ( int i = 0; i < unit - s.size(); i++ )
        std::cout << ' '; 
    std::cout << RESET;
    std::cout << number;
    return;
}

#if defined(WIN32) || defined(WIN32) || defined(_WIN64) || defined(__CYGWIN) || defined(WIN32) || defined(_WIN32) || defined(MINGW32) || defined(WINNT) || defined(WINNT) || defined(__WINNT) || defined(X86) || defined(i386) || defined(__i386)
void winapi::write( wchar_t const* const s, int const n )
{
    DWORD n_written;
    WriteConsole( winapi::std_output, s, n, &n_written, 0 );
}

void winapi::write( std::wstring const& s )
{
    winapi::write( s.c_str(), s.length() );
}
#endif

Position::Position(const short x, const short y)
    : x(x), y(y)
{}

Position Position::operator+(unsigned short dx) const
{
    Position pos(*this);
    pos.x += dx;
    return pos;
}

Position Position::operator-(unsigned short dx) const
{
    Position pos(*this);
    pos.x -= dx;
    return pos;
}
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
    winapi::write(letter);
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
void ani::drawLine(const Position& startPoint, short length, CurserMove direction, short timePerBlock)
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
            FLUSH; 
            mtx.unlock();
            SLEEP(timePerBlock);
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
            FLUSH; 
            mtx.unlock();
            SLEEP(timePerBlock);
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
            FLUSH;
            mtx.unlock();
            SLEEP(timePerBlock);
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
            FLUSH; 
            mtx.unlock();
            SLEEP(timePerBlock);
        }
        break;
    default:
        //可以用exception and throw
        return;
    }
    return;
}
void ani::drawRectangle(const Position& startPoint, short width, short height, short totalRunTime)
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
    return;
}

void ani::dimishWindow()
{
    Position startPoint(Global::Screen::winStartPosX,Global::Screen::winStartPosY);
    //清除輸出，重複
    std::cout << RESET; 
    ani::drawRectangle(startPoint,Global::Screen::winWith/ani::blockWidth,Global::Screen::winHeight,ani::WIN_LOAD_TIME);
    return;
}

void ani::HPLoading(const Position& startPoint, const short maxHMP, const std::string& color)
{
    Position currentPos(startPoint);
    short numberRunTime = ani::HMP_run_time/maxHMP;
    short BlockLoadTime = ani::HMP_run_time/ani::maxHMPSize;
    mtx.lock();
    ani::setPos(currentPos);
    std::cout <<RESET;
    std::cout << "HP"; //輸出HP字串
    mtx.unlock();
    //跑血條
    currentPos.x += 2;
    for ( int i = 0; i < maxHMPSize; i++ )
    {
        mtx.lock();
        ani::setPos(currentPos);
        std::cout << color;
        std::cout << unicode::FULL_PIXEL;
        FLUSH;
        currentPos.x++;
        mtx.unlock();
        SLEEP(BlockLoadTime);
    }
    mtx.lock();
    currentPos.x += 4;
    ani::setPos(currentPos);
    std::cout << RESET;
    std::cout << '/' << maxHMP;
    mtx.unlock();
    currentPos.x -= 4;
    numberChange(currentPos,0,maxHMP,numberRunTime,4);
    return;
}

void ani::renderGrapgh(const Position& startPoint, const Picture& graph)
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
    FLUSH;
    return;
}


void ani::runMessage(const Position& startPoint,const std::string& message,std::string color)
{
    Position currentPos(startPoint);
    for ( auto strc : message )
    {
        mtx.lock();
        ani::setPos(currentPos); //設定位置
        
        std::cout << color; //設定顏色
        std::cout << strc; //輸出
        FLUSH; 
        
        currentPos.x++; //向右移動1
        mtx.unlock();
        SLEEP(MESSAGE_PER_CHAR_LOAD_TIME);
    }
    return;
}

void ani::renderRuneFrame(const Position& startPoint, const Picture& graph, short amount, short time)
{
    Position currentPos = startPoint;
    for ( int i = 0; i < amount; i++ )
    {
        mtx.lock();
        ani::setPos(currentPos);
        ani::renderGrapgh(currentPos,graph);
        currentPos.y += 4;
        ani::setPos(currentPos);
        std::cout << ansi_color::background::RUNEBAG_INDEX << ansi_color::font::RUNEBAG_INDEX << i+1;
        FLUSH;
        mtx.unlock();
        SLEEP(time);
        currentPos.y -= 4;
        currentPos.x += 7;
    }
    std::cout << RESET;
    return;
}

void ani::numberChange(const Position& startPoint, const int start, const int end, short time, short unit)
{
    if ( start < end ) { //遞增
        for ( int i = start; i !=(end+1); i++ )
        {   
            mtx.lock();
            ani::setPos(startPoint);
            printNiceLy(i,unit);
            mtx.unlock();
            FLUSH;
            SLEEP(time);
        }
    } else { //遞減
        for ( int i = start; i != (end-1); i-- )
        {   
            mtx.lock();
            ani::setPos(startPoint);
            printNiceLy(i,unit);
            mtx.unlock();
            FLUSH;
            SLEEP(time);
        }
    }    
    return;
}