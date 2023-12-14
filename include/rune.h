#ifndef RUNE_H
#define RUNE_H

#include <vector>

struct Pair
{
    short index;
    short runeType;
};


const short MAX_RUNE_COUNT = 8; //最多持有的符文數量
const short INIT_RUNE_COUNT = 4; //一開始給的符文數
const short RUNE_GET_ROUNDLY = 2; //每回合給的
const short MAX_RUNEPOINT = 15;
const short RUNEPOINT_GET_ROUNDLY = 3;

namespace odds
{
    //各種符文出現機率
    const short APPEAR_FUNCTION_RUNE = 15;
    const short APPEAR_NORMAL_RUNE = 85;
    //等級合成機率
    const short MAKE_UP_LV_TWO = 80;
    const short MAKE_UP_LV_THREE = 60;
    const short DEBUFF = 75;
    const short BUFF = 85;
    const short HEAL = 100; 
} 

namespace mpConsume
{
    const short NORMAL_RUNE_ONE = 3; //使用一個攻擊符文
    const short FUNCTION_RUNE = 6; //使用功能符文
    const short MAKE_UP_LV_TWO = 6; //合成兩個符文
    const short MAKE_UP_LV_THREE = 10; //合成三個符文
}

enum class Rune : short
{
    FLAME = 1,
    AQUA,
    VITALITY,
    
    HEAL,
    DEBUFF,
    BUFF
};

class RuneBag
{
private:
    std::vector<short> runes;
    std::vector<Pair> selectedRunes;
    short runesCNT;
    bool isSelected[MAX_RUNE_COUNT]{false};
public:
    RuneBag(); //init 
    ~RuneBag(){};
    void runeGet(); //每回合隨機給予符文
    bool runeSelect(short index); //回傳選取是否有效
    void use();
};

#endif