/** @file end_game.c
    @author Robert Loomes(rwl29), Ryan Sheridan(rsh127)
    @date October, 2017
    @brief Define a game function to display the result of the game.

A game of paper scissors rock
**/
#include "pacer.h"
#include "tinygl.h"
#include "endgame.h"

/*Returns a single char that determines the result of the current game.
 *Based on the comparison of the 2 player's final game choices.*/
result game_result(option currently_selected, option opponent_choice)
{
	if (currently_selected == opponent_choice) {
		return DRAW;
	} else if (currently_selected == ROCK && opponent_choice == SCISSORS) {
		return WIN;
	} else if (currently_selected == PAPER && opponent_choice == ROCK) {
		return WIN;
	} else if (currently_selected == SCISSORS && opponent_choice == ROCK) {
		return WIN;
	} else {
		return LOSE;
	}
}

/*prints the game result(e.g WIN) to the game screen in symbol format
* e.g 'W'
* */
void print_result(result resolution)
{
    char buffer[2];
    buffer[0] = resolution;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


