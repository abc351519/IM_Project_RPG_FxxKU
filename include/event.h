#ifndef EVENT_H
#define EVENT_H

#include <map>
#include <utility>
#include <string>

//所有指令打在這裡
namespace Command{
    const std::string QUIT = "quit";
    const std::string ATTACK = "attack";
    const std::string DEFENSE = "defense";
};

enum Activity
{
    TO_USER_INTERFACE,
    TO_BATTLE,
    TO_SHOP,
    ATTACK,
    DEFENSE,
    CHARGE,
};

class Event
{
private:
    std::map<int,std::pair<short,short>> interfacePosition; //每個物件的位置座標
    std::map<std::string,int> command; //每個指令對應的動作
public:
    Event();
    ~Event();
    virtual void init(); //開啟活動
    virtual void close();//關閉活動
    virtual int receiveCommand(); //輸入指令
    virtual int action(int action);
};

#endif