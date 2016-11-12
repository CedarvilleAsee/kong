#ifndef CONSTANTS_H
#define CONSTANTS_H


const int TEST_STATE = 0;
const int START_STATE = 1;
const int LINE_FOLLOW_STATE = 2;
static int currentState = 0;

const int FULL_SPEED = 200;
const int TURN_SPEED = FULL_SPEED *.80;

//const int LINE_FOLLOW = 0;
//const int LEFT_TURN1 = 1;
//const int RIGHT_TURN1 = 2;

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
