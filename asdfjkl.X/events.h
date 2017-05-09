/* 
 * File:   events.h
 * Author: maxL
 *
 * Created on July 28, 2016, 12:36 PM
 */

#ifndef EVENTS_H
#define EVENTS_H

// A list of your events goes here:

typedef enum {
        NO_EVENT,//0
        ENTERED_LIGHT,//1
        ENTERED_DARK,//2
        FL_BUMP_DOWN,//3
        FR_BUMP_DOWN,//4
        F_BUMP_DOWN,//5
        RL_BUMP_DOWN,//6
        RR_BUMP_DOWN,//7
        R_BUMP_DOWN,//8
    BUMP_UP,//9
    TIMEOUT,//10
    TIMESET//11

} event_t;

// A prototype for the function that handles all the event checkers:
event_t CheckForEvents(void);

// prototypes for your event checkers go here:
event_t CheckForBumpers(void);
event_t CheckLightSensor(void);

// etc...

#endif