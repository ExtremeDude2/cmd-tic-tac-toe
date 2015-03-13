/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

/*
To do list:
Fix cross platform compatibility (started)
Optimize horible code (use arrays instead of positions?)
make CPU // No time D;
Try to make UI // Nooooooooooooooooooooooooooooo, it won't work D;
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "board.h"

using namespace std;

// 0 = none, 1 = X, 2 = O, 3 = tie
unsigned short NW = 0, N = 0, NE = 0, W = 0, CEN = 0, E = 0, SW = 0, S = 0, SE = 0,
	turn = 0, game = 0, x_win = 0, o_win = 0, tie = 0, playing = 1, place = 0, players = 0, error = 0;

// This function is CPU X's logic
void CPU_X()
{
	// Temp use of rand
	SYSTEMTIME time;
	GetLocalTime(&time);
	int ran = time.wMilliseconds;
	srand(ran);
	place = (rand() % 9) + 1;
}

// This function is CPU O's logic
void CPU_O()
{
	// Temp use of rand
	SYSTEMTIME time;
	GetLocalTime(&time);
	int ran = time.wMilliseconds;
	srand(ran);
	place = (rand() % 9) + 1;
}

// This function is used to determine whos turn it is
unsigned short player_turn()
{
	return (turn % 2) + 1;
}

// This function resets all of the places and clears the screen
void reset()
{
	NW = N = NE = W = CEN = E = SW = S = SE = turn = place = error = 0;
	system("cls");
}

// This function checks to see if anyone has won or if there is a tie
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
		&& ((E == 1) || (E == 2)) && ((SE == 1) || (SE == 2)) && ((S == 1) || (S == 2))
		&& ((SW == 1) || (SW == 2)) && ((W == 1) || (W == 2)) && ((CEN == 1) || (CEN == 2)) || turn >= 9)
	{
		return 3;
	}
	return 0;
}

// This function is used when 2 CPU's play against each other
void CPU2()
{
try_CPU2:
	if (player_turn() == 1)
	{
		cout << "X(CPU)'s turn" << endl;
		CPU_X();
	}
	else if (player_turn() == 2)
	{
		cout << "O(CPU)'s turn" << endl;
		CPU_O();
	}
	else
	{
		cout << "Error, unknown turn" << endl;
		error++;
	}
	if (place == 1)
	{
		if (!NW)
			NW = player_turn();
		else
		{
			// Don't worry about outputing an error if the CPU is moving as it it random and is bound to do so
			// cout << "Error, cannot move there. Please try again" << endl << endl;
			goto try_CPU2; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!N)
			N = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 3)
	{
		if (!NE)
			NE = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 4)
	{
		if (!W)
			W = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 5)
	{
		if (!CEN)
			CEN = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 6)
	{
		if (!E)
			E = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 7)
	{
		if (!SW)
			SW = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 8)
	{
		if (!S)
			S = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 9)
	{
		if (!SE)
			SE = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else
	{
		cout << "Error, incorect place. Please try again" << endl << endl;
		error++;
		goto try_CPU2;
	}
	draw_board();
	turn++;
}

// This function is used when 1 player is against 1 CPU
void CPU()
{
try_CPU:
	if (player_turn() == 1)
	{
		cout << "X's turn" << endl;
		cout << endl << "Please select where you would like to go, options include:" << endl;
		cout << "Nort West (1), North (2), North East (3), West (4), Center (5)," << endl;
		cout <<	"East (6), South West (7), South (8), South East (9): ";
		cin >> place;
		cout << endl;
	}
	else if (player_turn() == 2)
	{
		cout << "O(CPU)'s turn" << endl;
		CPU_O();
	}
	else
		cout << "Error, unknown turn" << endl;
	if (place == 1)
	{
		if (!NW)
			NW = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!N)
			N = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 3)
	{
		if (!NE)
			NE = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 4)
	{
		if (!W)
			W = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 5)
	{
		if (!CEN)
			CEN = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 6)
	{
		if (!E)
			E = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 7)
	{
		if (!SW)
			SW = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 8)
	{
		if (!S)
			S = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 9)
	{
		if (!SE)
			SE = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else
	{
		cout << "Error, incorect place. Please try again" << endl << endl;
		error++;
		goto try_CPU;
	}
	draw_board();
	turn++;
}

// This function is used when 2 people play against each other
void person()
{
try_person:
	if (player_turn() == 1)
		cout << "X's turn" << endl;
	else if (player_turn() == 2)
		cout << "O's turn" << endl;
	else
	{
		cout << "Error, unknown turn" << endl;
		error++;
	}
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
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!N)
			N = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 3)
	{
		if (!NE)
			NE = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 4)
	{
		if (!W)
			W = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 5)
	{
		if (!CEN)
			CEN = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 6)
	{
		if (!E)
			E = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 7)
	{
		if (!SW)
			SW = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 8)
	{
		if (!S)
			S = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 9)
	{
		if (!SE)
			SE = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else
	{
		cout << "Error, incorect place. Please try again" << endl << endl;
		error++;
		goto try_person;
	}
	draw_board();
	turn++;
}

int main()
{
start:
	// Ask the user how many human players there are (if any)
	cout << "Would you like to play with 0 (2 CPUs), 1 (1 CPU), or 2 players? (switching number of players mid-game requires a restart)" << endl;
	cout << "Note: All CPUs are very fast and you will likely not see them move." << endl;
	cin >> players;
	system("cls");
	while (playing)
	{
		if (players == 0)
			CPU2();
		else if (players == 1)
			CPU();
		else if (players == 2)
			person();
		else
		{
			cout << "Error, do not know how many people/CPU's are playing. Please try again." << endl;
			error++;
			goto start;
		}
		place = 0;
		if (check_status())
		{
			system("cls");
			cout << "SCOREBOARD:" << endl;
			if (check_status() == 1)
			{
				cout << endl << "X wins! It was done in " << turn << " turns." << endl << endl;
				x_win++;
			}
			else if (check_status() == 2)
			{
				cout << endl << "O wins! It was done in " << turn << " turns." << endl << endl;
				o_win++;
			}
			else if (check_status() == 3)
			{
				cout << endl << "Tie, no one wins." << endl << endl;
				tie++;
			}
			else
			{
				cout << "Error, unknown winner. Going back to start" << endl << endl;
				error++;
				goto start;
			}
			game++;
			draw_board();
			cout << endl << "Out of " << game << " game(s) played " << "X has " << x_win << " win(s), O has "
				<< o_win << " win(s) and there have been " << tie << " tie(s)." << endl << endl
				<< "A total number of " << error << " errors have occurred this turn from moving in an incorect places or for some other reason."
				<< endl << "Would you like to play again? (1 = yes, 0 = no): ";
			cin >> playing;
			reset();
		}
	}
}