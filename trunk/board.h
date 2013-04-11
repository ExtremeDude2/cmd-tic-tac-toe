#include <iostream>

using namespace std;

// 0 = none, 1 = X, 2 = O, 3 = draw
short NW = 0, N = 0, NE = 0, W = 0, CEN = 0, E = 0, SW = 0, S = 0, SE = 0,
	turn = 0, game = 0, x_win = 0, o_win = 0, draw = 0, playing = 1, place = 0, players = 0;

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
	else if (NW == 2 && N == 0 && NE == 0)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else
	{
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
	}
	if (false){}
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
	if (false){}
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