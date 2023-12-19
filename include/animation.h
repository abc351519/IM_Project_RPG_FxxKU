#ifndef ANIMATION_H
#define ANIMATION_H

#include <mutex>
#include <string>

extern std::mutex mtx;

//特殊輸出
#define RESET   "\033[0m"
#define CLEANWIN "\033[2J"
#define HIDE_CURSER "\033[?25l" 
#define SHOW_CURSER "\033[?25h"

#define SLEEP(time) std::this_thread::sleep_for(std::chrono::milliseconds(time))
#define FLUSH fflush(stdout)

#if defined(WIN32) || defined(WIN32) || defined(_WIN64) || defined(__CYGWIN) || defined(WIN32) || defined(_WIN32) || defined(MINGW32) || defined(WINNT) || defined(WINNT) || defined(__WINNT) || defined(X86) || defined(i386) || defined(__i386)
typedef std::wstring spSymbol; //window下用wchar_t

#define UNICODE
//#define NOMINMAX
#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace winapi {
    HANDLE const std_output = GetStdHandle( STD_OUTPUT_HANDLE );
    void write( wchar_t const* const s, int const n );
    void write( std::wstring const& s );
}
#define WRITE_UNI(wstr) winapi::write(wstr);

#define SET_CONST_SPSYMBOL(name, value) const spSymbol name = L##value
#elif defined(__APPLE__) || defined(__MACH__)
typedef std::string spSymbol; //mac下用c++string
#define SET_CONST_SPSYMBOL(name, value) const spSymbol name = value
#define WRITE_UNI(str) std::cout << str
#endif

void printNiceLy(short number, short unit);

namespace unicode{
    SET_CONST_SPSYMBOL(FULL_PIXEL,"█");
    SET_CONST_SPSYMBOL(UP_PIXEL,"▀");
    SET_CONST_SPSYMBOL(DOWN_PIXEL,"▄");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_NOLD,"▜");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_NORD,"▛");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_NOLU,"▟");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_NORU,"▙");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_LD,"▖");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_RD,"▗");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_LU,"▘");
    SET_CONST_SPSYMBOL(CORNER_PIXEL_RU,"▝");
    SET_CONST_SPSYMBOL(HAHF_PIXEL_L,"▌");
    SET_CONST_SPSYMBOL(HAHF_PIXEL_R,"▐");
    SET_CONST_SPSYMBOL(HAHF_PIXEL_M,"");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_1_8,"▁");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_2_8,"▂");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_3_8,"▃");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_4_8,"▄");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_5_8,"▅");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_6_8,"▆");
    SET_CONST_SPSYMBOL(DOWN_PIXEL_7_8,"▇");

    SET_CONST_SPSYMBOL(L_PIXEL_1_8,"▏");
    SET_CONST_SPSYMBOL(L_PIXEL_2_8,"▎");
    SET_CONST_SPSYMBOL(L_PIXEL_3_8,"▍");
    SET_CONST_SPSYMBOL(L_PIXEL_4_8,"▌");
    SET_CONST_SPSYMBOL(L_PIXEL_5_8,"▋");
    SET_CONST_SPSYMBOL(L_PIXEL_6_8,"▊");
    SET_CONST_SPSYMBOL(L_PIXEL_7_8,"▉");
    //▓▒░■ █   ▚▞ 
    SET_CONST_SPSYMBOL(RUNE_AQUA_SYMBOL,"𝕬");//𝓐");
    SET_CONST_SPSYMBOL(RUNE_FLAME_SYMBOL,"𝕴");
    


};

namespace ansi_color
{
    namespace font{
        //"\033[38;2;;;m"
        const std::string HP = "\033[38;5;160m";

        const std::string RUNE_AQUA_STONE = "\033[38;2;41;148;255m";
        const std::string RUNE_AQUA_STONE_DARK = "\033[38;2;30;115;200m";
        const std::string RUNE_AQUA_SYMBOL = "\033[38;2;0;0;148m";

