#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>

//特殊輸出
#define RESET   "\033[0m"
#define CLEANWIN "\033[2J"
#define HIDE_CURSER "\033[?25l" 
#define SHOW_CURSER "\033[?25h" 
namespace ansi_color
{
    namespace font{
        //"\033[38;2;;;m"
        const std::string RUNE_AQUA = "\033[38;2;166;199;252m";
        const std::string RUNEBAG_FRAME = "\033[48;2;255;244;194m";
    };
    namespace background{
        //"\033[48;2;;;m";
        const std::string RUNE_AQUA = "\033[48;2;41;148;255m";
        const std::string RUNEBAG_BACKGROUND = "\033[48;2;38;38;38m";
    };
};


struct Position
{
    short x;
    short y;
    Position(const short x, const short y);
};

struct Pixel
{
    char letter;
    std::string backgroundColor;
    std::string fontColor;
};


struct Picture
{
    short char_width;
    short char_height;
    Pixel** graph;
    Picture(short width, short height);
    ~Picture();
};

enum class CurserMove : short
{
    MOVEUP,
    MOVEDOWN,
    MOVERIGHT,
    MOVELEFT
};

namespace ani{
    // constant
    const short maxHMPSize = 20;
    const int HMP_run_time = 750;
    const int WIN_LOAD_TIME = 1000;
    const short HP_CHAR_WIDTH = 4;
    const short blockWidth = 2; //一格方塊的字元寬度

    void clearScreen();
    void setPos(short x, short y);
    void setPos(const Position& pos);
    void moveCurse(CurserMove option, short unit);
    void curserShow(bool isON);
    void drawLine(const Position startPoint, short length, CurserMove direction, short timePerBlock);
    void drawRectangle(const Position startPoint, short width, short height, short totalRunTime);
    void loadWindow(std::string color);
    void HMP_Loading(short maxHMP, short nowHMP, std::string color);
}

#endif