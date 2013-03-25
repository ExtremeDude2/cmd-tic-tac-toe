/*
To do list:

use system("cls");
count wins for each player
make CPU
be able to chose X or O when playing CPU?
count number of games
count number of turns
*/

#include <iostream>
// #include <iomanip>, may or may not need this

using namespace std;

// 0 = none, 1 = X, 2 = O, 3 = draw
unsigned short NW = 0, N = 0, NE = 0, W = 0, CEN = 0, E = 0, SW = 0, S = 0, SE = 0,
	turn = 0, game = 0, x_win = 0, o_win = 0, draw = 0, playing = 1, place = 0, players = 0;

void draw_board()
{
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "----------+----------+----------" << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "----------+----------+----------" << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << "          |          |          " << endl;
	cout << endl;
}

bool game_playing(int playing)
{
	if (playing)
		return true;
	else if (!playing)
		return false;
	return true;
}

unsigned short player_turn()
{
	if (turn == 0 || turn == 2 || turn == 4 || turn == 6 || turn == 8)
		return 1;
	if (turn == 1 || turn == 3 || turn == 5 || turn == 7)
		return 2;
	return 0;
}

void reset()
{
	NW = N = NE = W = CEN = E = SW = S = SE = turn = place = 0;
	system("cls");
}

unsigned short check_status()
{
	if (((NW == 1) && (N == 1) && (NE == 1)) || ((W == 1 && E == 1 && CEN == 1))
		|| ((SW == 1) && (S == 1) && (SE == 1)) || ((NW == 1) && (W == 1) && (SW == 1))
		|| ((N == 1) && (S == 1) && (CEN == 1)) || ((NE == 1) && (E == 1) && (SE == 1))
		|| ((NW == 1) && (SE == 1) && (CEN == 1)) || ((NE == 1) && (SW == 1) && (CEN == 1)))
	{
		return 1;
	}
	if (((NW == 2) && (N == 2) && (NE == 2)) || ((W == 2) && (E == 2) && (CEN == 2))
		|| ((SW == 2) && (S == 2) && (SE == 2)) || ((NW == 2) && (W == 2) && (SW == 2))
		|| ((N == 2) && (S == 2) && (CEN == 2)) || ((NE == 2) && (E == 2) && (SE == 2))
		|| ((NW == 2) && (SE == 2) && (CEN == 2)) || ((NE == 2) && (SW == 2) && (CEN == 2)))
	{
		return 2;
	}
	if (((NW == 1) || (NW == 2)) && ((N == 1) || (N == 2)) && ((NE == 1) || (NE == 2))
		&& ((E == 1) || (E == 2)) && ((SE == 1) || (SE == 2)) && ((S == 1) || (SE == 2))
		&& ((SW == 1) || (SW == 2)) && ((W == 1) || (W == 2)) && ((CEN == 1) || (CEN == 2)) || turn > 8)
	{
		return 3;
	}
	return 0;
}

void CPU2()
{
	if (player_turn() == 1)
	{
try_CPU2:
		cout << "X(CPU)'s turn" << endl;
		if (place == 1)
		{
			if (!NW)
				NW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		}
		else if (place == 2)
		{
			if (!N)
				N = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		}
		else if (place == 3)
			if (!NE)
				NE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 4)
			if (!W)
				W = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 5)
			if (!CEN)
				CEN = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 6)
			if (!E)
				E = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 7)
			if (!SW)
				SW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 8)
			if (!S)
				S = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 9)
			if (!SE)
				SE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else
		{
			cout << "Error incorect place, try again" << endl << endl;
			goto try_CPU2;
		}
	}
	else if (player_turn() == 2)
	{
		cout << "O(CPU)'s turn" << endl;
		if (place == 1)
		{
			if (!NW)
				NW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		}
		else if (place == 2)
		{
			if (!N)
				N = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		}
		else if (place == 3)
			if (!NE)
				NE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 4)
			if (!W)
				W = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 5)
			if (!CEN)
				CEN = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 6)
			if (!E)
				E = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 7)
			if (!SW)
				SW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 8)
			if (!S)
				S = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else if (place == 9)
			if (!SE)
				SE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU2;
			}
		else
		{
			cout << "Error incorect place, try again" << endl << endl;
			goto try_CPU2;
		}
	}
	else
		cout << "Unknown turn" << endl;
	draw_board();
	turn++;
}

