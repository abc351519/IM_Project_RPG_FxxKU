#ifndef RUNE_H
#define RUNE_H

#include <vector>

const short MAX_RUNE_COUNT = 8; //最多持有的符文數量
const short INIT_RUNE_COUNT = 4; //一開始給的符文數
const short RUNE_GET_ROUNDLY = 2; //每回合給的
const short MAX_RUNEPOINT = 15;

const short INIT_RUNEPOINTS = 7;
const short RUNEPOINT_GET_ROUNDLY = 3;
//可議再商量
const short RUNE_PER_COST = 6; 
const short RUNE_SOLD_NORMAL_EARN = 3;
const short RUNE_SOLD_FUNCTION_EARN = 6;

namespace attackRate{
    const double RUNE_ONE = 1.0;
    const double RUNE_TWO = 1.6;
    const double RUNE_THREE = 2.5;
};

namespace odds
{
    //各種符文出現機率
    const short APPEAR_FUNCTION_RUNE = 15;
    const short APPEAR_NORMAL_RUNE = 85;
    //等級合成機率
    const short MAKE_UP_LV_TWO = 70;
    const short MAKE_UP_LV_THREE = 40;
    const short DEBUFF = 75;
    const short BUFF = 85;
    const short HEAL = 100; 
};

namespace mpConsume
{
    const short NORMAL_RUNE_ONE = 3; //使用一個攻擊符文
    const short FUNCTION_RUNE = 6; //使用功能符文
    const short MAKE_UP_LV_TWO = 6; //合成兩個符文
    const short MAKE_UP_LV_THREE = 10; //合成三個符文
};

enum class RuneCondition{
    RuneNotEnough,
    cancelSucceed,
    runeLimitExceed

};


enum class RuneEffect
{
    USELESS,

    FLAMENORMAL,
    AQUANORMAL,
    VITALITYNORMAL,

    FLAMEHEAL,
    AQUAHEAL,
    VITALITYHEAL,

    FLAMEBUFF,
    AQUABUFF,
    VITALITYBUFF,

    FLAMEDEBUFF,
    AQUADEBUFF,
    VITALITYDEBUFF,
    
    FLAMEATTACK,
    AQUAATTACK,
    VITALITYATTACK
};

enum Rune : short
{
    FLAME = 1,
    AQUA,
    VITALITY,
    
    HEAL,
    BUFF,
    DEBUFF
};

class RuneBag
{
private:
    RuneCondition conditionType;
    bool isFunction; //選擇卡組是否為功能
    short attackType; // 1:flame 2:aqua 3:vitality
    short functionType; // 4:heal 5:buff 6:debuff
    short selectedNum; // 選擇張數
    std::vector<short> runes;
    bool isSelected[MAX_RUNE_COUNT];
public:
    RuneBag(); //init 
    ~RuneBag(){};
    void runeGet(short runeGetNumber); //每回合隨機給予符文
    short runeSelectToUse(short index); //回傳選取是否有效
    short runeSelectToSell(short index);
    bool buyRune(short& runePoint);
    bool use(double& attackRate, RuneEffect& effect, short& runePoints);
    bool sell(short& runePoints);
    void selectReset();
    short getRuneCount();
    short getRune(short index);
    bool isRuneSelected(short index);
    RuneCondition getConditionType() const;
};

#endif