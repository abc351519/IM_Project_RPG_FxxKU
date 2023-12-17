#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>

//特殊輸出
#define RESET   "\033[0m"
#define CLEANWIN "\033[2J"
#define HIDE_CURSER "\033[?25l" 
#define SHOW_CURSER "\033[?25h"

namespace unicode{
    const std::string FULL_PIXEL = "█";
    const std::string UP_PIXEL = "▀";
    const std::string DOWN_PIXEL = "▄";
    const std::string CORNER_PIXEL_NOLD = "▜";
    const std::string CORNER_PIXEL_NORD = "▛";
    const std::string CORNER_PIXEL_NOLU = "▟";
    const std::string CORNER_PIXEL_NORU = "▙";
    const std::string CORNER_PIXEL_LD = "▖";
    const std::string CORNER_PIXEL_RD = "▗";
    const std::string CORNER_PIXEL_LU = "▘";
    const std::string CORNER_PIXEL_RU = "▝";
    const std::string HAHF_PIXEL_L = "▌";
    const std::string HAHF_PIXEL_R = "▐";
    const std::string HAHF_PIXEL_M = "";
    const std::string DOWN_PIXEL_1_8 = "▁";
    const std::string DOWN_PIXEL_2_8 = "▂";
    const std::string DOWN_PIXEL_3_8 = "▃";
    const std::string DOWN_PIXEL_4_8 = "▄";
    const std::string DOWN_PIXEL_5_8 = "▅";
    const std::string DOWN_PIXEL_6_8 = "▆";
    const std::string DOWN_PIXEL_7_8 = "▇";

    const std::string L_PIXEL_1_8 = "▏";
    const std::string L_PIXEL_2_8 = "▎";
    const std::string L_PIXEL_3_8 = "▍";
    const std::string L_PIXEL_4_8 = "▌";
    const std::string L_PIXEL_5_8 = "▋";
    const std::string L_PIXEL_6_8 = "▊";
    const std::string L_PIXEL_7_8 = "▉";
    //▓▒░■ █   ▚▞ 
    const std::string RUNE_AQUA_SYMBOL = "𝕬";//𝓐";
    const std::string RUNE_FLAME_SYMBOL = "𝕴";
};

namespace ansi_color
{
    namespace font{
        //"\033[38;2;;;m"
        const std::string RUNE_AQUA_STONE = "\033[38;2;41;148;255m";
        const std::string RUNE_AQUA_STONE_DARK = "\033[38;2;30;115;200";
        const std::string RUNE_AQUA_SYMBOL = "\033[38;2;0;0;148m";

        const std::string RUNE_FLAME_STONE = "\033[38;2;255;71;15m";
        const std::string RUNE_FLAME_STONE_DARK = "\033[38;2;166;40;17m";
        const std::string RUNE_FLAME_SYMBOL = "\033[38;2;158;0;0m";

        const std::string RUNEBAG_FRAME = "\033[38;2;255;244;194m";
        const std::string RUNEBAG_BACKGROUND = "\033[38;2;38;38;38m";
    };
    namespace background{
        //"\033[48;2;;;m";
        const std::string RUNEBAG_BACKGROUND = "\033[48;2;38;38;38m";
        const std::string RUNE_AQUA_STONE = "\033[48;2;41;148;255m";
        const std::string RUNE_AQUA_STONE_DARK = "\033[48;2;30;115;200";
        const std::string RUNE_FLAME_STONE = "\033[48;2;255;71;15m";
        const std::string RUNE_FLAME_STONE_DARK = "\033[48;2;166;40;17m";
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
    std::string letter;
    std::string backgroundColor;
    std::string fontColor;
    Pixel(){}
    Pixel(std::string letter, std::string backgroundColor, std::string fontColor)
        : letter(letter), backgroundColor(backgroundColor), fontColor(fontColor)
    {}
    ~Pixel(){};
    void change(std::string letter, std::string backgroundColor, std::string fontColor);
    void change(std::string letter);
    void changeBackColor(std::string backgroundColor);
    void changeFontColor(std::string fontColor);
    void operator=(Pixel pixel);
    void render();
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
    void renderGrapgh(Position startPoint,Picture& graph);
}

#endif