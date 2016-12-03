#ifndef CONSTANTS_H
#define CONSTANTS_H



static int currentState = 0;

const int FULL_SPEED = 150;
const int TURN_SPEED = FULL_SPEED *.80;

const int CLOBBER_START_POSITION = 95;
const int CLOBBER_BACK_POSITION = 60;

const int HALF_INCH = 496;
const int INCH = 1500;
const int INCH_AND_HALF = 3000;
const int TWO_INCH = 650;
const int THREE_INCH = 795;

enum State{
    LINE_FOLLOW = 0, LEFT_TURN1 = 1, RIGHT_TURN1 = 2  
};
const int TURN_SPEEDS[3] = { FULL_SPEED * 0.4,
                             FULL_SPEED * 0.6,
                             FULL_SPEED * 0.8
                           };

const int stateMap[3] = {
  LINE_FOLLOW, LEFT_TURN1, RIGHT_TURN1  
};

#endif
