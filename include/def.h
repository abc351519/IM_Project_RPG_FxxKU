#ifndef DEF_H
#define DEF_H

#define s_cat static_cast

// #define MOVEUP  \033[nA //光标上移n行
// #define MOVEDOWN    \033[nB //光标下移n行
// #define MOVERIGHT    \033[nC //光标右移n行
// #define MOVELEFT    \033[nD //光标左移n行
    //\033[y;xH //设置光标位置
 //清屏
// \033[?25l 隐藏光标
// \033[?25h 显示光标
// \033[38;5;177m
// #define BLACK   "\033[30m"      /* Black */
// #define RED     "\033[31m"      /* Red */
// #define GREEN   "\033[32m"      /* Green */
// #define YELLOW  "\033[33m"      /* Yellow */
// #define BLUE    "\033[34m"      /* Blue */
// #define MAGENTA "\033[35m"      /* Magenta */
// #define CYAN    "\033[36m"      /* Cyan */
// #define WHITE   "\033[37m"      /* White */
// #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
// #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
// #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
// #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
// #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
// #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
// #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
// #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
// #define BRED     "\033[41m"      /* Red */
// #define BBLUE    "\033[44m"      /* Blue */
namespace Global {
    const int HP_LIMIT = 1000;
    namespace Screen {
        const short winWith = 80;
        const short winHeight = 22;
        const short winStartPosX = 1;
        const short winStartPosY = 1;
    }
}

#endif