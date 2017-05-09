/*
 * File:   events.c
 * Author: maxL
 *
 * Created on July 28, 2016, 12:36 PM
 */

#include <stdio.h>
#include "events.h"
#include "timers.h"

#define FLEFT_DOWN 1
#define FRIGHT_DOWN 2
#define FRONT_DOWN 3

#define RLEFT_DOWN 4
#define RRIGHT_DOWN 8
#define REAR_DOWN 12

#define LOW_THRESH 550
#define HIGH_THRESH 650

#define SECOND 1000

// Check for all events:

event_t CheckForEvents(void)
{
    event_t thisEvent = NO_EVENT;

    thisEvent = CheckForBumpers();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    }
    
    thisEvent = CheckLightSensor();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    }

    
    return NO_EVENT;
}

// define each event checker


event_t CheckForBumpers(void)
{
    // all event checkers remember their previous Event:
    static int previousEvent;
    

    // all event checkers update their event:
    int thisEvent = Roach_ReadBumpers();
    // current_status = ???

    // if there has been an important change, return an event:
    if (previousEvent != thisEvent){
        previousEvent = thisEvent;
        if(thisEvent == FLEFT_DOWN){
            return FL_BUMP_DOWN;
        } else if(thisEvent == FRIGHT_DOWN){
            return FR_BUMP_DOWN;
        } else if(thisEvent == FRONT_DOWN){
            printf("front");
            return F_BUMP_DOWN;
        } else if(thisEvent == RLEFT_DOWN){
            return RL_BUMP_DOWN;
        } else if(thisEvent == RRIGHT_DOWN){
            return RR_BUMP_DOWN;
        } else if(thisEvent == REAR_DOWN){ 
            printf("rear");
            return R_BUMP_DOWN;
        } else {
            return BUMP_UP;
        }
        
                
    }
    
    /*static int previousFLBump;
    static int previousFRBump;
    static int previousFBump;
    
    static int previousRLBump;
    static int previousRRBump;
    static int previousRBump;
    
    int thisFLBump;
    int thisFRBump;
    int thisFBump;
    
    int thisRLBump;
    int thisRRBump;
    int thisRBump;
    
    if(Roach_ReadBumpers()){
        thisFLBump = Roach_ReadFrontLeftBumper();
        thisFRBump = Roach_ReadFrontRightBumper();
        
                
        thisRLBump = Roach_ReadRearLeftBumper();
        thisRRBump = Roach_ReadRearRightBumper();
        
        if(thisFLBump && thisFRBump){
                   
            return F_BUMP_DOWN;
        } else if(thisFLBump){
            
            return FL_BUMP_DOWN;
        } else if(thisFRBump) {
            
            return FR_BUMP_DOWN;
        } else if(thisRLBump && thisRRBump) {
            
            return R_BUMP_DOWN;
        } else if(thisRLBump){
            
            return RL_BUMP_DOWN;
        } else if(thisRRBump){
            
            return RR_BUMP_DOWN;
        } else {
            return BUMP_UP;
        }
        
        
    
    }*/
    
    //and if there has not been an important change,
    return NO_EVENT;
}


event_t CheckLightSensor(void)
{
    // all event checkers remember their previous Event:
    static int previousEvent;
    

    // all event checkers update their event:
    int thisEvent = Roach_LightLevel();
    // current_status = ???

    // if there has been an important change, return an event:
    if (previousEvent != thisEvent){
        previousEvent = thisEvent;
        if(thisEvent < LOW_THRESH){
            
            return ENTERED_LIGHT;
        } else if(thisEvent > HIGH_THRESH){
            return ENTERED_DARK;
        }
        
                
    }
    //printf("light = %d\n", previousEvent);
    //and if there has not been an important change,
    return NO_EVENT;
}


/*event_t CheckForTimers(void)
{
    static int previousEvent;
    static char timerSet;
    int thisEvent = IsTimerExpired(0);
    
    if (previousEvent != thisEvent){
        previousEvent = thisEvent;
        if(!timerSet){
            timerSet = 1;
            InitTimer(0, SECOND);
            return TIMEOUT;
        } else {
            timerSet = 0;
            return ARM;
        }
        
    }
    return NO_EVENT; //replace with your code here
}*/
