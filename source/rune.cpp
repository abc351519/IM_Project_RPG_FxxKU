#include "rune.h"
#include "def.h"

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <random>
#include <cmath>

short odds::rand()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed); 
    return abs(static_cast<short>(generator()/std::numeric_limits<short>::max()));
}

short randomRune()
{
    
    short random_num = odds::rand() % 300 + 1;
    if(random_num <= odds::APPEAR_NORMAL_RUNE*3){
        return random_num%3 + 1; //1 - 3
    }
    else{
        return random_num%3 + 4; //4 - 6
    }
    
}

bool makeUpLevelTwoRate(){
    short random_num = odds::rand() % 300 + 1;
    if(random_num <= odds::MAKE_UP_LV_TWO*3){
        return true; 
    }
    else{
        return false;
    }
}

bool makeUpLevelThreeRate(){
    short random_num = odds::rand() % 300 + 1;
    if(random_num <= odds::MAKE_UP_LV_THREE*3){
        return true; 
    }
    else{
        return false;
    }
}

bool buffRate(){
    short random_num = odds::rand() % 300 + 1;
    if(random_num <= odds::BUFF*3){
        return true; 
    }
    else{
        return false;
    }
}

bool debuffRate(){
    short random_num = odds::rand() % 300 + 1;
    if(random_num <= odds::DEBUFF*3){
        return true; 
    }
    else{
        return false;
    }
}

