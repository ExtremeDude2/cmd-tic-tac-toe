/************************************************************/
/*                                                          */
/* Created by Ryan Collins 2012-2015, use at your own risk. */
/*                                                          */
/************************************************************/

/*
To do list:
Optimize horrible code
make CPU // No time D;
Try to make UI // Nooooooooooooooooooooooooooooo, it won't work D;
*/

#include <stdio.h>
#include <stdlib.h>

#include "board.h"

static long scan_long(void)
{
    static char temp_buffer[32];
    size_t i;

    for (i = 0; i < sizeof(temp_buffer); i++)
    {
        int character;

        character = getchar();
        if (character == '\n')
            break;
        if (character == EOF)
        {
            fputs("scan_long:  unexpected EOF\n", stderr);
            break;
        }
        temp_buffer[i] = (char)character;
    }

    if (i >= sizeof(temp_buffer))
    {
        fputs("scan_long:  evaded buffer overrun\n", stderr);
        i = sizeof(temp_buffer) - 1;
    }
    temp_buffer[i] = '\0';
    return strtol(temp_buffer, NULL, 0);
}

unsigned short grid[GRID_COMPLEXITY][GRID_COMPLEXITY];
unsigned short turn = 0, game = 0, x_win = 0, o_win = 0, tie = 0, error = 0;

/* This function is CPU X's logic (aka random). */
long CPU_X()
{
    long place;

    place = (rand() % GRID_SIZE) + 1;
    return (place);
}

/* This function is CPU O's logic (aka random). */
long CPU_O()
{
    long place;

    place = (rand() % GRID_SIZE) + 1;
    return (place);
}

/* This function is used to determine whose turn it is. */
unsigned short player_turn()
{
    return (turn % NUM_PLAYERS) + 1;
}

/* This function resets all of the places and clears the screen. */
void reset()
{
    int x, y;

    for (y = 0; y < GRID_COMPLEXITY; y++)
        for (x = 0; x < GRID_COMPLEXITY; x++)
            grid[y][x] = BLANK;
    turn = error = 0;
    system("cls"); /* <-- gay */
}

/* This function checks to see if anyone has won or if there is a tie. */
unsigned short check_status()
{
    unsigned int ways_to_win[8];
    unsigned int test;
    register int i;

/*
 * horizontal tests
 */
    ways_to_win[0] = grid[TOP][LFT] & grid[TOP][CNT] & grid[TOP][RGT];
    ways_to_win[1] = grid[MID][LFT] & grid[MID][CNT] & grid[MID][RGT];
    ways_to_win[2] = grid[LOW][LFT] & grid[LOW][CNT] & grid[LOW][RGT];

/*
 * vertical tests
 */
    ways_to_win[3] = grid[TOP][LFT] & grid[MID][LFT] & grid[LOW][LFT];
    ways_to_win[4] = grid[TOP][CNT] & grid[MID][CNT] & grid[LOW][CNT];
    ways_to_win[5] = grid[TOP][RGT] & grid[MID][RGT] & grid[LOW][RGT];

/*
 * diagonal tests
 */
    ways_to_win[6] = grid[TOP][LFT] & grid[MID][CNT] & grid[LOW][RGT];
    ways_to_win[7] = grid[TOP][RGT] & grid[MID][CNT] & grid[LOW][LFT];

    test = 0;
    for (i = 0; i < 8; i++)
        test |= ways_to_win[i];

    switch (test)
    {
    case BLANK:  return (turn < GRID_SIZE ? PLAYING : DRAW);
    case SET_X:  return (WIN_X);
    case SET_O:  return (WIN_O);
    default:
        fputs("check_status:  conflicting or multiple winners?", stderr);
        return (test);
    }
}

