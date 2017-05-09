/* 
 * File:   Library_Test_main.c
 * Author: COSMOS
 *
 * Created on July 25, 2016, 11:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"


#include "Navigation.h"
#include "Bumpers.h"
#include "LightSensor.h"

#define INTERVAL 500
/*
 * 
 */
int main(int argc, char** argv) {
    
    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();
    
    
    //initialization here
    MoveForward(10);
    InitTimer(0,500);
    while (1) {
        if (IsTimerExpired(0)) {
            printf("Bumpers = %X", CheckForBumps());
            printf("LightLevel = %X", CheckLightSensor());
            InitTimer(0, INTERVAL);
        }
    }
    
    printf("Hello World\n");
    return (EXIT_SUCCESS);
    
}

