#ifndef ANIMATION_H
#define ANIMATION_H

enum CurserMove
{
    MOVEUP,
    MOVEDOWN,
    MOVERIGHT,
    MOVELEFT
};

namespace ani{
    const short maxHMPSize = 20;
    void clearScreen();
    void setPos(short x, short y);
    void moveCurse(short option, short unit);
    void drawLine(short length, short blockWidth, short direction, short timePerBlock);
    void loadWindow(const char* color);
    void HMP_Loading(short maxHMP, short nowHMP, const char* color);
}

#endif