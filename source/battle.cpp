#include "battle.h"


Battle::Battle(Player* player, Enemy* enemy)
    : player(player), enemy(enemy)
{
    gameFlag = gameLoopFlag::BATTLE; //戰鬥中
    command[Command::ATTACK] = Activity::ATTACK; //攻擊
    command[Command::QUIT] = Activity::QUIT; //退出
    command[Command::DEFENSE] = Activity::DEFENSE; //防禦
    command[Command::CHARGE] = Activity::CHARGE; //充能
    command[Command::RETURN] = Activity::RETURN; //反彈
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
    while ( gameFlag == gameLoopFlag::BATTLE ) {
        action(receiveCommand());
        if ( gameFlag == gameLoopFlag::QUIT ) {
            std::cout << "fuckyou\n";
            return;
        }
        if ( gameFlag == gameLoopFlag::PLAYER_LOSE ) {
            std::cout << "PLAYER LOSE\n";
            return;
        }
        if ( gameFlag == gameLoopFlag::PLAYER_WIN) {
            std::cout << "YOU WIN\n";
        }
    }
}

int Battle::receiveCommand()
{
    bool commandIsFound = false;
    std::string input;
    std::map<const std::string,int>::iterator it;

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


int Battle::action(int action)
{
    switch (action)
    {
    case Activity::ATTACK:
        playerAttack();
        break;
    case Activity::DEFENSE:
        playerDefense();
        break;
    case Activity::CHARGE:
        playerCharge();
        break;
    case Activity::RETURN:
        playerReturn();
        break;
    case Activity::QUIT:
        gameFlag = gameLoopFlag::QUIT;
        break;
    default:
        std::cout  << "oho ho jojo simthing went ronnn\n";
        break;
    }
    return 0;
}