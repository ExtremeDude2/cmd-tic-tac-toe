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
    SET_X,
    SET_O
};

#define PLAYING     0
#define WIN_X       (SET_X)
#define WIN_O       (SET_O)
#define DRAW        3

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

#define LINES_PER_DRAWING       5
static const char ASCII_drawings[NUM_PLAYERS + 1][LINES_PER_DRAWING][10] = {
    { /* blank space */
        "         ",
        "         ",
        "         ",
        "         ",
        "         ",
    },
    {
        "  X   X  ",
        "   X X   ",
        "    X    ",
        "   X X   ",
        "  X   X  ",
    },
    {
        "   OOO   ",
        "  O   O  ",
        "  O   O  ",
        "  O   O  ",
        "   OOO   ",
    },
};

void draw_row(unsigned short * row)
{
    register int current_line;

    for (current_line = 0; current_line < LINES_PER_DRAWING; current_line++)
    {
        fputs(ASCII_drawings[row[LFT]][current_line], stdout);
        putchar('|');
        fputs(ASCII_drawings[row[CNT]][current_line], stdout);
        putchar('|');
        fputs(ASCII_drawings[row[RGT]][current_line], stdout);
        putchar('\n');
    }
    return;
}
