#include "battle.h"


Battle::Battle(Player* player, Enemy* enemy)
    : player(player), enemy(enemy)
{
    gameFlag = gameLoopFlag::PLAYER_BATTLE; //戰鬥中

}

Battle::~Battle()
{
    enemy = nullptr;
    player = nullptr;
}

void Battle::init()
{
    player->startGameValueSet(); //玩家的點數血量
    player->; //玩家符文初始化
    //使用者介面，畫圖
    
    //玩家
    




}

void Battle::close()
{


}

void Battle::gameLoop() //結束條件：玩家死掉、玩家退出
{
    init(); //戰鬥開始 //輸出提示 Chooseing session
    while ( true )
    {
        if ( gameFlag == gameLoopFlag::PLAYER_BATTLE ) { //如果在戰鬥中
            playerTime();
            //敵人死未
            //敵人回合
            //玩家死未
            //更新回合
        } 

    }
    return;
}

std::string Battle::receiveCommand()
{
    std::string input;
    ani::setPos(BATTLE::POS::COMMAND_LINE); //設定輸入位置
    ani::curserShow(true); //開啟游標

    std::getline(std::cin,input);

    ani::curserShow(false); //關閉游標
    return input;
}

void Battle::playerTime()
{
    double atkRate = 1.0;
    RuneEffect effect = RuneEffect::NONE;
    while ( true )
    {
        //提示輸入模式
        //清除message
        //ani::runMessage(,,);
        //符文重設
        //choosing session 更新現在模式
        //設定使用者Command
        std::string input = receiveCommand(); //接收指令
        input = toSmall(input); //轉小寫
        //清除使用者的痕跡
        if ( input == BATTLE::Command::USE ) { //進入使用模式
            if ( useMode(atkRate,effect) ) { //如果使用成功則進入下一關
                break;
            } else { //使用失敗，請重新來過
                continue;
            }
        } else if ( input == BATTLE::Command::BUY ) {//進入購買模式
            player->myRunes->buyRune(player->runePoint);
            continue;
        } else if ( input == BATTLE::Command::SELL ) { //進入選賣
            sellMode();
            continue;
        } else if ( input == BATTLE::Command::QUIT ) { //你不能放棄
            //清除message
            //輸出
            continue;
        } else if ( input == BATTLE::Command::SKIP ) {
            //輸出你跳過這回合
            return; //到敵人的回合
        } else { //輸入錯誤
            //清除message
            //輸出
            continue;
        }
    }
    switch ( effect )
    {
    case RuneEffect:: :
        /* code */
        break;
    
    default:
        break;
    }
    //結算傷害
    
    //輸出訊息
    //更新效果
    //更新血量
    return;
}

bool Battle::useMode(double& atkRate,RuneEffect& effect)
{
    //清除message
    //輸出
    while ( true )
    {
        //重設符文包
        //接收指令
        std::string input = receiveCommand();
        input = toSmall(input); //轉小寫
        //清除玩家使用痕跡
        if ( input == BATTLE::Command::QUIT ) { //回到選擇模式
            player->myRunes->selectReset(); //重置選擇
            return false;
        }
        if ( input == BATTLE::Command::USE ) { //玩家確定要使用符文
            if ( player->myRunes->use(atkRate,effect) ) { 
                //if  使用成功
                    //傳出訊息
                //if 使用失敗 
                    //傳出訊息
                //更新符文
                return true;
            } else {
                //回報錯誤
                player->myRunes->selectReset();
                return false;
            }
        }
        
        player->myRunes->runeSelectToUse(strToShort(input)); //選擇符文

    }
    return false;
}


void Battle::sellMode()
{
    //清除 message
    while ( true )
    {
        //重設符文包
        //接收指令
        std::string input = receiveCommand();
        input = toSmall(input); //轉小寫
        //清除玩家使用痕跡
        if ( input == BATTLE::Command::QUIT ) { //回到選擇模式
            player->myRunes->selectReset(); //重置選擇
            return;
        }        
        if ( input == BATTLE::Command::SELL ) { //如果要賣的話
            player->myRunes->sell(player->runePoint);
            //輸出訊息
            //更新玩家符文點數
            return;
        }
        if ( player->myRunes->runeSelectToSell(strToShort(input)) ) { //選擇成功
            //選擇什麼，目前可以賣多少
            continue;
        } else { //選擇失敗
            //你人生失敗   
            continue;
        }
    }
    return;
}