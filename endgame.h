/** @file endgame.h
    @author Robert Loomes(rwl29), Ryan Sheridan(rsh127)
    @date October, 2017
    @brief Defines game resolution options e.g win, lose, draw
    
    Enables use of symbols used within the game in a typedef fashion.
    ENCE260 UCFK4 assignment
**/
#ifndef ENDGAME_H
#define ENDGAME_H

#include "pacer.h"
#include "tinygl.h"
#include "optionselect.h"

/* Task resolution enum*/
typedef enum {WIN = 'W', LOSE = 'L', DRAW = 'D'} result;
 
result game_result(option currently_selected, option opponent_choice);
void print_result(result resolution);
 
#endif /* ENDGAME_H */
