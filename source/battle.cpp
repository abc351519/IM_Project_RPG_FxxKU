#include "battle.h"
#include "thread"
#include <cmath>

void Battle::loadMode(const std::string& opt)
{
    mtx.lock();
    std::cout << ansi_color::background::RUNEBAG_FRAME_DARK << ansi_color::font::RUNEBAG_FRAME;
    Position pos(BATTLE::POS::RUNE_POINT);
    pos.x += 7*8-1;
    ani::setPos(pos);
    ani::moveCurse(CurserMove::MOVELEFT,12);
    for ( int i = 0; i < 13; i++ )
        std::cout << ' ';
    if ( opt == "use" ) {
        std::string use = "USE";
        pos.x -= use.length();
        ani::setPos(pos);
        std::cout << use;
    } else if ( opt == "sell" ) {
        std::string sell = "SELL";
        pos.x -= sell.length();
        ani::setPos(pos);
        std::cout << sell;
    } else {
        std::string battle = "In Battle";
        pos.x -= battle.length();
        ani::setPos(pos);
        std::cout << battle;
    }
    std::cout << RESET;
    mtx.unlock();
    return;
}

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

    ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,ani::RUNEBAG_RUN_TIME);
    ani::setPos(BATTLE::POS::RUNE_POINT);
    std::cout << ansi_color::background::RUNEBAG_FRAME << ansi_color::font::RUNEBAG_FRAME_DARK << " Rune Point:   ";
    std::cout <<RESET;
    changeRunePoint(0,ani::RUNE_POINT_RUN_TIME);

    loadPromptMessage("You find a " + enemy->name + "; use your runes to beat it.");

    return;
}

void Battle::close()
{
    player->endBattle();
}

void Battle::gameLoop() //結束條件：玩家死掉、玩家退出
{
    init(); //戰鬥開始 //輸出提示 Chooseing session
    while ( true )
    {
        if ( gameFlag == gameLoopFlag::PLAYER_BATTLE ) { //如果在戰鬥中
            playerTime();
            if ( gameFlag == gameLoopFlag::PLAYER_WIN ) {
                loadPromptMessage(BATTLE::MESSAGE::PLAYER_WIN);
                break;
            }
            enemyTime(); //敵人回合
            if ( gameFlag == gameLoopFlag::PLAYER_LOSE ) {  //玩家死未
                loadPromptMessage(BATTLE::MESSAGE::PLAYER_LOSE);
                break;
            }
            //更新回合
            short originalRunePoint = player -> runePoint;
            player->refreshRoundly(); //玩家更新符文點數
            changeRunePoint(originalRunePoint,ani::RUNE_POINT_RUN_TIME);
        } 
    }
    close();
    return;
}

