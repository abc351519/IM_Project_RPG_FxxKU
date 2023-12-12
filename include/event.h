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

//所有指令打在這裡
namespace Command{
    const std::string QUIT = "quit";
    const std::string ATTACK = "attack";
    const std::string DEFEND = "defend";
    const std::string CHARGE = "charge";
    const std::string RETURN = "return";
};

enum class Activity : short
{
    QUIT,
    TO_USER_INTERFACE,
    TO_BATTLE,
    TO_SHOP,
    ATTACK,
    DEFEND,
    CHARGE,
    RETURN,
};

class Event
{
protected:
    std::map<int,Position> interfacePosition; //每個物件的位置座標
    std::map<const std::string,Activity> command; //每個指令對應的動作
public:
    Event(){}
    ~Event(){}
    virtual void init() = 0; //開啟活動
    virtual void close() = 0;//關閉活動
    virtual void gameLoop() = 0; //該事件的遊戲循環
    virtual Activity receiveCommand() = 0; //輸入指令
    virtual int action(Activity action) = 0;
};

#endif