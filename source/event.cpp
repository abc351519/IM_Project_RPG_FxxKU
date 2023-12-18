#include "event.h"
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