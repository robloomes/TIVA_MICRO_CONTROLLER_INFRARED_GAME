/** @file optionselect.c
    @author Robert Loomes(rwl29), Ryan Sheridan(rsh127)
    @date October, 2017
    @brief Define various game functions to display and
    clyle through symbol options e.g rock, paper, scissors.

    Defines the functions below for use in main game program.
    Allows the selection of currently dispayed option, as well as the
    function for cycling through options.
**/
#include "optionselect.h"
#include "system.h"
#include "../fonts/font5x7_1.h"
#include "pacer.h"
#include "tinygl.h"
#include "navswitch.h"

/*Begins the main game cycle, where the navswitchs can be used to cycle
 * through the different symbol options
 * */
option game_cycle(option current_displayed)
{
    if (current_displayed == ROCK) {
        current_displayed = PAPER;
        print_option(PAPER);
    } else if (current_displayed == PAPER) {
        current_displayed = SCISSORS;
        print_option(SCISSORS);
    } else {
        current_displayed = ROCK;
        print_option(ROCK);
    }
    return current_displayed;
}

/*begins the main game cycle, where the navswitchs can be used to cycle
 * through the different symbol options --conflicting direction to
 * game_cycle()
 * */
option opp_game_cycle(option current_displayed)
{
    if (current_displayed == ROCK) {
        current_displayed = SCISSORS;
        print_option(SCISSORS);
    } else if (current_displayed == PAPER) {
        current_displayed = ROCK;
        print_option(ROCK);
    } else {
        current_displayed = PAPER;
        print_option(PAPER);
    }
    return current_displayed;
}

/*prints the game option(e.g Rock) to the game screen in symbol format
* e.g 'R'
* */
void print_option(option option_choice)
{
    char buffer[2];
    buffer[0] = option_choice;
    buffer[1] = '\0';
    tinygl_text(buffer);
}




