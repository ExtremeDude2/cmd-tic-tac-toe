/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

/*
To do list:
Fix cross platform compatibility (started)
Optimize horrible code
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
unsigned short grid[GRID_SIZE][GRID_SIZE];
unsigned short turn = 0, game = 0, x_win = 0, o_win = 0, tie = 0, playing = 1, place = 0, players = 0, error = 0;

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
    int x, y;

    for (y = 0; y < GRID_SIZE; y++)
        for (x = 0; x < GRID_SIZE; x++)
            grid[y][x] = 0;
    turn = place = error = 0;
    system("cls"); /* <-- gay */
}

// This function checks to see if anyone has won or if there is a tie
unsigned short check_status()
{
    unsigned int test;
    int x, y;

/*
 * horizontal tests
 */
    if (grid[TOP][LFT] == 1 && grid[TOP][CNT] == 1 && grid[TOP][RGT] == 1)
        return 1;
    if (grid[MID][LFT] == 1 && grid[MID][CNT] == 1 && grid[MID][RGT] == 1)
        return 1;
    if (grid[LOW][LFT] == 1 && grid[LOW][CNT] == 1 && grid[LOW][RGT] == 1)
        return 1;

/*
 * vertical tests
 */
    if (grid[TOP][LFT] == 1 && grid[MID][LFT] == 1 && grid[LOW][LFT] == 1)
        return 1;
    if (grid[TOP][CNT] == 1 && grid[MID][CNT] == 1 && grid[LOW][CNT] == 1)
        return 1;
    if (grid[TOP][RGT] == 1 && grid[MID][RGT] == 1 && grid[LOW][RGT] == 1)
        return 1;

/*
 * diagonal tests
 */
    if (grid[TOP][LFT] == 1 && grid[MID][CNT] == 1 && grid[LOW][RGT] == 1)
        return 1;
    if (grid[TOP][RGT] == 1 && grid[MID][CNT] == 1 && grid[LOW][LFT] == 1)
        return 1;

/*
 * samefag (repeated for other player) (lrn2usefunctions u nub!)
 */
    if (grid[TOP][LFT] == 2 && grid[TOP][CNT] == 2 && grid[TOP][RGT] == 2)
        return 2;
    if (grid[MID][LFT] == 2 && grid[MID][CNT] == 2 && grid[MID][RGT] == 2)
        return 2;
    if (grid[LOW][LFT] == 2 && grid[LOW][CNT] == 2 && grid[LOW][RGT] == 2)
        return 2;

    if (grid[TOP][LFT] == 2 && grid[MID][LFT] == 2 && grid[LOW][LFT] == 2)
        return 2;
    if (grid[TOP][CNT] == 2 && grid[MID][CNT] == 2 && grid[LOW][CNT] == 2)
        return 2;
    if (grid[TOP][RGT] == 2 && grid[MID][RGT] == 2 && grid[LOW][RGT] == 2)
        return 2;

    if (grid[TOP][LFT] == 2 && grid[MID][CNT] == 2 && grid[LOW][RGT] == 2)
        return 2;
    if (grid[TOP][RGT] == 2 && grid[MID][CNT] == 2 && grid[LOW][LFT] == 2)
        return 2;

/*
 * tied game (meaning you both suck)
 */
    test  = 1;
    for (y = 0; y < GRID_SIZE; y++)
        for (x = 0; x < GRID_SIZE; x++)
            test &= (grid[y][x] == 1) || (grid[y][x] == 2);
    if (test != 0 || turn >= 9)
        return 3;

/*
 * game still on
 */
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

/* to do:  wtf man lrn2switch */
	if (place == 1)
	{
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			// Don't worry about outputing an error if the CPU is moving as it it random and is bound to do so
			// cout << "Error, cannot move there. Please try again" << endl << endl;
			goto try_CPU2; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 3)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 4)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 5)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 6)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 7)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 8)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == 9)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
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
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 3)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 4)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 5)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 6)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 7)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 8)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_CPU;
		}
	}
	else if (place == 9)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
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
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person; // Return to begining of function to try again
		}
	}
	else if (place == 2)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 3)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 4)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 5)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 6)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 7)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 8)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			cout << "Error, cannot move there. Please try again" << endl << endl;
			error++;
			goto try_person;
		}
	}
	else if (place == 9)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
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