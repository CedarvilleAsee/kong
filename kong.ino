#include "vState.h"
#include "LineFollowState.h"
#include "StartState.h"
#include "pins.h"
//#include <Servo.h>

void setup() {
  vState.setState(new StartState());
  pinMode(START_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  vState.getCurrentState().update();
}