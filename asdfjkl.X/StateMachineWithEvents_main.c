/* 
 * File:   StateMachineWithEvents_main.c
 * Author: max
 *
 * Created on July 28, 2016, 12:46 PM
 */

//other includes go here

#include <stdio.h>
#include "BOARD.h"
#include "events.h"
#include "runStateMachine.h"
#include "roach.h"
#include "timers.h"


//standard event-handling main function:

void main(void)
{
    //Init code (BOARD, Roach, Timers)
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();
    printf("works\n");
    event_t currentEvent = NO_EVENT;
    RunStateMachine(NO_EVENT);
    InitTimer(0,1);
    while (1) {
        //if an event happens run the state machine
        currentEvent = CheckForEvents();
        if (currentEvent != NO_EVENT){
            RunStateMachine(currentEvent);
        }
            
    }
}
