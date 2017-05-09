#include <stdio.h>
#include <stdlib.h>


#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"


void MoveForward (int speed) {
    Roach_RightMtrSpeed (speed);
    Roach_LeftMtrSpeed (speed);
}

void Stop () {
    MoveForward(0);
}

void Reverse (int speed) {
    MoveForward(-speed);
}

void RotateRight (int speed) {
    Roach_RightMtrSpeed (-speed);
    Roach_LeftMtrSpeed (speed);
}

void RotateLeft (int speed) {
    Roach_RightMtrSpeed (speed);
    Roach_LeftMtrSpeed (-speed);
}

void PivotRight (int speed) {
    Roach_RightMtrSpeed (0);
    Roach_LeftMtrSpeed (speed);
}

void PivotLeft (int speed) {
    Roach_RightMtrSpeed (speed);
    Roach_LeftMtrSpeed (0);
}

void ArcRight (int speed) {
    Roach_RightMtrSpeed (speed/2);
    Roach_LeftMtrSpeed (speed);
}

void ArcLeft (int speed) {
    Roach_RightMtrSpeed (speed);
    Roach_LeftMtrSpeed (speed/2);
}