        const std::string RUNE_FLAME_STONE = "\033[38;2;255;71;15m";
        const std::string RUNE_FLAME_STONE_DARK = "\033[38;2;166;40;17m";
        const std::string RUNE_FLAME_SYMBOL = "\033[38;2;158;0;0m";

        const std::string RUNEBAG_FRAME = "\033[38;2;235;235;255m";
        const std::string RUNEBAG_FRAME_DARK = "\033[38;2;129;129;193m";
        const std::string RUNEBAG_FRAME_SELECTED = "\033[38;2;235;235;255m";
        const std::string RUNEBAG_FRAME_SELECTED_DARK = "\033[38;2;129;129;193m";
        const std::string RUNEBAG_BACKGROUND = "\033[38;2;38;38;38m";
        const std::string RUNEBAG_INDEX = "\033[38;2;40;0;77m";
        const std::string RUNEBAG_SELECTED_INDEX = "\033[38;2;40;0;77m";

    };
    namespace background{
        //"\033[48;2;;;m";
        const std::string BATTLE_COLOR = "\033[48;2;108;51;101m";

        const std::string RUNEBAG_FRAME = "\033[48;2;235;235;255m";
        const std::string RUNEBAG_FRAME_DARK = "\033[48;2;129;129;193m";
        const std::string RUNEBAG_FRAME_SELECTED = "\033[48;2;235;235;255m";
        const std::string RUNEBAG_FRAME_SELECTED_DARK = "\033[48;2;129;129;193m";
        const std::string RUNEBAG_BACKGROUND = "\033[48;2;38;38;38m";
        const std::string RUNEBAG_INDEX = "\033[48;2;235;235;255m";
        const std::string RUNEBAG_SELECTED_INDEX = "\033[48;2;40;0;77m";

        const std::string RUNE_AQUA_STONE = "\033[48;2;41;148;255m";
        const std::string RUNE_AQUA_STONE_DARK = "\033[48;2;30;115;200m";
        
        const std::string RUNE_FLAME_STONE = "\033[48;2;255;71;15m";
        const std::string RUNE_FLAME_STONE_DARK = "\033[48;2;166;40;17m";



    };
};


struct Position
{
    short x;
    short y;
    Position(const short x, const short y);    
    Position operator+(unsigned short dx) const;
    Position operator-(unsigned short dx) const;
};

struct Pixel
{
    spSymbol letter;
    std::string backgroundColor;
    std::string fontColor;
    Pixel(){}
    Pixel(spSymbol letter, std::string backgroundColor, std::string fontColor)
        : letter(letter), backgroundColor(backgroundColor), fontColor(fontColor)
    {}
    ~Pixel(){};
    void change(spSymbol letter, std::string backgroundColor, std::string fontColor);
    void change(spSymbol letter);
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
    const int MESSAGE_PER_CHAR_LOAD_TIME = 1000/30;
    const short HP_CHAR_WIDTH = 4;
    const short blockWidth = 2; //一格方塊的字元寬度
    const short RUNEBAG_RUN_TIME = 80;
    const short RUNE_SHOW_TIME = 150;


    void clearScreen();
    void setPos(short x, short y);
    void setPos(const Position& pos);
    void moveCurse(CurserMove option, short unit);
    void curserShow(bool isON);
    void drawLine(const Position& startPoint, short length, CurserMove direction, short timePerBlock);
    void drawRectangle(const Position& startPoint, short width, short height, short totalRunTime);
    void loadWindow(std::string color);
    void dimishWindow();
    void HPLoading(const Position& ,short maxHMP, const std::string& color);
    void renderGrapgh(const Position& startPoint,const Picture& graph);
    void runMessage(const Position& startPoint,const std::string& message,std::string color);
    void renderRuneFrame(const Position& startPoint,const Picture& graph,short amount, short time);
    void numberChange(const Position& startPoint, const int start, const int end, short time, short unit);
}

#endif