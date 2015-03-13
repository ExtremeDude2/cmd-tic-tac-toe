/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

#include <iostream>

using namespace std;

#define GRID_SIZE       3

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

// 0 = none, 1 = X, 2 = O, 3 = draw
extern unsigned short grid[GRID_SIZE][GRID_SIZE];

// This function draws the board and any X's or O's
void draw_board()
{
	if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 0)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 0)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 1)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 0)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 1)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 1)
	{
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 1)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 0)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 0)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 2)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 0)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 2)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 2)
	{
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 2)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 2)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 0)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 2)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 1)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 2)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 0 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 1)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 2)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 2)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 0 && grid[TOP][RGT] == 1)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 1)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 0)
	{
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 1)
	{
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
	}
	else
	{
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
	}

	if (grid[MID][LFT] == 1 && grid[MID][CNT] == 0 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 1 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 0 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 1 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 1 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 0 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 1 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 0 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 2 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 0 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 2 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 2 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 0 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 2 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 2 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 2 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 1 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 2 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 1 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 0 && grid[MID][CNT] == 2 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 1 && grid[MID][CNT] == 0 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 1 && grid[MID][RGT] == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 0 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 1)
	{ /* bookmark:  think you got a bug up thar m8! ^ */
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 1 && grid[MID][RGT] == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == 2 && grid[MID][CNT] == 1 && grid[MID][RGT] == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}

	if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 0)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 0)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 1)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 0)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 1)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[TOP][CNT] == 0 && grid[LOW][RGT] == 1)
	{ /* bookmark:  think you got a bug up thar m8! ^ */
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 1)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 0)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 0)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 2)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 0)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 2)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[TOP][CNT] == 0 && grid[LOW][RGT] == 2)
	{ /* bookmark:  think you got a bug up thar m8! ^ */
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 2)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 2)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 0)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 2)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 1)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 2)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 0 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 1)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 2)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 2)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 0 && grid[LOW][RGT] == 1)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 1)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[TOP][CNT] == 1 && grid[LOW][RGT] == 0)
	{ /* bookmark:  think you got a bug up thar m8! ^ */
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 1)
	{
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
	}
	else
	{
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
	}

	cout << endl;
}