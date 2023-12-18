#include "rune.h"
#include "def.h"

short randomRune()
{
    short random_num = rand() % 300 + 1;
    if(random_num <= odd::APPEAR_NORMAL_RUNE*3){
        return random_num%3 + 1; 
    }
    else{
        return random_num%3 + 4;
    }
    
}

RuneBag::RuneBag()
{
    isFunction = false;
    attackType = 0;
    functionType = 0;
    selectedNum = 0;
    for( int i = 0; i < MAX_RUNE_COUNT; i++)
        isSelected[i] = false;
    runes.clear();
    for(int i = 0; i < 4; i++)
        randomRunes[i] = 0;
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

bool RuneBag::runeSelectToUse(short index)
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
            return true;
        }

        if( (runes[index-1] >= 1 && runes[index-1] <= 3) && selectedNum == 1 ){
            selectedNum--;
            isSelected[index-1] = false;
            attackType = 0;
            return true;
        }

        if( (runes[index-1] >= 1 && runes[index-1] <= 3) && selectedNum > 1 ){
            selectedNum--;
            isSelected[index-1] = false;
            return true;
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
            return true;
        }
        return false; // 選擇功能牌時在第三張
    }
    
    if( runes[index-1] >= 1 && runes[index-1] <= 3 ){ // 選擇一般牌
        if(isFunction && selectedNum == 1){ // 選完功能牌後選擇一般牌
            isSelected[index-1] = true;
            attackType = runes[index-1];
            selectedNum++;
            return true;
        }

        if( !isFunction ){ // 尚未選擇功能牌
            if(selectedNum == 0){ // 第一張一般牌
                isSelected[index-1] = true;
                selectedNum++;
                attackType = runes[index-1];
                return true;
            }

            if(runes[index-1] == attackType && selectedNum <= 2){ // 多張一般牌
                isSelected[index-1] = true;
                selectedNum++;
                return true;
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
                        effect = FLAMEHEAL;
                    }
                    else if(attackType == 2){
                        attackRate = 0;
                        effect = AQUAHEAL;
                    }
                    else if(attackType == 3){
                        attackRate = 0;
                        effect = VITALITYHEAL;
                    }
                    break;
                case BUFF:
                    if(attackType == 1){
                        attackRate = 0;
                        effect = FLAMEBUFF;
                    }
                    else if(attackType == 2){
                        attackRate = 0;
                        effect = AQUABUFF;
                    }
                    else if(attackType == 3){
                        attackRate = 0;
                        effect = VITALITYBUFF;
                    }
                    break;
                case DEBUFF:
                    if(attackType == 1){
                        attackRate = 0;
                        effect = FLAMEDEBUFF;
                    }
                    else if(attackType == 2){
                        attackRate = 0;
                        effect = AQUADEBUFF;
                    }
                    else if(attackType == 3){
                        attackRate = 0;
                        effect = VITALITYDEBUFF;
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
                        effect = FLAMENORMAL;
                    }
                    else if(selectedNum == 2){
                        attackRate = 1.6;
                        effect = FLAMENORMAL;
                    }
                    else if(selectedNum == 3){
                        attackRate = 2.5;
                        effect = FLAMEATTACK;
                    }
                    break;
                case AQUA:
                    if(selectedNum == 1){
                        attackRate = 1;
                        effect = AQUANORMAL;
                    }
                    else if(selectedNum == 2){
                        attackRate = 1.6;
                        effect = AQUANORMAL;
                    }
                    else if(selectedNum == 3){
                        attackRate = 2.5;
                        effect = AQUAATTACK;
                    }
                    break;
                case VITALITY:
                    if(selectedNum == 1){
                        attackRate = 1;
                        effect = VITALITYNORMAL;
                    }
                    else if(selectedNum == 2){
                        attackRate = 1.6;
                        effect = VITALITYNORMAL;
                    }
                    else if(selectedNum == 3){
                        attackRate = 2.5;
                        effect = VITALITYATTACK;
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

bool RuneBag::runeSelectToSell(short index){
    if ( index < 1 || index > 8 ) //選取要合理
        return false;
    if ( index > runes.size() ) {
        return false; //不合理，選取超過數量
    }
    
    if ( isSelected[index-1] ) { //已經被選取
        isSelected[index-1] = false; //取消選取
        return true;
    }

    if( !isSelected[index-1] ){
        isSelected[index-1] = true; //紀錄已經選取
        return true;
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
    runePoint -= RUNE_PER_COST;    //減掉符文點數
    runes.push_back(randomRune());  //隨機購入一個符文
    return true;
}

//選取重置，所有取消選取
void RuneBag::selectReset()
{
    selectedNum = 0;
    for ( int i = 0; i < MAX_RUNE_COUNT; i++ )
        isSelected[i] = false;  //將所有的符文標記為未選取
    return;
}