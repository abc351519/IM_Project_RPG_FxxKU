#ifndef BATTLE_H
#define BATTLE_H

#include "event.h"
#include "enemy.h"
#include "animation.h"

namespace BATTLE{
    namespace POS{
        const Position COMMAND_LINE = {0,0};
        const Position PLAYER_NAME = {5,3};
        const Position ENEMY_NAME = {77,3};
        const Position PLAYER_HP = {5,4};
        const Position ENEMY_HP = {77,4};
        //const Position  = {,};
    };
    namespace MESSAGE{
        const std::string WRONG_COMMAND = "u r typing the wrong command.";
    };
    namespace ICON{
        Picture RUNE_ICON(3,3);
    };

};
//定義畫圖圖形
Pixel pixel
BATTLE::ICON::RUNE_ICON.graph[0][0] = ;

enum class gameLoopFlag : short {
    PLAYER_LOSE,
    PLAYER_WIN,
    PLAYER_QUIT,
    PLAYER_BATTLE,
};

class Area;
class Player;

class Battle : public Event
{
private:
    Player* player;
    Enemy* enemy;
public:
    gameLoopFlag gameFlag;
    Battle(Player* player, Enemy* enemy);
    ~Battle();
    void init() override; //開啟活動
    void close() override; //關閉活動
    void gameLoop() override; //遊戲循環
    Activity receiveCommand() override; //輸入指令
    int action(Activity action) override;
};

#endif