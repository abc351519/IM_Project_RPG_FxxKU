#include "battle.h"


Battle::Battle(Player* player, Enemy* enemy)
    : player(player), enemy(enemy)
{
    gameFlag = gameLoopFlag::PLAYER_BATTLE; //戰鬥中
    
}

Battle::~Battle()
{
    player = nullptr;
}

void Battle::init()
{




}

void Battle::close()
{


}

void Battle::gameLoop() //結束條件：玩家死掉、玩家退出
{
    while ( gameFlag == gameLoopFlag::PLAYER_BATTLE ) {
        action(receiveCommand());
        if ( gameFlag == gameLoopFlag::PLAYER_QUIT) {
            std::cout << "fuckyou\n";
            return;
        }
            if ( gameFlag == gameLoopFlag::PLAYER_LOSE ) {
            std::cout << "PLAYER LOSE\n";
            return;
        }
        if ( gameFlag == gameLoopFlag::PLAYER_WIN) {
            std::cout << "YOU WIN\n";
            return;
        }
    }
}

Activity Battle::receiveCommand()
{
    bool commandIsFound = false;
    std::string input;
    std::map<const std::string,Activity>::iterator it;

    while (!commandIsFound) //還沒接收到指令
    {       
        std::cout << "Type command: ";//定位 ewjfihiqehwg   ani::setPos();
        std::getline(std::cin,input); //玩家輸入指令
    
        //清除螢幕上輸入
    
        it = command.find(input); //在指令集中尋找該指令
        if ( it == command.end() ) //如果沒找到的話
        {
            //定位
            std::cout << BATTLE::MESSAGE::WRONG_COMMAND << '\n';//輸出錯誤訊息
        } else {
            commandIsFound = true; //回傳接收到有效的指令
        }
    }
    return command[input];
}


int Battle::action(Activity action)
{

    return 0;
}