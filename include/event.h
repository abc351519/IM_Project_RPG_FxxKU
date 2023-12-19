#ifndef EVENT_H
#define EVENT_H

#include <map>
#include <string>
#include <iostream>
#include <exception>

#include "animation.h"
#include "player.h"

#define MAX_CLEAN_CHAR 100
#define IN_THE_EVENT -1

short strToShort(std::string str);
std::string toSmall(std::string str);

namespace EVENT{
    namespace POS{
        const Position COMMAND_LINE = {3,23};
        const Position PROMPT_FRAME = {2,24};
        const Position PROMPT_LINE = {3,25};
    };
};


//所有
enum class Activity : short
{
    QUIT,
    TO_USER_INTERFACE,
    TO_BATTLE,
};

class Event
{
protected:
    std::map<int,Position> interfacePosition; //每個物件的位置座標
    std::map<const std::string,Activity> command; //每個指令對應的動作
public:
    Event(){}
    ~Event(){}
    std::string receiveCommand(); //輸入指令
    void loadPromptFrame(const std::string& color);
    void loadPromptMessage(const std::string& message, const std::string& frameColor, const std::string& Color);
    virtual void init() = 0; //開啟活動
    virtual void close() = 0;//關閉活動
    virtual void gameLoop() = 0; //該事件的遊戲循環

};



#endif