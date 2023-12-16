#include "rune.h"
#include <random>

static short firstChosenType;

short randomRune() //隨機生成一個符文
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<short> dist(1,300);
    short random_num = dist(gen);   
    if ( random_num <= odds::APPEAR_NORMAL_RUNE*3 ) {
        return random_num%3+1; //1-3 ：一般符文
    } else {
        return random_num%3+4; //4-6 ：功能符文
    }
}

RuneBag::RuneBag()
{
    for ( int i = 0; i < INIT_RUNE_COUNT; i++ )
    {
        runes.push_back(randomRune());
    }
}

void RuneBag::runeGet() //每回合拿到符文
{
    for ( int i = 0; i < RUNE_GET_ROUNDLY; i++ )
    {
        runes.push_back(randomRune()); //隨機分配一個符文
    }
}

bool RuneBag::runeSelectToUse(short index)
{
    if ( index < 1 || index > 8 ) //選取要合理
        return false;
    if ( index > runes.size() ) {
        return false; //不合理，選曲超過數量
    }
    
    if ( isSelected[index-1] ) { //已經被選取
        for ( int i = 0 ; i < selectedRunes.size(); i++ )
        {
            if ( selectedRunes[i].index = index-1 ) {
                selectedRunes.erase(selectedRunes.begin()+i); //刪除掉此元素
                break;
            }
        }
        isSelected[index-1] = false; //取消選取
        return true;
    } 
    if ( selectedRunes.empty() ) { //如果是第一次選
        Pair chosenRune{index-1,runes[index-1]};
        selectedRunes.push_back(chosenRune); //加入選取
        isSelected[index-1] = true; //紀錄已經選取
        firstChosenType = runes[index-1]; //紀錄第一個選取的類型
        return true;
    }
    
    if ( runes[index-1] >= 4 && runes[index-1] <= 6 ) { //選到的符文是功能牌
        if ( firstChosenType >= 4 && firstChosenType <= 6 ) { //你不能選兩個功能牌
            return false;
        }
        if ( selectedRunes.size() == 1 )  { //如果先前選取了元素牌而且只選一張
            Pair chosenRune{index-1,runes[index-1]};
            selectedRunes.push_back(chosenRune);
            isSelected[index-1] = true;
            return true;
        }
        return false; 
    }
    //選到一般牌
    if ( runes[index-1] == firstChosenType && selectedRunes.size() < 3  ) { //選到類型一樣
        Pair chosenRune{index-1,runes[index-1]};
        selectedRunes.push_back(chosenRune);
        isSelected[index-1] = true;
        return true;
    }
    return false;
}

void RuneBag::use()
{
    for ( int i = runes.size() - 1; i >= 0; i-- )
        if ( isSelected[i] )
            runes.erase( runes.begin()+i );
    for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;
    //do st for selected
    //更新符文數量
    return;
}

bool RuneBag::buyRune(short& runePoint)
{
    if ( runes.size() >= MAX_RUNE_COUNT )   //如果符文數量接近限制
        return false;
    if ( runePoint < RUNE_PER_COST )//如果點數不夠
        return false;
    runePoint -= RUNE_PER_COST;     //減掉符文點數
    runes.push_back(randomRune());  //隨機購入一個符文
    return true;
}

//選取重置，所有取消選取
void RuneBag::selectReset()
{
    for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;  //將所有的符文標記為未選取
    selectedRunes.clear();      //清除選取的符文
    return;
}