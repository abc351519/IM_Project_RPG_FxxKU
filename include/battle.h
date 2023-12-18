#ifndef BATTLE_H
#define BATTLE_H

#include "event.h"
#include "enemy.h"
#include "animation.h"


namespace BATTLE{
    
    namespace Command{
        const std::string QUIT = "quit";
        const std::string USE = "use";
        const std::string SELL = "sell";
        const std::string BUY = "buy";
        const std::string SKIP = "skip";
    };
    
    namespace POS{
        const Position COMMAND_LINE = {0,0};
        const Position PROMPT_LINE = {0,0}; 
        const Position PLAYER_NAME = {5,5};
        const Position ENEMY_NAME = {46,5};
        const Position PLAYER_HP = {5,7};
        const Position ENEMY_HP = {46,7};
        const Position PLAYER_LV = {5,9};
        const Position ENEMY_LV = {77,9};
        const Position PLAYER_STATE = {5,11};
        const Position ENEMY_STATE = {77,11};
        const Position ENEMY_CD = {77,13};
        const Position RUNEBAG = {13,16};
        const Position RUNE_POINT = {64,16};
    };
    namespace MESSAGE{
        
        const std::string WRONG_COMMAND = "u r typing the wrong command.";
    };
    namespace ICON{
        extern Picture RUNE_FRAME;
        extern Picture RUNE_FRAME_SELECTED;
        extern Picture RUNE_AQUA_ICON;
        extern Picture RUNE_FLAME_ICON;
        extern Picture RUNE_VITALITY_ICON;
    };

};

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
    gameLoopFlag gameFlag;
public:
    Battle(Player* player, Enemy* enemy);
    ~Battle();
    
    void init() override; //開啟活動
    void close() override; //關閉活動
    void gameLoop() override; //遊戲循環
    std::string receiveCommand() override; //輸入指令
    void playerTime();
    void enemyTime();
    bool useMode(double& atkRate,RuneEffect& effect);
    void sellMode();
    void updateRune(short time);
}; 

#endif