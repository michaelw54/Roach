/* 
 * File:   Bumpers_main.c
 * Author: COSMOS
 *
 * Created on July 22, 2016, 11:09 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"
#include "Bumpers.h"

#define INTERVAL 100

/*
 * 
 */
int main(int argc, char** argv) {

    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();

    printf("Hello World\n");

    char strings[9][16] = {"No Change", "FL bumper up", "FR bumper up",
        "Front bumpers up", "RL bumper up", "No Change", "No Change",
        "No Change", "RR bumper up"};

    
    //Initializations here

    while (1) {
        if (CheckForBumps()) {
            int bump = Roach_ReadBumpers();
            printf("Bump=%s\n", strings[bump]);
            Roach_LEDSSet(bump);

        }
        InitTimer(0, INTERVAL);
        while (IsTimerActive(0));
    }


    return (EXIT_SUCCESS);
}

