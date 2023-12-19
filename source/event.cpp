#include "event.h"
#include "def.h"

#include <cctype>


short strToShort(std::string str)
{
    short number = 0;
    bool startCount = false; //還沒開始算
    for ( auto c : str ) 
    {
        if ( isdigit(c) ) { //是數字
            startCount = true; //開始算
            number *= 10;
            number += static_cast<short>(c - '0');
        } 
        if ( !isdigit(c) && !startCount ) { //還沒遇到數字
            continue;
        }
        if ( !isdigit(c) && startCount ) {//開始算之後遇到不是數字
            break;
        }
    }
    return number;
}

std::string toSmall(std::string str)
{
    std::string retStr;
    for ( auto c : str )
    {
        retStr += static_cast<char>(tolower(c));
    }
    return retStr;
}

void Event::loadPromptFrame(const std::string& color)
{
    mtx.lock();
    ani::setPos(EVENT::POS::PROMPT_FRAME);
    std::cout << color;
    WRITE_UNI(unicode::CORNER_LINE_LU);
    for ( int i = 0; i < Global::Screen::winWith - 3; i++ )
    {
        WRITE_UNI(unicode::LINE_HORIZONTAL);
    }
    WRITE_UNI(unicode::CORNER_LINE_RU);
    
    ani::setPos(EVENT::POS::PROMPT_FRAME);
    ani::moveCurse(CurserMove::MOVEDOWN,1);
    WRITE_UNI(unicode::LINE_VERTICAL);
    for ( int i = 0; i < Global::Screen::winWith - 3; i++ )
    {
        std::cout << ' ';
    }
    WRITE_UNI(unicode::LINE_VERTICAL);

    ani::setPos(EVENT::POS::PROMPT_FRAME);
    ani::moveCurse(CurserMove::MOVEDOWN,2);
    WRITE_UNI(unicode::CORNER_LINE_LD);
    for ( int i = 0; i < Global::Screen::winWith - 3; i++ )
    {
        WRITE_UNI(unicode::LINE_HORIZONTAL);
    }
    WRITE_UNI(unicode::CORNER_LINE_RD);

    std::cout << RESET;
    mtx.unlock();
    return;
}


std::string Event::receiveCommand()
{
    mtx.lock();
    std::string input;
    ani::setPos(EVENT::POS::COMMAND_LINE); //設定輸入位置
    std::cout << ansi_color::font::COMMAND_LINE_COLOR << "Type command here: ";
    ani::curserShow(true); //開啟游標

    std::getline(std::cin,input);
    
    std::cout << RESET;
    FLUSH;

    ani::curserShow(false); //關閉游標
    mtx.unlock();
    return input;
}

// void Event::loadPromptMessage(const std::string& message)
// {


//     return;
// }