RuneBag::RuneBag()
{
    isFunction = false;
    attackType = 0;
    functionType = 0;
    selectedNum = 0;
    for( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;
    runes.clear();
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
    return;
}

short RuneBag::runeSelectToUse(short index)
{
    if ( index < 1 || index > 8 ) //選取要合理
        return false;

    if ( index > runes.size() ) {
        return false; //不合理，選曲超過數量
    }
    
    if ( isSelected[index-1] ) { //已經被選取
        if(runes[index-1] >= 4 && runes[index-1] <= 6){
            isFunction = false;
            functionType = 0;
            selectedNum--;
            isSelected[index-1] = false;
            return  index;
        }

        if( (runes[index-1] >= 1 && runes[index-1] <= 3) && selectedNum == 1 ){
            selectedNum--;
            isSelected[index-1] = false;
            attackType = 0;
            return  index;
        }

        if( (runes[index-1] >= 1 && runes[index-1] <= 3) && selectedNum > 1 ){
            selectedNum--;
            isSelected[index-1] = false;
            return  index;
        }
    } 
    
    if( runes[index-1] >= 4 && runes[index-1] <= 6 ){ // 選擇功能牌
        if(isFunction) // 重複選擇功能牌
            return false;
    
        if( !isFunction && selectedNum <= 1 ){ // 選擇功能牌，轉為功能
            isFunction = true;
            functionType = runes[index-1];
            isSelected[index - 1] = true;
            selectedNum++;
            return  index;
        }
        return false; // 選擇功能牌時在第三張
    }
    
    if( runes[index-1] >= 1 && runes[index-1] <= 3 ){ // 選擇一般牌
        if(isFunction && selectedNum == 1){ // 選完功能牌後選擇一般牌
            isSelected[index-1] = true;
            attackType = runes[index-1];
            selectedNum++;
            return  index;
        }

        if( !isFunction ){ // 尚未選擇功能牌
            if(selectedNum == 0){ // 第一張一般牌
                isSelected[index-1] = true;
                selectedNum++;
                attackType = runes[index-1];
                return  index;
            }

            if(runes[index-1] == attackType && selectedNum <= 2){ // 多張一般牌
                isSelected[index-1] = true;
                selectedNum++;
                return  index;
            }
        }
        return false;
    }

    return false;
}

bool RuneBag::use(double& attackRate, RuneEffect& effect)
{   
    if((isFunction && selectedNum == 1) || (selectedNum == 0))
        return false;
    else{
        if(isFunction && selectedNum == 2){
            switch(functionType)
            {
                case HEAL:
                    if(attackType == 1){
                        attackRate = 0;
                        effect = RuneEffect::FLAMEHEAL;
                    }
                    else if(attackType == 2){
                        attackRate = 0;
                        effect = RuneEffect::AQUAHEAL;
                    }
                    else if(attackType == 3){
                        attackRate = 0;
                        effect = RuneEffect::VITALITYHEAL;
                    }
                    break;
                case BUFF:
                    if(attackType == 1){
                        if(buffRate()){
                            attackRate = 0;
                            effect = RuneEffect::FLAMEBUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(attackType == 2){
                        if(buffRate()){
                            attackRate = 0;
                            effect = RuneEffect::AQUABUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(attackType == 3){
                        if(buffRate()){
                            attackRate = 0;
                            effect = RuneEffect::VITALITYBUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    break;
                case DEBUFF:
                    if(attackType == 1){
                        if(debuffRate()){
                            attackRate = 0;
                            effect = RuneEffect::FLAMEDEBUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(attackType == 2){
                        if(debuffRate()){
                            attackRate = 0;
                            effect = RuneEffect::AQUADEBUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(attackType == 3){
                        if(debuffRate()){
                            attackRate = 0;
                            effect = RuneEffect::VITALITYDEBUFF;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    break;
            }
        }
        else if (!isFunction && selectedNum >= 1){
            switch (attackType)
            {
                case FLAME:
                    if(selectedNum == 1){
                        attackRate = 1;
                        effect = RuneEffect::FLAMENORMAL;
                    }
                    else if(selectedNum == 2){
                        if(makeUpLevelTwoRate()){
                            attackRate = 1.6;
                            effect = RuneEffect::FLAMENORMAL;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(selectedNum == 3){
                        if(makeUpLevelThreeRate()){
                            attackRate = 2.5;
                            effect = RuneEffect::FLAMEATTACK;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    break;
                case AQUA:
                    if(selectedNum == 1){
                        attackRate = 1;
                        effect = RuneEffect::AQUANORMAL;
                    }
                    else if(selectedNum == 2){
                        if(makeUpLevelTwoRate()){
                            attackRate = 1.6;
                            effect = RuneEffect::AQUANORMAL;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(selectedNum == 3){
                        if(makeUpLevelThreeRate()){
                            attackRate = 2.5;
                            effect = RuneEffect::AQUAATTACK;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    break;
                case VITALITY:
                    if(selectedNum == 1){
                        attackRate = 1;
                        effect = RuneEffect::VITALITYNORMAL;
                    }
                    else if(selectedNum == 2){
                        if(makeUpLevelTwoRate()){
                            attackRate = 1.6;
                            effect = RuneEffect::VITALITYNORMAL;
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    else if(selectedNum == 3){
                        if(makeUpLevelThreeRate()){
                            attackRate = 2.5;
                            effect = RuneEffect::VITALITYATTACK;   
                        }
                        else{
                            attackRate = 0;
                            effect = RuneEffect::USELESS;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        for ( int i = runes.size() - 1; i >= 0; i-- )
            if ( isSelected[i] ){
                runes.erase( runes.begin()+i );
            }
        
        for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
            isSelected[i] = false;
        
        attackType = 0;
        functionType = 0;
        selectedNum = 0;
        return true;
    }
}

short RuneBag::runeSelectToSell(short index){
    if ( index < 1 || index > 8 ) //選取要合理
        return false;
    if ( index > runes.size() ) {
        return false; //不合理，選取超過數量
    }
    
    if ( isSelected[index-1] ) { //已經被選取
        isSelected[index-1] = false; //取消選取
        return index;
    }

    if( !isSelected[index-1] ){
        isSelected[index-1] = true; //紀錄已經選取
        return index;
    }
    
    return false;
}

bool RuneBag::sell(short& runePoints){
    short sellPoints = 0;
    for ( int i = runes.size() - 1; i >= 0; i-- )
        if ( isSelected[i] ){
            if( runes[i] >= 1 && runes[i] <= 3 ){
                sellPoints += RUNE_SOLD_NORMAL_EARN;
                runes.erase( runes.begin()+i );
            }
            else if( runes[i] >= 4 && runes[i] <= 6 ){
                sellPoints += RUNE_SOLD_FUNCTION_EARN;
                runes.erase( runes.begin()+i );
            }
        }
            
    for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;
    
    runePoints += sellPoints;
    return true;
}

bool RuneBag::buyRune(short& runePoint)
{
    if ( runes.size() >= MAX_RUNE_COUNT )   //如果符文數量接近限制
        return false;
    if ( runePoint < RUNE_PER_COST )//如果點數不夠
        return false;
    if ( runePoint >= RUNE_PER_COST ) {
        runePoint -= RUNE_PER_COST;    //減掉符文點數
        runes.push_back(randomRune());  //隨機購入一個符文
        return true;
    }
    return false;
}

//選取重置，所有取消選取
void RuneBag::selectReset()
{
    selectedNum = 0;
    for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;  //將所有的符文標記為未選取
    return;
}

short RuneBag::getRuneCount()
{   
    return static_cast<short>(runes.size());
}

short RuneBag::getRune(short index)
{
    if ( index < static_cast<short>(runes.size()) && index >=0 )
        return runes[index];
    return -69;
}

bool RuneBag::isRuneSelected(short index)
{
    return isSelected[index];
}