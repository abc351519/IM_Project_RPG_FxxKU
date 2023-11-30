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
    void clearScreen();
    void setPos(short x, short y);
    void loadWindow(const char* color);
    void HMP_Loading(short maxHMP, short nowHMP, const char* color);
}

#endif