void Battle::playerTime()
{
    double atkRate = 1.0;
    bool isFirst = true;
    RuneEffect effect = RuneEffect::USELESS;
    Event::loadPromptFrame(RESET);
    while ( true )
    {
        ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,0);
        
        if ( isFirst ) {
            isFirst = false;
            loadPromptMessage(BATTLE::MESSAGE::CHOOSING_SESSION); //提示輸入模式
            updateRune(ani::RUNE_SHOW_TIME);
        } else {
            updateRune(0);
            loadPromptMessage(BATTLE::MESSAGE::CHOOSING_SESSION); //提示輸入模式
        }
        loadMode("");
        std::string input = receiveCommand(); //接收指令
        input = toSmall(input); //轉小寫
        cleanCommandLine();  //清除使用者的痕跡
        if ( input == BATTLE::Command::USE ) { //進入使用模式
            loadMode("use");
            if ( useMode(atkRate,effect) ) { //如果使用成功則進入下一關
                loadMode("");
                break;
            } else { //使用失敗，請重新來過
                loadMode("");
                continue;
            }
        } else if ( input == BATTLE::Command::BUY ) {//進入購買模式
            short originPoint = player->runePoint;
            if ( player->myRunes->buyRune(player->runePoint) ) {
                updateRune(0);  //更新符文
                changeRunePoint(originPoint,1000); //更新點數
                loadPromptMessage(BATTLE::MESSAGE::BUY_RUNE_SUCCESS);
            }
            continue;
        } else if ( input == BATTLE::Command::SELL ) { //進入選賣
            loadMode("sell");
            sellMode();
            continue;
        }
        else if ( input == BATTLE::Command::QUIT ) { //你不能放棄
            loadPromptMessage(BATTLE::MESSAGE::ESCAPE_TRYING);
            continue;
        } else if ( input == BATTLE::Command::SKIP ) {
            loadPromptMessage("You skip this round, now it's " + enemy->name + "'s turn.");
            return; //到敵人的回合
        } else { //輸入錯誤
            loadPromptMessage(BATTLE::MESSAGE::INPUT_ERROR);
            continue;
        }
    }
    switch ( effect ) //結算傷害 ， 增加效果
    {
    case RuneEffect::AQUAATTACK:
    
    case RuneEffect::AQUANORMAL: 
        if ( enemy->element == EnemyElement::FLAME ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::VITALITY ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
        break;
    case RuneEffect::FLAMEATTACK:

    case RuneEffect::FLAMENORMAL:
        if ( enemy->element == EnemyElement::VITALITY ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::AQUA ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
        break;
    case RuneEffect::VITALITYATTACK:

    case RuneEffect::VITALITYNORMAL:
        if ( enemy->element == EnemyElement::AQUA ) { //克制
            atkRate *= BATTLE::atkRateCounter::DOMINANT;
        } else if ( enemy->element == EnemyElement::FLAME ) { //被克制
            atkRate *= BATTLE::atkRateCounter::COUNTERED;
        }
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
    short originalHp = enemy->nowHp;
    bool enemyIsDead = enemy->normalAttackDamageIsDead(static_cast<short>(static_cast<double>(player->atk)*atkRate));
    short hpGap = originalHp - enemy->nowHp;
    ani::numberChange(BATTLE::POS::ENEMY_HP+22,originalHp,enemy->nowHp,ani::HMP_run_time/hpGap,4,RESET); //更新血量（已更新）
    loadPromptMessage("You have made " + std::to_string(hpGap) + " damage to the " + enemy->name + ".");
    if ( enemyIsDead ) { //如果敵人死掉
        gameFlag = gameLoopFlag::PLAYER_WIN; //宣告玩家勝利
        return;
    }
    return;
}

void Battle::enemyTime()
{
    //enemy攻擊
    Skill attackFlag;
    short damage = enemy->attack(attackFlag);
    short originalHp = player->nowHp; //原本的血量
    bool playerIsDead = player->normalAttackDamageIsDead(damage);
    short hpGap = originalHp - player->nowHp;
    if ( attackFlag == Skill::NORMAL ) {
        loadPromptMessage(enemy->name+" has caused "+std::to_string(hpGap)+" damage on "+player->name+".");
    } else if( attackFlag == Skill::DOUBLE_CRITICAL ) {
        loadPromptMessage(enemy->name+" use skill, \"DOUBLE CRITICAL\", cause "+std::to_string(hpGap)+" damage on "+player->name+"!!?");
    } else {
        std::cerr << "SOMTHIN WENT WRONG.";
    }
    ani::numberChange(BATTLE::POS::PLAYER_HP+22,originalHp,player->nowHp,ani::HMP_run_time/hpGap,4,RESET); //更新血量（已更新）
    if ( playerIsDead ) {
        gameFlag = gameLoopFlag::PLAYER_LOSE;
    }
    return;
}

bool Battle::useMode(double& atkRate,RuneEffect& effect)
{
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
            short originRunePoints = player->runePoint;
            if ( player->myRunes->use(atkRate,effect, player->runePoint) ) { 
                if(effect != RuneEffect::USELESS){ //使用成功
                    loadPromptMessage(BATTLE::MESSAGE::USE_SUCCESS);
                    changeRunePoint(originRunePoints, ani::RUNE_POINT_RUN_TIME);
                }
                else if(effect == RuneEffect::USELESS){ //使用失敗
                    loadPromptMessage(BATTLE::MESSAGE::USE_FAILED);
                    changeRunePoint(originRunePoints, ani::RUNE_POINT_RUN_TIME);
                }
                //傳出訊息
                ani::renderRuneFrame(BATTLE::POS::RUNEBAG,BATTLE::ICON::RUNE_FRAME,MAX_RUNE_COUNT,ani::RUNEBAG_RUN_TIME);
                updateRune(ani::RUNE_SHOW_TIME); 
                return true;
            } else {
                //回報錯誤
                switch (player->myRunes->getConditionType())
                {
                case RuneCondition::RuneNotEnough:
                    loadPromptMessage(BATTLE::MESSAGE::RUNE_POINT_NOT_ENOUGH);
                    player->myRunes->selectReset();
                    break;
                
                default:
                    break;
                }
                
                return false;
            }
        }
        short index = player->myRunes->runeSelectToUse(strToShort(input)); //選擇符文
        if ( index ) { // 成功選取
            showRuneSelected(index-1);
            loadPromptMessage(BATTLE::MESSAGE::SELECT_SUCCESS);
        } else { // 未成功選取
            loadPromptMessage(BATTLE::MESSAGE::SELECT_FAIL);
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
            loadPromptMessage("You have sold some runes to get " + std::to_string(player->runePoint-originalCNT) + " Rune Points successfully!!");
            changeRunePoint(originalCNT,ani::RUNE_POINT_RUN_TIME); //更新符文點數
            return;
        }
        short index = player->myRunes->runeSelectToSell(strToShort(input));
        if ( index ) { //選擇成功
            showRuneSelected(index-1); //更新符文選擇
            loadPromptMessage(BATTLE::MESSAGE::SELECT_SUCCESS); 
            continue;
        } else { //選擇失敗
            loadPromptMessage(BATTLE::MESSAGE::SELECT_FAIL); //你人生失敗 訊息輸出
            continue;
        }
    }
    return;
}


// 符文貼上 應該是沒問題了
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
    pos.x += 12;
    ani::numberChange(pos,originalCNT,player->runePoint,time/gap,2,ansi_color::font::RUNEBAG_FRAME_DARK/*RUNE_POINT_COLOR*/+ansi_color::background::RUNEBAG_FRAME);
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
    std::cout << RESET;
    mtx.unlock();
    return;
}

void Battle::cleanCommandLine()
{
    ani::setPos(EVENT::POS::COMMAND_LINE);
    std::cout << RESET;
    for ( int i = 0; i < 77; i++ )
        std::cout << ' ';
    FLUSH;
    return;
}