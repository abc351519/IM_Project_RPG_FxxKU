#include "graph.h"
#include "battle.h"

Picture BATTLE::ICON::RUNE_ICON(5,3);

void graph::init()
{
    //定義畫圖圖形
    Pixel pixel(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_AQUA_STONE);
    BATTLE::ICON::RUNE_ICON.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[2][0] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[3][1] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[2][2] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[4][1] = pixel;
    pixel.change(unicode::DOWN_PIXEL);
    BATTLE::ICON::RUNE_ICON.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[3][0] = pixel;
    pixel.change(unicode::UP_PIXEL);
    BATTLE::ICON::RUNE_ICON.graph[1][2] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[3][2] = pixel;
    pixel.change(unicode::RUNE_AQUA_SYMBOL,ansi_color::background::RUNE_AQUA_STONE,ansi_color::font::RUNE_AQUA_SYMBOL);
    BATTLE::ICON::RUNE_ICON.graph[2][1] = pixel;
    pixel.change(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_ICON.graph[0][0] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[0][2] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[4][0] = pixel;
    BATTLE::ICON::RUNE_ICON.graph[4][2] = pixel;
}