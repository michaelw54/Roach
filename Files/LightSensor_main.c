/* 
 * File:   LightSensor_main.c
 * Author: COSMOS
 *
 * Created on July 21, 2016, 2:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"
#include "LightSensor.h"

#define TIMER_A 0
/*
 * 
 */
int main(int argc, char** argv) {

    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();

    InitTimer(TIMER_A, 100);
    while(1){
        if (IsTimerExpired(TIMER_A)) {
            if (CheckLightSensor()) {
                printf("LIGHT ");
            } else {
                printf("DARK ");
            }
            InitTimer(TIMER_A, 100);
        }
    }
    return (EXIT_SUCCESS);
}

