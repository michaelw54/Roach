/*
 * File:   runStateMachine.c
 * Author: max
 *
 * Created on July 28, 2016, 12:43 PM
 */
#include <stdio.h>
#include "runStateMachine.h"
//#include "events.h"

#include "roach.h"
#include "Navigation.h"

#define DEFAULT_COUNT 12
#define SECOND 1000
#define TIME 800
#define MAX_SPEED 10

void RunStateMachine(event_t currentEvent) {
    //printf("%d\n", TIME/2);
    static state_t currentState = IDLE;
    //static int count;
    
    //which state are we in? 
    //printf("\nState: %d\tEvent: %d", currentState, currentEvent);
    
    switch (currentState) {
        case IDLE:
        {
            
            switch(currentEvent) {
                case ENTERED_LIGHT:
                {
                    currentState = RIGHT_PATH;
                    MoveForward(MAX_SPEED);                    
                }
            }
            
            break;
            
        }
        
        case RIGHT_PATH:
        {
            
            switch (currentEvent) {
                // take actions here dependent on the event
                case FL_BUMP_DOWN:
                {
                    printf("frontleft");
                    
                    currentState = WRONG_PATH;
                    
                    InitTimer(0, TIME / 2);
                    while(IsTimerActive(0)){
                        RotateRight(MAX_SPEED);
                    }
                    
                    
                    //printf("reverse\n");
                    break;
                }
                case FR_BUMP_DOWN:
                {
                    printf("frontright");
                    
                    currentState = WRONG_PATH;
                    
                    InitTimer(0,TIME /2);
                    while(IsTimerActive(0)){
                        RotateLeft(MAX_SPEED);
                    }
                    break;
                }
                case F_BUMP_DOWN:
                {
                    printf("front");
                    
                    currentState = WRONG_PATH;
                    InitTimer(0,TIME/2);
                    while(IsTimerActive(0)){
                        RotateLeft(MAX_SPEED);
                    }
                    break;
                }
                case RL_BUMP_DOWN:
                {
                    
                    printf("rearleft");
                    currentState = WRONG_PATH;
                    InitTimer(0,TIME/2);
                    while(IsTimerActive(0)){
                        RotateLeft(-MAX_SPEED);
                    }
                    break;
                }
                case RR_BUMP_DOWN:
                {
                    printf("rearright");
                    
                    currentState = WRONG_PATH;
                    InitTimer(0, TIME/2);
                    while(IsTimerActive(0)){
                        RotateRight(-MAX_SPEED);
                    }
                    break;
                }
                case R_BUMP_DOWN:
                {
                    printf("rear");
                    
                    currentState = WRONG_PATH;
                    InitTimer(0,TIME/2);
                    while(IsTimerActive(0)){
                        MoveForward(MAX_SPEED);
                    }
                    break;
                }
                case ENTERED_DARK:
                {
                    currentState = IDLE;
                    Stop();
                    break;
                }
                case BUMP_UP:
                {
                    
                    break;
                }
                
                
            }
            break;
        }
        case WRONG_PATH:
        {
            switch (currentEvent) {
                // take actions here dependent on the event
                
                case BUMP_UP:
                {
                    //printf("right path\n");
                    MoveForward(MAX_SPEED);
                    currentState = RIGHT_PATH;
                    break;
                }
                break;
            }
            
            break;
        }
        
        
    }
}
