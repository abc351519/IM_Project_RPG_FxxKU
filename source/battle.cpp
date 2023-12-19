#include "battle.h"
#include "thread"
#include <cmath>

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
    ani::loadWindow(ansi_color::background::BATTLE_COLOR);
    player->startGameValueSet(); //玩家的點數血量
    std::thread pName(ani::runMessage,BATTLE::POS::PLAYER_NAME,player->name,RESET);
    std::thread eName(ani::runMessage,BATTLE::POS::ENEMY_NAME,enemy->name,RESET);
    ani::runMessage(BATTLE::POS::PLAYER_NAME,player->name,RESET);
    std::thread eHp(ani::HPLoading,BATTLE::POS::ENEMY_HP,enemy->maxHp,ansi_color::font::HP);
    std::thread pHp(ani::HPLoading,BATTLE::POS::PLAYER_HP,player->maxHp,ansi_color::font::HP);    
    pName.join();
    eName.join();
    pHp.join();
    eHp.join();

    ani::setPos(BATTLE::POS::ENEMY_LV);
    std::cout << RESET;
    std::cout << "Level:";
    printNiceLy(enemy->lv,2);
    ani::setPos(BATTLE::POS::PLAYER_LV);
    std::cout << "Level:";
    printNiceLy(player->lv,2);
    FLUSH;
    //std::cout << player->maxHp << ' ' << enemy ->maxHp;
    //使用者介面，畫圖

    //玩家
    


    ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,ani::RUNEBAG_RUN_TIME);
    ani::setPos(BATTLE::POS::RUNE_POINT);
    std::cout << "Rune Point:";
    changeRunePoint(0,ani::RUNE_POINT_RUN_TIME);
    return;
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
    mtx.lock();
    std::string input;
    ani::setPos(BATTLE::POS::COMMAND_LINE); //設定輸入位置
    std::cout << ansi_color::font::COMMAND_LINE_COLOR << "Type command here: ";
    ani::curserShow(true); //開啟游標

    std::getline(std::cin,input);
    
    std::cout << RESET;
    FLUSH;

    ani::curserShow(false); //關閉游標
    mtx.unlock();
    return input;
}

