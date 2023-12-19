#include "graph.h"
#include "battle.h"

Picture BATTLE::ICON::RUNE_AQUA_ICON(5,3);
Picture BATTLE::ICON::RUNE_FLAME_ICON(5,3);
Picture BATTLE::ICON::RUNE_VITALITY_ICON(5,3);
Picture BATTLE::ICON::RUNE_HEAL_ICON(5,3);
Picture BATTLE::ICON::RUNE_BUFF_ICON(5,3);
Picture BATTLE::ICON::RUNE_DEBUFF_ICON(5,3);
Picture BATTLE::ICON::RUNE_FRAME(7,5);
Picture BATTLE::ICON::RUNE_FRAME_SELECTED(7,5);
Picture BATTLE::ICON::RUNE_FRAME_DISSELECTED(7,5);
void graph::init()
{
    ///////////////////////////AQUA RUNE 圖形（水滴形）/////////////////////////
    Pixel pixel(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_AQUA_STONE);
    BATTLE::ICON::RUNE_AQUA_ICON.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[2][0] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[3][1] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[2][2] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[4][1] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[1][2] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[3][2] = pixel;
    
    pixel.change(unicode::DOWN_PIXEL);
    BATTLE::ICON::RUNE_AQUA_ICON.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[3][0] = pixel;
    
    pixel.change(unicode::UP_PIXEL);
    BATTLE::ICON::RUNE_AQUA_ICON.graph[0][2] = pixel;    
    BATTLE::ICON::RUNE_AQUA_ICON.graph[4][2] = pixel;

    pixel.change(unicode::RUNE_AQUA_SYMBOL,ansi_color::background::RUNE_AQUA_STONE,ansi_color::font::RUNE_AQUA_SYMBOL);
    BATTLE::ICON::RUNE_AQUA_ICON.graph[2][1] = pixel;
    
    pixel.change(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_AQUA_ICON.graph[0][0] = pixel;
    BATTLE::ICON::RUNE_AQUA_ICON.graph[4][0] = pixel;
    ///////////////////////FLAME RUNE圖形（火焰形）////////////////////
    pixel.change(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_FLAME_STONE);
    
    
    BATTLE::ICON::RUNE_FLAME_ICON.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_FLAME_ICON.graph[3][1] = pixel;
    BATTLE::ICON::RUNE_FLAME_ICON.graph[4][1] = pixel;
    
    pixel.changeFontColor(ansi_color::font::RUNE_FLAME_STONE_DARK);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[0][1] = pixel;

    pixel.changeFontColor(ansi_color::font::RUNE_FLAME_STONE);
    pixel.change(unicode::CORNER_PIXEL_NORU);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[4][0] = pixel;    
    BATTLE::ICON::RUNE_FLAME_ICON.graph[2][0] = pixel;

    pixel.changeFontColor(ansi_color::font::RUNE_FLAME_STONE_DARK);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[0][0] = pixel;

    pixel.changeFontColor(ansi_color::font::RUNE_FLAME_STONE);
    pixel.change(unicode::DOWN_PIXEL_1_8);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_FLAME_ICON.graph[3][0] = pixel;
    
    pixel.change(unicode::CORNER_PIXEL_NOLD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_FLAME_STONE_DARK);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[0][2] = pixel;    
    pixel.change(unicode::CORNER_PIXEL_NORD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_FLAME_STONE);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[4][2] = pixel;

    pixel.change(unicode::RUNE_FLAME_SYMBOL,ansi_color::background::RUNE_FLAME_STONE,ansi_color::font::RUNE_FLAME_SYMBOL);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[2][1] = pixel;
    
    pixel.change(unicode::DOWN_PIXEL,ansi_color::background::RUNE_FLAME_STONE,ansi_color::font::RUNE_FLAME_STONE_DARK);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[2][2] = pixel;
    BATTLE::ICON::RUNE_FLAME_ICON.graph[3][2] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORU);
    BATTLE::ICON::RUNE_FLAME_ICON.graph[1][2] = pixel;

    ///////////////////////VITALITY RUNE圖形（火焰形）////////////////////
    ///////////////////////HEAL RUNE圖形（）////////////////////
    pixel.change(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_WHITE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[0][3] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[1][4] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[2][1] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[2][3] = pixel;

    pixel.change(unicode::CORNER_PIXEL_NOLU,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_WHITE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[0][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_WHITE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[2][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_WHITE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[2][4] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORU,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_WHITE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[0][4] = pixel;

    pixel.change(unicode::FULL_PIXEL,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNE_HEAL_STONE);
    BATTLE::ICON::RUNE_HEAL_ICON.graph[0][2] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[1][2] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[1][3] = pixel;
    BATTLE::ICON::RUNE_HEAL_ICON.graph[2][2] = pixel;

    ///////////////////////BUFF RUNE圖形（火焰形）////////////////////
    ///////////////////////DEBUFF RUNE圖形（火焰形）////////////////////

    ///////////////////////////RUNE FRAME 圖形（框）/////////////////////////
    pixel.change(unicode::CORNER_PIXEL_NORD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME);
    BATTLE::ICON::RUNE_FRAME.graph[0][0] = pixel;
    pixel.change(unicode::L_PIXEL_4_8);
    BATTLE::ICON::RUNE_FRAME.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[0][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[0][3] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORU);
    BATTLE::ICON::RUNE_FRAME.graph[0][4] = pixel;
    pixel.change(unicode::DOWN_PIXEL_6_8,ansi_color::background::RUNEBAG_FRAME,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_DARK);
    BATTLE::ICON::RUNE_FRAME.graph[6][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLU);
    BATTLE::ICON::RUNE_FRAME.graph[6][4] = pixel;
    pixel.change(unicode::L_PIXEL_4_8,ansi_color::background::RUNEBAG_FRAME_DARK,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME.graph[6][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[6][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[6][3] = pixel;
    pixel.change(unicode::DOWN_PIXEL_2_8,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_DARK);
    BATTLE::ICON::RUNE_FRAME.graph[1][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][4] = pixel;
    pixel.change(unicode::DOWN_PIXEL_2_8,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME.graph[1][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[1][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[1][3] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][3] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][3] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][3] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][3] = pixel;
     ///////////////////////////RUNE FRAME SELECTED  圖形（選取框）/////////////////////////
    pixel.change(unicode::CORNER_PIXEL_NORD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_SELECTED);
    BATTLE::ICON::RUNE_FRAME.graph[0][0] = pixel;
    pixel.change(unicode::L_PIXEL_4_8);
    BATTLE::ICON::RUNE_FRAME.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[0][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[0][3] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORU);
    BATTLE::ICON::RUNE_FRAME.graph[0][4] = pixel;
    pixel.change(unicode::DOWN_PIXEL_6_8,ansi_color::background::RUNEBAG_FRAME_SELECTED,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][0] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_SELECTED_DARK);
    BATTLE::ICON::RUNE_FRAME.graph[6][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLU);
    BATTLE::ICON::RUNE_FRAME.graph[6][4] = pixel;
    pixel.change(unicode::L_PIXEL_4_8,ansi_color::background::RUNEBAG_FRAME_SELECTED_DARK,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME.graph[6][1] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[6][2] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[6][3] = pixel;
    pixel.change(unicode::DOWN_PIXEL_2_8,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_SELECTED_DARK);
    BATTLE::ICON::RUNE_FRAME.graph[1][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[2][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[3][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[4][4] = pixel;
    BATTLE::ICON::RUNE_FRAME.graph[5][4] = pixel;
    ///////////////////////////RUNE FRAME 圖形（取消選取框）/////////////////////////
    pixel.change(unicode::CORNER_PIXEL_NORD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[0][0] = pixel;
    pixel.change(unicode::L_PIXEL_4_8);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[0][1] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[0][2] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[0][3] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NORU);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[0][4] = pixel;
    pixel.change(unicode::DOWN_PIXEL_6_8,ansi_color::background::RUNEBAG_FRAME,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[1][0] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[2][0] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[3][0] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[4][0] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[5][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLD,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_DARK);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[6][0] = pixel;
    pixel.change(unicode::CORNER_PIXEL_NOLU);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[6][4] = pixel;
    pixel.change(unicode::L_PIXEL_4_8,ansi_color::background::RUNEBAG_FRAME_DARK,ansi_color::font::RUNEBAG_BACKGROUND);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[6][1] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[6][2] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[6][3] = pixel;
    pixel.change(unicode::DOWN_PIXEL_2_8,ansi_color::background::RUNEBAG_BACKGROUND,ansi_color::font::RUNEBAG_FRAME_DARK);
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[1][4] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[2][4] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[3][4] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[4][4] = pixel;
    BATTLE::ICON::RUNE_FRAME_DISSELECTED.graph[5][4] = pixel;

    return;
}