/** @file game.c
    @author Robert Loomes(rwl29), Ryan Sheridan(rsh127)
    @date October, 2017
    @brief Paper Scissors Rock -Main

A game of paper scissors rock. This main program handles all the main 
* logic for the game, and calls other supporting modules as needed.
**/
#include <stdio.h>
#include "system.h"
#include "../fonts/font5x7_1.h"
#include "pacer.h"
#include <avr/io.h>

#include "tinygl.h"
#include "navswitch.h"
#include <stdbool.h>
#include "ir_uart.h"
#include "led.h"
#include "endgame.h"
#include "endgame.c"
#include "optionselect.h"
#include "optionselect.c"

/*Defines the pacer wait period and the message scrolling rate in Hz*/
#define PACER_RATE 1000
#define MESSAGE_RATE 20

int main (void)
{
    system_init();
    navswitch_init();
    led_init ();
    led_set (LED1, 0);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    char greeting[] = "ROCK/PAPER/SCISSORS, PUSH TO BEGIN";
    tinygl_text(greeting);
    pacer_init (PACER_RATE);
    ir_uart_init();
    
    option currently_selected = ROCK; //rock is default choice 
    option opponent_choice = ROCK; //rock is default choice 
    
    int game_start = 1;
    int select_char = 1;
    int send_char = 1;
    int game_end = 1;
    
    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCCR1C = 0x00;
    
    while (game_start) { /* Scrolling starter text */
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
            print_option(ROCK);
            game_start = 0;
        }
    }

    while (select_char) { /*Cycling through rock/paper/scissors options 
        * and a push event for a decision on said choice*/
        pacer_wait();
        tinygl_update();
        navswitch_update();
       
        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
            currently_selected = game_cycle(currently_selected);
        }
        if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            currently_selected = opp_game_cycle(currently_selected);
        }
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            select_char = 0;
            tinygl_clear();
            led_set (LED1, 1);
        }
    }
        
    while (send_char) {  /* send and receive IR (not actually working)*/
        tinygl_update();
        TCNT1=0;
        while (TCNT1 < 2000) {
            continue;
        }

        if (ir_uart_read_ready_p()) {
            opponent_choice = ir_uart_getc();
            /*Makes sure character recieved is of correct type*/
            if (opponent_choice == ROCK || opponent_choice == PAPER || opponent_choice == SCISSORS) {
                send_char = 0;  
                led_set (LED1, 0);
            }
        }
               
        TCNT1=0;
        while (TCNT1 < 2000) {
            continue;
        }
        
        int i;
        for ( i = 0; i < 6; i++ ) {
            ir_uart_putc(currently_selected);
        }
        
        TCNT1=0;
        while (TCNT1 < 2000) {
            continue;
        }
    }    
    
    while (game_end) { /* Displays loser for the losing board and winner for the winning board */
        tinygl_update();
        ir_uart_putc(currently_selected);
        print_result(game_result(currently_selected, opponent_choice));         
    }
        
    return 0;
}