void Battle::playerTime()
{
    double atkRate = 1.0;
    bool isFirst = true;
    RuneEffect effect = RuneEffect::USELESS;
    while ( true )
    {
        //提示輸入模式

        //清除message
        //ani::runMessage(,,);
        ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,0);
        if ( isFirst ) {
            isFirst = false;
            updateRune(ani::RUNE_SHOW_TIME);
        } else {
            updateRune(0);
        }
        //choosing session 更新現在模式
        std::string input = receiveCommand(); //接收指令
        input = toSmall(input); //轉小寫
        cleanCommandLine();  //清除使用者的痕跡
        if ( input == BATTLE::Command::USE ) { //進入使用模式
            if ( useMode(atkRate,effect) ) { //如果使用成功則進入下一關
                break;
            } else { //使用失敗，請重新來過
                continue;
            }
        } else if ( input == BATTLE::Command::BUY ) {//進入購買模式
            short originPoint = player->runePoint;
            if ( player->myRunes->buyRune(player->runePoint) ) {
                updateRune(0);  //更新符文
                changeRunePoint(originPoint,1000); //更新點數
            }
            continue;
        } else if ( input == BATTLE::Command::SELL ) { //進入選賣
            sellMode();
            continue;
        }
        else if ( input == BATTLE::Command::QUIT ) { //你不能放棄
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
    short originHp = player->nowHp;
    switch ( effect ) //結算傷害 ， 增加效果
    {
    case RuneEffect::AQUANORMAL:
        if ( enemy->element == EnemyElement::FLAME ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::VITALITY ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
        enemy->normalAttackDamage(static_cast<short>(static_cast<double>(player->atk)*atkRate));
        break;
    case RuneEffect::FLAMENORMAL:
        if ( enemy->element == EnemyElement::VITALITY ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::AQUA ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
        enemy->normalAttackDamage(static_cast<short>(static_cast<double>(player->atk)*atkRate));
        break;
    case RuneEffect::VITALITYNORMAL:
        if ( enemy->element == EnemyElement::AQUA ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::FLAME ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
        enemy->normalAttackDamage(static_cast<short>(static_cast<double>(player->atk)*atkRate));
        break;/*
    case RuneEffect:::
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;
    case RuneEffect::VITALITYATTACK:
        break;*/
    default:
        break;
    }
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
        std::string input = receiveCommand(); //接收指令
        input = toSmall(input); //轉小寫
        cleanCommandLine();   //清除玩家使用痕跡
        if ( input == BATTLE::Command::QUIT ) { //回到選擇模式
            player->myRunes->selectReset(); //重置選擇
            ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,0);
            updateRune(0);    //更新螢幕顯示
            return false;
        }
        if ( input == BATTLE::Command::USE ) { //玩家確定要使用符文
            if ( player->myRunes->use(atkRate,effect) ) { 
                //if  使用成功
                    //傳出訊息
                //if 使用失敗 
                    //傳出訊息
                ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,ani::RUNEBAG_RUN_TIME);
                updateRune(ani::RUNE_SHOW_TIME); 
                return true;
            } else {
                //回報錯誤
                player->myRunes->selectReset();
                return false;
            }
        }
        
        short index = player->myRunes->runeSelectToUse(strToShort(input)); //選擇符文
        if ( index ) { //成功選取
            showRuneSelected(index-1);
        } else { //為成功選取
            //輸出錯誤
        }

    }
    return false;
}


void Battle::sellMode()
{
    //清除 message
    while ( true )
    {
        std::string input = receiveCommand();  //接收指令
        input = toSmall(input); //轉小寫
        cleanCommandLine();  //清除玩家使用痕跡
        if ( input == BATTLE::Command::QUIT ) { //回到選擇模式
            player->myRunes->selectReset(); //重置選擇
            return;
        }        
        if ( input == BATTLE::Command::SELL ) { //如果要賣的話
            short originalCNT = player->runePoint;
            player->myRunes->sell(player->runePoint);
            //輸出訊息
            changeRunePoint(originalCNT,100); //更新符文點數
            return;
        }
        short index = player->myRunes->runeSelectToSell(strToShort(input));
        if ( index ) { //選擇成功
            showRuneSelected(index-1); //更新符文選擇
            continue;
        } else { //選擇失敗
            //你人生失敗 訊息輸出
            continue;
        }
    }
    return;
}


// 符文貼上
void Battle::updateRune(short time)
{
    Position currentPos = BATTLE::POS::RUNEBAG;
    currentPos.x++;
    currentPos.y++;
    short runeCNT = player->myRunes->getRuneCount();

    for ( short i = 0; i < runeCNT; i++ )
    {
        mtx.lock();
        Picture* graph = nullptr;
        bool toPrint = true;
        switch ( player->myRunes->getRune(i) )
        {
        case 1:
            graph = &BATTLE::ICON::RUNE_FLAME_ICON;
            break;
        case 2:
            graph = &BATTLE::ICON::RUNE_AQUA_ICON;
            break;
        case 3:
            graph = &BATTLE::ICON::RUNE_VITALITY_ICON;
            break;
        case 4:
            graph = &BATTLE::ICON::RUNE_HEAL_ICON;
            break;
        case 5:
            graph = &BATTLE::ICON::RUNE_BUFF_ICON;
            break;
        case 6:
            graph = &BATTLE::ICON::RUNE_DEBUFF_ICON;
            break;
        default:
            graph = nullptr;
            toPrint = false;
            std::cerr << "回傳-69" << player->myRunes->getRune(i) << ' ' << player->myRunes->getRuneCount();
            break;
        }
        if ( toPrint )
            ani::renderGraph(currentPos,*graph);
        FLUSH;
        mtx.unlock();
        currentPos.x += 7;
        SLEEP(time);
    }
    return;
}


void Battle::changeRunePoint(short originalCNT,short time)
{
    Position pos(BATTLE::POS::RUNE_POINT);
    short gap = abs(originalCNT-player->runePoint);
    pos.x += 11;
    ani::numberChange(pos,originalCNT,player->runePoint,time/gap,2,ansi_color::font::RUNE_POINT_COLOR);
    return;
}

///顯示選取的符文
void Battle::showRuneSelected(short index)
{
    mtx.lock();
    Position pos(BATTLE::POS::RUNEBAG);
    if ( index )
        pos.x += 7*index;
    if ( player->myRunes->isRuneSelected(index) ) { //如果被選了
        ani::renderGraph(pos,BATTLE::ICON::RUNE_FRAME_SELECTED);
        pos.y += 4;
        ani::setPos(pos);
        std::cout << ansi_color::background::RUNEBAG_SELECTED_INDEX << ansi_color::font::RUNEBAG_SELECTED_INDEX << index+1;
    } else
    {
        ani::renderGraph(pos,BATTLE::ICON::RUNE_FRAME_DISSELECTED);
        pos.y += 4;
        ani::setPos(pos);
        std::cout << ansi_color::background::RUNEBAG_INDEX << ansi_color::font::RUNEBAG_INDEX << index+1;
    }
    FLUSH;
    mtx.unlock();
    return;
}


void Battle::cleanCommandLine()
{
    ani::setPos(BATTLE::POS::COMMAND_LINE);
    std::cout << RESET;
    for ( int i = 0; i < 77; i++ )
        std::cout << ' ';
    FLUSH;
    return;
}