void CPU()
{
	if (player_turn() == 1)
	{
try_CPU:
		cout << "X's turn" << endl;
		cout << endl << "Please select where you would like to go, options include:" << endl;
		cout << "Nort West (1), North (2), North East (3), West (4), Center (5)," << endl;
		cout <<	"East (6), South West (7), South (8), South East (9): ";
		cin >> place;
		cout << endl;
		if (place == 1)
		{
			if (!NW)
				NW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		}
		else if (place == 2)
		{
			if (!N)
				N = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		}
		else if (place == 3)
			if (!NE)
				NE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 4)
			if (!W)
				W = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 5)
			if (!CEN)
				CEN = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 6)
			if (!E)
				E = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 7)
			if (!SW)
				SW = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 8)
			if (!S)
				S = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else if (place == 9)
			if (!SE)
				SE = player_turn();
			else
			{
				cout << "Error cannot move there, try again" << endl << endl;
				goto try_CPU;
			}
		else
		{
			cout << "Error incorect place, try again" << endl << endl;
			goto try_CPU;
		}
	}
	else if (player_turn() == 2)
		cout << "O(CPU)'s turn" << endl;
	else
		cout << "Unknown turn" << endl;
	draw_board();
	turn++;
}

void person()
{
try_person:
	if (player_turn() == 1)
		cout << "X's turn" << endl;
	else if (player_turn() == 2)
		cout << "O's turn" << endl;
	else
		cout << "Unknown turn" << endl;
	cout << endl << "Please select where you would like to go, options include:" << endl;
	cout << "Nort West (1), North (2), North East (3), West (4), Center (5)," << endl;
	cout <<	"East (6), South West (7), South (8), South East (9): ";
	cin >> place;
	cout << endl;
	if (place == 1)
	{
		if (!NW)
			NW = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	}
	else if (place == 2)
	{
		if (!N)
			N = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	}
	else if (place == 3)
		if (!NE)
			NE = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 4)
		if (!W)
			W = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 5)
		if (!CEN)
			CEN = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 6)
		if (!E)
			E = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 7)
		if (!SW)
			SW = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 8)
		if (!S)
			S = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else if (place == 9)
		if (!SE)
			SE = player_turn();
		else
		{
			cout << "Error cannot move there, try again" << endl << endl;
			goto try_person;
		}
	else
	{
		cout << "Error incorect place, try again" << endl << endl;
		goto try_person;
	}
	draw_board();
	turn++;
}

int main()
{
	cout << "Would you like to play with 1 player or 2?" << endl;
	cout << "(switching number of players requires a restart): ";
	cin >> players;
	if (players > 2)
		cout << "Error, invalid number of players";
	system("cls");
	while (game_playing(playing))
	{
		if (players == 0)
			CPU2();
		else if (players == 1)
			CPU();
		else if (players == 2)
			person();
		if (check_status())
		{
			system("cls");
			cout << "SCOREBOARD:" << endl;
			if (check_status() == 1)
			{
				cout << endl << "X wins!" << endl << endl;
				x_win++;
			}
			else if (check_status() == 2)
			{
				cout << endl << "O wins!" << endl << endl;
				o_win++;
			}
			else if (check_status() == 3)
			{
				cout << endl << "Draw, no one wins" << endl << endl;
				draw++;
			}
			else
				cout << "Error unknown winner" << endl << endl;
			game++;
			draw_board();
			cout << endl << "Out of " << game << " game(s) played " << "X has " << x_win << " win(s), O has "
				<< o_win << " win(s) and there have been " << draw << " draw(s)." << endl;
			cout << endl << "Would you like to play again? (1 = yes, 0 = no): ";
			cin >> playing;
			reset();
		}
	}
}