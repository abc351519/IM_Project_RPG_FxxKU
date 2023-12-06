#include "animation.h"
#include <iostream>


int main()
{   
    Position a(3,3);
    ani::clearScreen();
    ani::setPos(a);
    ani::curserShow(false);

    // std::cout << "\033[41mjadijfajdsf";

    // std::cin.ignore();
    // ani::drawLine(a,10, CurserMove::MOVEDOWN, 300);
    
    
    std::cout << "   HP";
    ani::HMP_Loading(100, 1, "\033[41m");
    std::cout << '\n';
    
    std::cout << "   MP";
    ani::HMP_Loading(500, 0, "\033[44m");
    std::cin.ignore();
    ani::loadWindow("\033[48;5;177m");
    std::cin.ignore();

    std::cout << "\033[48;5;181m";
    ani::drawRectangle(a,20,10,20);
    std::cin.ignore();
    
    return 0;
}