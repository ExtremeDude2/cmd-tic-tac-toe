/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

#include <iostream>

using namespace std;

// 0 = none, 1 = X, 2 = O, 3 = draw
extern unsigned short NW, N, NE, W, CEN, E, SW, S, SE;

// This function draws the board and any X's or O's
void draw_board()
{
	if (NW == 1 && N == 0 && NE == 0)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (NW == 0 && N == 1 && NE == 0)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (NW == 0 && N == 0 && NE == 1)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (NW == 1 && N == 1 && NE == 0)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (NW == 0 && N == 1 && NE == 1)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (NW == 1 && N == 0 && NE == 1)
	{
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (NW == 1 && N == 1 && NE == 1)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (NW == 2 && N == 0 && NE == 0)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (NW == 0 && N == 2 && NE == 0)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (NW == 0 && N == 0 && NE == 2)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (NW == 2 && N == 2 && NE == 0)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (NW == 0 && N == 2 && NE == 2)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (NW == 2 && N == 0 && NE == 2)
	{
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (NW == 2 && N == 2 && NE == 2)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (NW == 1 && N == 2 && NE == 2)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (NW == 1 && N == 2 && NE == 0)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (NW == 1 && N == 1 && NE == 2)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (NW == 1 && N == 2 && NE == 1)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (NW == 0 && N == 1 && NE == 2)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (NW == 0 && N == 2 && NE == 1)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (NW == 1 && N == 0 && NE == 2)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (NW == 2 && N == 1 && NE == 2)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (NW == 2 && N == 0 && NE == 1)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (NW == 2 && N == 2 && NE == 1)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (NW == 2 && N == 1 && NE == 0)
	{
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (NW == 2 && N == 1 && NE == 1)
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
	if (W == 1 && CEN == 0 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 1 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 0 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 1 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 1 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 0 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 1 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 0 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 2 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 0 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 2 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 2 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 0 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 2 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 2 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 2 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 1 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 2 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 1 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 0 && CEN == 2 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 1 && CEN == 0 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 1 && E == 2)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 0 && E == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && N == 2 && NE == 1)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 1 && E == 0)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (W == 2 && CEN == 1 && E == 1)
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
	if (SW == 1 && S == 0 && SE == 0)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (SW == 0 && S == 1 && SE == 0)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (SW == 0 && S == 0 && SE == 1)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (SW == 1 && S == 1 && SE == 0)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (SW == 0 && S == 1 && SE == 1)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (NW == 1 && N == 0 && NE == 1)
	{
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (SW == 1 && S == 1 && SE == 1)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (SW == 2 && S == 0 && SE == 0)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (SW == 0 && S == 2 && SE == 0)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (SW == 0 && S == 0 && SE == 2)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (SW == 2 && S == 2 && SE == 0)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (SW == 0 && S == 2 && SE == 2)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (NW == 2 && N == 0 && NE == 2)
	{
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (SW == 2 && S == 2 && SE == 2)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (SW == 1 && S == 2 && SE == 2)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (SW == 1 && S == 2 && SE == 0)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (SW == 1 && S == 1 && SE == 2)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (SW == 1 && S == 2 && SE == 1)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (SW == 0 && S == 1 && SE == 2)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (SW == 0 && S == 2 && SE == 1)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (SW == 1 && S == 0 && SE == 2)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (SW == 2 && S == 1 && SE == 2)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (SW == 2 && S == 0 && SE == 1)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (SW == 2 && S == 2 && SE == 1)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (SW == 2 && N == 1 && SE == 0)
	{
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (SW == 2 && S == 1 && SE == 1)
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