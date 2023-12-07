#ifndef BATTLE_H
#define BATTLE_H

#include "event.h"
#include "enemy.h"

namespace BATTLE{
    namespace POS{
        const Position COMMAND_LINE= {0,0};
    };
    namespace MESSAGE{
        const std::string WRONG_COMMAND = "u r typing the wrong command.";
    };
};

enum gameLoopFlag{
    PLAYER_LOSE,
    PLAYER_WIN,
    QUIT,
    BATTLE,
};

class Area;
class Player;

class Battle : public Event
{
private:
    Player* player;
    Enemy* enemy;
    Area** areas;

    void playerAttack()
    {
        if ( !player->getCanAttack() ) { //如果玩家不能攻擊
            std::cout << "你不能攻擊\n";
            return;
        }
        switch (enemy->startAction())
        {
        case 0:
            std::cout << "敵人攻擊\n";
            player->lossHp(enemy->getAtt()-player->getDef());
            if ( !player->getIsAlive() ) {
                gameFlag = gameLoopFlag::PLAYER_LOSE;
                return;
            }
            std::cout << "玩家攻擊\n";
            enemy->lossHp(player->getAtt()-enemy->getDef());
            if ( !enemy->getIsAlive() ) {
                gameFlag = gameLoopFlag::PLAYER_WIN;
                return;
            }
            break;
        case 1:
            std::cout << "敵人防禦\n";
            std::cout << "玩家進攻\n";
            enemy->lossHp((player->getAtt()-enemy->getDef())/10);
            if ( !enemy->getIsAlive() ) { //如果敵人死掉的話
                gameFlag = gameLoopFlag::PLAYER_WIN;
                return;
            }
            break;
        //case /*大招*/:
            /*我不知道*/
          //  break;
        default:
            break;
        }
    }
    void playerDefense()
    { 
        if ( !player->getCanDefend() ) { //如果玩家不能防禦
            std::cout << "你不能防禦";
            return; //回到遊戲迴圈
        }
        switch ( enemy->startAction() )
        {
        case 0:
            std::cout << "玩家防禦\n";
            std::cout << "敵人攻擊\n";
            player->lossHp((enemy->getAtt()-player->getDef())/10);
            if ( !player->getIsAlive() ) {
                gameFlag = gameLoopFlag::PLAYER_LOSE;
                return;
            }
            break;
        case 1:
            std::cout << "玩家防禦\n";
            std::cout << "敵人防禦\n";
            std::cout << "笑死\n";
            player->defendFail();
            break;
        //case /*大招*/:
            /*我不知道*/
          //  break;
        default:
            break;
        }
    }
    void playerCharge()
    {
        switch (enemy->startAction())
        {
        case 0:
            std::cout << "敵人攻擊\n";
            player->lossHp(enemy->getAtt()-player->getDef());
            if ( !player->getIsAlive() ) {
                gameFlag = gameLoopFlag::PLAYER_LOSE;
                return;
            }
            std::cout << "玩家充能\n";
            player->charge();
            break;
        case 1:
            std::cout << "敵人防禦\n";
            std::cout << "玩家充能\n";
            player->charge();
            break;
        default:
            break;
        }
    }
    void playerReturn()
    {
        switch (enemy->startAction())
        {
        case 0:
            std::cout << "敵人攻擊\n";
            std::cout << "玩家反彈\n";
            enemy->lossHp(enemy->getAtt()*2);
            if ( !enemy->getIsAlive() ) { //如果敵人死掉的話
                gameFlag = gameLoopFlag::PLAYER_WIN;
                return;
            }
            break;
        case 1:
            std::cout << "敵人防禦\n";
            std::cout << "玩家反彈\n";
            std::cout << "玩家反彈失敗，接受懲罰\n";
            //調整玩家狀態
        default:
            break;
        }
    }
public:
    static short gameFlag;
    Battle(Player* player, Enemy* enemy);
    ~Battle();
    void init() override; //開啟活動
    void close() override; //關閉活動
    void gameLoop() override; //遊戲循環
    int receiveCommand() override; //輸入指令
    int action(int action) override;
};

#endif