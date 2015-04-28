/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

#include <stdio.h>

#define GRID_COMPLEXITY     3
#define GRID_DIMENSIONS     2

#if (GRID_DIMENSIONS == 1)
#define GRID_SIZE       (GRID_COMPLEXITY)
#elif (GRID_DIMENSIONS == 2)
#define GRID_SIZE       ((GRID_COMPLEXITY)*(GRID_COMPLEXITY))
#elif (GRID_DIMENSIONS == 3)
#define GRID_SIZE       ((GRID_COMPLEXITY)*(GRID_COMPLEXITY)*(GRID_COMPLEXITY))
#else
#error https://www.youtube.com/watch?v=oIJ4APeqpeY
#endif

#define NUM_PLAYERS     2

enum {
    TOP,
    MID,
    LOW
};

enum {
    LFT,
    CNT,
    RGT
};

/*
 * u nub11!1  y u counting from 1 to 9 instead of 0 to 8?!
 */
#define BASE            1

#define TOP_LEFT        ((GRID_COMPLEXITY)*(TOP) + (LFT) + (BASE))
#define TOP_CENTER      ((GRID_COMPLEXITY)*(TOP) + (CNT) + (BASE))
#define TOP_RIGHT       ((GRID_COMPLEXITY)*(TOP) + (RGT) + (BASE))

#define MID_LEFT        ((GRID_COMPLEXITY)*(MID) + (LFT) + (BASE))
#define MID_CENTER      ((GRID_COMPLEXITY)*(MID) + (CNT) + (BASE))
#define MID_RIGHT       ((GRID_COMPLEXITY)*(MID) + (RGT) + (BASE))

#define LOW_LEFT        ((GRID_COMPLEXITY)*(LOW) + (LFT) + (BASE))
#define LOW_CENTER      ((GRID_COMPLEXITY)*(LOW) + (CNT) + (BASE))
#define LOW_RIGHT       ((GRID_COMPLEXITY)*(LOW) + (RGT) + (BASE))

enum {
    BLANK,
    SET_X = 1 << 0,
    SET_O = 1 << 1
};

#define PLAYING     0
#define WIN_X       (SET_X)
#define WIN_O       (SET_O)
#define DRAW        63

extern unsigned short grid[GRID_COMPLEXITY][GRID_COMPLEXITY];

extern void draw_row(unsigned short * row);

// This function draws the board and any X's or O's
void draw_board()
{
    draw_row(grid[TOP]);
    puts("---------+---------+---------");
    draw_row(grid[MID]);
    puts("---------+---------+---------");
    draw_row(grid[LOW]);
    putchar('\n');
    return;
}

