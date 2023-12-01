#ifndef ANIMATION_H
#define ANIMATION_H
//特殊輸出
#define RESET   "\033[0m"
#define CLEANWIN "\033[2J"
#define HIDE_CURSER "\033[?25l" 
#define SHOW_CURSER "\033[?25h" 

enum CurserMove
{
    MOVEUP,
    MOVEDOWN,
    MOVERIGHT,
    MOVELEFT
};

namespace ani{
    // const
    const short maxHMPSize = 20;
    const int HMP_run_time = 750;
    const int WIN_LOAD_TIME = 1000;
    const short HP_CHAR_WIDTH = 4;
    const short blockWidth = 2; //一格方塊的字元寬度

    void clearScreen();
    void setPos(short x, short y);
    void moveCurse(short option, short unit);
    void curserShow(bool isON);
    void drawLine(short length, short direction, short timePerBlock);
    void drawRectangle(short width, short height, short timePerBlock);
    void loadWindow(const char* color);
    void HMP_Loading(short maxHMP, short nowHMP, const char* color);
}

#endif