/* This function is used when 2 CPU's play against each other. */
void CPU2()
{
    long place;

try_CPU2:
    switch (player_turn())
    {
    case SET_X:
        puts("X(CPU)'s turn");
        place = CPU_X();
        break;
    case SET_O:
        puts("O(CPU)'s turn");
        place = CPU_O();
        break;
    default:
        puts("Error, unknown turn");
        place = 0;
        error++;
    }

/* to do: glrn2switch */
    if (place == TOP_LEFT)
    {
        if (!grid[TOP][LFT])
            grid[TOP][LFT] = player_turn();
        else
        {
            /* Don't worry about outputting an error if the CPU is moving, as it is random and is bound to do so. */
#if 0
            puts("Error, cannot move there. Please try again\n");
#endif
            goto try_CPU2; /* Return to beginning of function to try again. */
        }
    }
    else if (place == TOP_CENTER)
    {
        if (!grid[TOP][CNT])
            grid[TOP][CNT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == TOP_RIGHT)
    {
        if (!grid[TOP][RGT])
            grid[TOP][RGT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == MID_LEFT)
    {
        if (!grid[MID][LFT])
            grid[MID][LFT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == MID_CENTER)
    {
        if (!grid[MID][CNT])
            grid[MID][CNT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == MID_RIGHT)
    {
        if (!grid[MID][RGT])
            grid[MID][RGT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == LOW_LEFT)
    {
        if (!grid[LOW][LFT])
            grid[LOW][LFT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == LOW_CENTER)
    {
        if (!grid[LOW][CNT])
            grid[LOW][CNT] = player_turn();
        else
        {
            error++;
            goto try_CPU2;
        }
    }
    else if (place == LOW_RIGHT)
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
        puts("Error, incorrect place. Please try again\n");
        error++;
        goto try_CPU2;
    }
    draw_board();
    turn++;
}

/* This function is used when 1 player is against 1 CPU. */
void CPU()
{
    long place;

try_CPU:
    switch (player_turn())
    {
    case SET_X:
        puts("X's turn");
        putchar('\n');
        fputs(
            "Please select where you would like to go, options include:\n"\
            "Nort West (1), North (2), North East (3), West (4), Center (5),\n"\
            "East (6), South West (7), South (8), South East (9):", stdout
        );
        putchar(' ');
        place = scan_long();
        putchar('\n');
        break;
    case SET_O:
        puts("O(CPU)'s turn");
        place = CPU_O();
        break;
    default:
        puts("Error, unknown turn");
        place = 0;
        error++;
    }

    if (place == TOP_LEFT)
    {
        if (!grid[TOP][LFT])
            grid[TOP][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU; /* Return to begining of function to try again. */
        }
    }
    else if (place == TOP_CENTER)
    {
        if (!grid[TOP][CNT])
            grid[TOP][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == TOP_RIGHT)
    {
        if (!grid[TOP][RGT])
            grid[TOP][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == MID_LEFT)
    {
        if (!grid[MID][LFT])
            grid[MID][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == MID_CENTER)
    {
        if (!grid[MID][CNT])
            grid[MID][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == MID_RIGHT)
    {
        if (!grid[MID][RGT])
            grid[MID][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == LOW_LEFT)
    {
        if (!grid[LOW][LFT])
            grid[LOW][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == LOW_CENTER)
    {
        if (!grid[LOW][CNT])
            grid[LOW][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else if (place == LOW_RIGHT)
    {
        if (!grid[LOW][RGT])
            grid[LOW][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_CPU;
        }
    }
    else
    {
        puts("Error, incorrect place. Please try again\n");
        error++;
        goto try_CPU;
    }
    draw_board();
    turn++;
}

/* This function is used when 2 people play against each other. */
void person()
{
    long place;

try_person:
    switch (player_turn())
    {
    case SET_X:
        puts("X's turn");
        break;
    case SET_O:
        puts("O's turn");
        break;
    default:
        puts("Error, unknown turn");
        error++;
    }

    putchar('\n');
    fputs(
        "Please select where you would like to go, options include:\n"\
        "Nort West (1), North (2), North East (3), West (4), Center (5),\n"
        "East (6), South West (7), South (8), South East (9):", stdout
    );
    putchar(' ');
    place = scan_long();
    putchar('\n');

    if (place == TOP_LEFT)
    {
        if (!grid[TOP][LFT])
            grid[TOP][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person; /* Return to begining of function to try again. */
        }
    }
    else if (place == TOP_CENTER)
    {
        if (!grid[TOP][CNT])
            grid[TOP][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == TOP_RIGHT)
    {
        if (!grid[TOP][RGT])
            grid[TOP][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == MID_LEFT)
    {
        if (!grid[MID][LFT])
            grid[MID][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == MID_CENTER)
    {
        if (!grid[MID][CNT])
            grid[MID][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == MID_RIGHT)
    {
        if (!grid[MID][RGT])
            grid[MID][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == LOW_LEFT)
    {
        if (!grid[LOW][LFT])
            grid[LOW][LFT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == LOW_CENTER)
    {
        if (!grid[LOW][CNT])
            grid[LOW][CNT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else if (place == LOW_RIGHT)
    {
        if (!grid[LOW][RGT])
            grid[LOW][RGT] = player_turn();
        else
        {
            puts("Error, cannot move there. Please try again\n");
            error++;
            goto try_person;
        }
    }
    else
    {
        puts("Error, incorrect place. Please try again\n");
        error++;
        goto try_person;
    }
    draw_board();
    turn++;
}

int main(void)
{
    long players;
    long playing;

start:
    /* Ask the user how many human players there are (if any). */
    puts(
        "Would you like to play with 0 (2 CPUs), 1 (1 CPU), or 2 players? "\
        "(switching number of players mid-game requires a restart)"
    );
    puts("Note: All CPUs are very fast and you will likely not see them move.");

    players = scan_long();
    system("cls");
    playing = 1;
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
            puts("Error, do not know how many people/CPU's are playing. Please try again.");
            error++;
            goto start;
        }
        if (check_status())
        {
            system("cls");
            puts("SCOREBOARD:");
            putchar('\n');
            if (check_status() == WIN_X)
            {
                printf("X wins! It was done in %u turns.\n", turn);
                x_win++;
            }
            else if (check_status() == WIN_O)
            {
                printf("O wins! It was done in %u turns.\n", turn);
                o_win++;
            }
            else if (check_status() == DRAW)
            {
                printf("Tie, no one wins.\n");
                tie++;
            }
            else
            {
                puts("Error, unknown winner. Going back to start\n");
                error++;
                putchar('\n');
                goto start;
            }
            putchar('\n');

            game++;
            draw_board();

            putchar('\n');
            printf(
                "Out of %u game(s) played, "\
                "X has %u win(s), "\
                "O has %u win(s), "\
                "and there have been %u tie(s).\n",

                game, x_win, o_win, tie
            );

            putchar('\n');
            printf(
                "A total number of %u errors have occurred this turn "\
                "from moving in incorrect places or for some other reason.\n",

                error
            );

            fputs("Would you like to play again? (1 = yes, 0 = no): ", stdout);
            playing = scan_long();
            reset();
        }
    }
}