void draw_row(unsigned short * row)
{
    if (row[LFT] == SET_X && row[CNT] == BLANK && row[RGT] == BLANK)
    {
        puts("  X   X  |         |         ");
        puts("   X X   |         |         ");
        puts("    X    |         |         ");
        puts("   X X   |         |         ");
        puts("  X   X  |         |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_X && row[RGT] == BLANK)
    {
        puts("         |  X   X  |         ");
        puts("         |   X X   |         ");
        puts("         |    X    |         ");
        puts("         |   X X   |         ");
        puts("         |  X   X  |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == BLANK && row[RGT] == SET_X)
    {
        puts("         |         |  X   X  ");
        puts("         |         |   X X   ");
        puts("         |         |    X    ");
        puts("         |         |   X X   ");
        puts("         |         |  X   X  ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_X && row[RGT] == BLANK)
    {
        puts("  X   X  |  X   X  |         ");
        puts("   X X   |   X X   |         ");
        puts("    X    |    X    |         ");
        puts("   X X   |   X X   |         ");
        puts("  X   X  |  X   X  |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_X && row[RGT] == SET_X)
    {
        puts("         |  X   X  |  X   X  ");
        puts("         |   X X   |   X X   ");
        puts("         |    X    |    X    ");
        puts("         |   X X   |   X X   ");
        puts("         |  X   X  |  X   X  ");
    }
    else if (row[LFT] == SET_X && row[CNT] == BLANK && row[RGT] == SET_X)
    {
        puts("  X   X  |         |  X   X  ");
        puts("   X X   |         |   X X   ");
        puts("    X    |         |    X    ");
        puts("   X X   |         |   X X   ");
        puts("  X   X  |         |  X   X  ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_X && row[RGT] == SET_X)
    {
        puts("  X   X  |  X   X  |  X   X  ");
        puts("   X X   |   X X   |   X X   ");
        puts("    X    |    X    |    X    ");
        puts("   X X   |   X X   |   X X   ");
        puts("  X   X  |  X   X  |  X   X  ");
    }
    else if (row[LFT] == SET_O && row[CNT] == BLANK && row[RGT] == BLANK)
    {
        puts("   OOO   |         |         ");
        puts("  O   O  |         |         ");
        puts("  O   O  |         |         ");
        puts("  O   O  |         |         ");
        puts("   OOO   |         |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_O && row[RGT] == BLANK)
    {
        puts("         |   OOO   |         ");
        puts("         |  O   O  |         ");
        puts("         |  O   O  |         ");
        puts("         |  O   O  |         ");
        puts("         |   OOO   |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == BLANK && row[RGT] == SET_O)
    {
        puts("         |         |   OOO   ");
        puts("         |         |  O   O  ");
        puts("         |         |  O   O  ");
        puts("         |         |  O   O  ");
        puts("         |         |   OOO   ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_O && row[RGT] == BLANK)
    {
        puts("   OOO   |   OOO   |         ");
        puts("  O   O  |  O   O  |         ");
        puts("  O   O  |  O   O  |         ");
        puts("  O   O  |  O   O  |         ");
        puts("   OOO   |   OOO   |         ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_O && row[RGT] == SET_O)
    {
        puts("         |   OOO   |   OOO   ");
        puts("         |  O   O  |  O   O  ");
        puts("         |  O   O  |  O   O  ");
        puts("         |  O   O  |  O   O  ");
        puts("         |   OOO   |   OOO   ");
    }
    else if (row[LFT] == SET_O && row[CNT] == BLANK && row[RGT] == SET_O)
    {
        puts("   OOO   |         |   OOO   ");
        puts("  O   O  |         |  O   O  ");
        puts("  O   O  |         |  O   O  ");
        puts("  O   O  |         |  O   O  ");
        puts("   OOO   |         |   OOO   ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_O && row[RGT] == SET_O)
    {
        puts("   OOO   |   OOO   |   OOO   ");
        puts("  O   O  |  O   O  |  O   O  ");
        puts("  O   O  |  O   O  |  O   O  ");
        puts("  O   O  |  O   O  |  O   O  ");
        puts("   OOO   |   OOO   |   OOO   ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_O && row[RGT] == SET_O)
    {
        puts("  X   X  |   OOO   |   OOO   ");
        puts("   X X   |  O   O  |  O   O  ");
        puts("    X    |  O   O  |  O   O  ");
        puts("   X X   |  O   O  |  O   O  ");
        puts("  X   X  |   OOO   |   OOO   ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_O && row[RGT] == BLANK)
    {
        puts("  X   X  |   OOO   |         ");
        puts("   X X   |  O   O  |         ");
        puts("    X    |  O   O  |         ");
        puts("   X X   |  O   O  |         ");
        puts("  X   X  |   OOO   |         ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_X && row[RGT] == SET_O)
    {
        puts("  X   X  |  X   X  |   OOO   ");
        puts("   X X   |   X X   |  O   O  ");
        puts("    X    |    X    |  O   O  ");
        puts("   X X   |   X X   |  O   O  ");
        puts("  X   X  |  X   X  |   OOO   ");
    }
    else if (row[LFT] == SET_X && row[CNT] == SET_O && row[RGT] == SET_X)
    {
        puts("  X   X  |   OOO   |  X   X  ");
        puts("   X X   |  O   O  |   X X   ");
        puts("    X    |  O   O  |    X    ");
        puts("   X X   |  O   O  |   X X   ");
        puts("  X   X  |   OOO   |  X   X  ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_X && row[RGT] == SET_O)
    {
        puts("         |  X   X  |   OOO   ");
        puts("         |   X X   |  O   O  ");
        puts("         |    X    |  O   O  ");
        puts("         |   X X   |  O   O  ");
        puts("         |  X   X  |   OOO   ");
    }
    else if (row[LFT] == BLANK && row[CNT] == SET_O && row[RGT] == SET_X)
    {
        puts("         |   OOO   |  X   X  ");
        puts("         |  O   O  |   X X   ");
        puts("         |  O   O  |    X    ");
        puts("         |  O   O  |   X X   ");
        puts("         |   OOO   |  X   X  ");
    }
    else if (row[LFT] == SET_X && row[CNT] == BLANK && row[RGT] == SET_O)
    {
        puts("  X   X  |         |   OOO   ");
        puts("   X X   |         |  O   O  ");
        puts("    X    |         |  O   O  ");
        puts("   X X   |         |  O   O  ");
        puts("  X   X  |         |   OOO   ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_X && row[RGT] == SET_O)
    {
        puts("   OOO   |  X   X  |   OOO   ");
        puts("  O   O  |   X X   |  O   O  ");
        puts("  O   O  |    X    |  O   O  ");
        puts("  O   O  |   X X   |  O   O  ");
        puts("   OOO   |  X   X  |   OOO   ");
    }
    else if (row[LFT] == SET_O && row[CNT] == BLANK && row[RGT] == SET_X)
    {
        puts("   OOO   |         |  X   X  ");
        puts("  O   O  |         |   X X   ");
        puts("  O   O  |         |    X    ");
        puts("  O   O  |         |   X X   ");
        puts("   OOO   |         |  X   X  ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_O && row[RGT] == SET_X)
    {
        puts("   OOO   |   OOO   |  X   X  ");
        puts("  O   O  |  O   O  |   X X   ");
        puts("  O   O  |  O   O  |    X    ");
        puts("  O   O  |  O   O  |   X X   ");
        puts("   OOO   |   OOO   |  X   X  ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_X && row[RGT] == BLANK)
    {
        puts("   OOO   |  X   X  |         ");
        puts("  O   O  |   X X   |         ");
        puts("  O   O  |    X    |         ");
        puts("  O   O  |   X X   |         ");
        puts("   OOO   |  X   X  |         ");
    }
    else if (row[LFT] == SET_O && row[CNT] == SET_X && row[RGT] == SET_X)
    {
        puts("   OOO   |  X   X  |  X   X  ");
        puts("  O   O  |   X X   |   X X   ");
        puts("  O   O  |    X    |    X    ");
        puts("  O   O  |   X X   |   X X   ");
        puts("   OOO   |  X   X  |  X   X  ");
    }
    else
    {
        puts("         |         |         ");
        puts("         |         |         ");
        puts("         |         |         ");
        puts("         |         |         ");
        puts("         |         |         ");
    }
    return;
}
