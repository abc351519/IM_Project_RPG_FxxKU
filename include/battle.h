#ifndef BATTLE_H
#define BATTLE_H

#include "event.h"
#include "enemy.h"
#include "animation.h"
#include "def.h"

namespace BATTLE{
    
    namespace Command{
        const std::string QUIT = "quit";
        const std::string USE = "use";
        const std::string SELL = "sell";
        const std::string BUY = "buy";
        const std::string SKIP = "skip";
    };
    
    namespace POS{
        const Position INIT_MESSAGE = {Global::Screen::winStartPosX,Global::Screen::winStartPosY};
        const Position PLAYER_NAME = {5,5};
        const Position ENEMY_NAME = {46,5};
        const Position PLAYER_HP = {5,7};
        const Position ENEMY_HP = {46,7};
        const Position PLAYER_LV = {5,9};
        const Position ENEMY_LV = {46,9};
        const Position PLAYER_STATE = {5,11};
        const Position ENEMY_STATE = {77,11};
        const Position ENEMY_CD = {77,13};
        const Position RUNEBAG = {13,16};
        const Position RUNE_POINT = {13,15};
    };
    namespace MESSAGE{
        const std::string SELECT_SUCCESS = "Choose successfully!";
        const std::string SELECT_FAIL = "Failed choose.";
        const std::string WRONG_COMMAND = "You are typing the wrong command.";
        const std::string CHOOSING_SESSION = "Select your action mode.";
        const std::string SELECT_CANCEL = "Cancel successfully!";
        const std::string INPUT_ERROR = "Something is wrong with your input command.";
        const std::string ESCAPE_TRYING = "You cannot escape from this battle lol.";
        const std::string BUY_RUNE_SUCCESS = "You've purchased a rune successfully!!!";
        const std::string BUY_RUNE_FAIL = "You don't have enough Rune Point to buy one.";
        const std::string PLAYER_WIN = "Congrates, you've win the battle! ! !";
        const std::string PLAYER_LOSE = "Wasted. You are dead lol.";
        const std::string RUNE_POINT_NOT_ENOUGH = "Your runePoints are not enough to use!";
        const std::string USE_SUCCESS = "Use successfully!";
        const std::string USE_FAILED = "Use failed!";
        const std::string USE_FLAMEBUFF = "You've used FLAMEBUFF and increased your ATK."; // /*+ ansi_color::font::RUNE_FLAME_STONE*/ + "" + /*RESET +*/ "";
        const std::string USE_AQUABUFF = "You've used AQUABUFF and decreased the damage from Enemy."; // /*+ ansi_color::font::RUNE_AQUA_STONE*/ + "" /*+ RESET*/ + "";
        const std::string USE_VITALITYBUFF = "You've used VATILITYBUFF and increased your DEF." ; // /*+ ansi_color::font::RUNE_VITALITY_STONE*/ + "" + /*RESET*/ + "";
        const std::string USE_FLAMEDEBUFF = "You've used FLAMEDEBUFF and decreased ENEMY'S DEF.";
        const std::string USE_AQUADEBUFF = "You've used AQUADEBUFF and decreased ENEMY'S ATK.";
        const std::string USE_VATILITYDEBUFF = "You've used VATILITYDEBUFF and rooted the ENEMY.";
        const std::string ONLY_ONE_CHOOSED = "You've only choosed ONE function Rune.";
        const std::string NOTHING_CHOOSED = "You've choosed NOTHING.";
        std::string USE_AQUAHEAL(short healHp);
        std::string RETURN_POINT(short n);
    };
    namespace ICON{
        extern Picture RUNE_FRAME;
        extern Picture RUNE_FRAME_SELECTED;
        extern Picture RUNE_FRAME_DISSELECTED;
        extern Picture RUNE_AQUA_ICON;
        extern Picture RUNE_FLAME_ICON;
        extern Picture RUNE_VITALITY_ICON;
        extern Picture RUNE_HEAL_ICON;
        extern Picture RUNE_BUFF_ICON;
        extern Picture RUNE_DEBUFF_ICON;
        
    };
    namespace atkRateCounter{
        const double DOMINANT = 1.30;
        const double COUNTERED = 0.7;
    }
};

enum class gameLoopFlag : short {
    PLAYER_LOSE,
    PLAYER_WIN,
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
    void playerTime();
    void enemyTime();
    bool useMode(double& atkRate,RuneEffect& effect);
    void sellMode();
    void updateRune(short time);
    void changeRunePoint(short originalCNT,short time);
    void showRuneSelected(short index);
    void cleanCommandLine();
    void loadMode(const std::string& opt);
}; 

#endif