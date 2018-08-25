/** @file optionselect.h
    @author Robert Loomes(rwl29), Ryan Sheridan(rsh127)
    @date October, 2017
    @brief Defines game symbol options
    
    Enables use of symbols used within the game in a typedef fashion.
    ENCE260 UCFK4 assignment
**/
 #ifndef OPTIONSELECT_H
 #define OPTIONSELECT_H
 
 /** Task symbol enum**/
 typedef enum {ROCK = 'R', PAPER = 'P', SCISSORS = 'S'} option;
 
 void print_option(option option_choice);
 option opp_game_cycle(option current_displayed);
 option game_cycle(option current_displayed);
 
 #endif /* OPTIONSELECT_H */
 
