/*
Main file for ASEE 2017 two robot solution with a STM32 controller.

please don't use 2 spaces for indentation.
*/

//wednesday's stuff
#include <Servo.h>
#include <Arduino.h>

#include "pins.h"
#include "constants.h"
#include "stateMachine.h"
#include "PT6961.h"

using namespace stateMachine;

int state;
static PT6961 display(DIN, CLOCK, CS);




void setup() {

	state = START_STATE;

  display.initDisplay();
  
	pinMode(SENSOR_0, INPUT);//line sensors
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(SENSOR_4, INPUT);
  pinMode(SENSOR_5, INPUT);
  pinMode(SENSOR_6, INPUT);
  pinMode(SENSOR_7, INPUT);

 
  
	pinMode(GO_BUTTON, INPUT_PULLUP);

  pinMode(MC_PWMA, OUTPUT);
  pinMode(MC_AIN2, OUTPUT);
  pinMode(MC_AIN1, OUTPUT);
  
  pinMode(MC_PWMB, OUTPUT);
  pinMode(MC_BIN1, OUTPUT);
  pinMode(MC_BIN2, OUTPUT);

  pinMode(MC_STBY, OUTPUT);

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(MC_AIN1, LOW);  // Go forward
  digitalWrite(MC_AIN2, HIGH);  // Go forward

  digitalWrite(MC_BIN1, HIGH);  // Go forward
  digitalWrite(MC_BIN2, LOW); // Go forward

  digitalWrite(MC_STBY, HIGH);

}

void loop() {

  int data = readData();

  SensorIndices indices = interpretData(data);

   
  //display.sendNum(data, ((indices.amountSeen > 0)?(1):(0)));
  display.sendDigits(0, indices.firstIndex, indices.lastIndex, indices.amountSeen ,0);
  drive(indices);

}
