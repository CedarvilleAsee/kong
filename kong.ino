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

Servo dump;
Servo clobber;
Servo scoop;

void setup() {

	state = LINE_FOLLOW;

  display.initDisplay();
  
	pinMode(SENSOR_0, INPUT);//line sensors
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(SENSOR_4, INPUT);
  pinMode(SENSOR_5, INPUT);
  pinMode(SENSOR_6, INPUT);
  pinMode(SENSOR_7, INPUT);

 // pinMode(WALL_SENSOR1, INPUT);
  
	pinMode(GO_BUTTON, INPUT_PULLUP);

  pinMode(MC_PWMA, OUTPUT);
  pinMode(MC_AIN2, OUTPUT);
  pinMode(MC_AIN1, OUTPUT);
  
  pinMode(MC_PWMB, OUTPUT);
  pinMode(MC_BIN1, OUTPUT);
  pinMode(MC_BIN2, OUTPUT);

  pinMode(MC_STBY, OUTPUT);

  pinMode(LED_PIN, OUTPUT);

  dump.attach(DUMP_SERVO);
  clobber.attach(CLOBBER_SERVO);

  clobber.write(CLOBBER_START_POSITION);
  
  scoop.attach(SCOOP_SERVO);

  digitalWrite(MC_AIN1, LOW);  // Go forward
  digitalWrite(MC_AIN2, HIGH);  // Go forward

  digitalWrite(MC_BIN1, HIGH);  // Go forward
  digitalWrite(MC_BIN2, LOW); // Go forward

  digitalWrite(MC_STBY, HIGH);


}

void loop() {

  int data = readData();

  SensorIndices indices = interpretData(data);
   
  display.sendNum(data, ((indices.amountSeen > 0)?(1):(0)));
  int wallSensorData = analogRead(WALL_SENSOR1);
  
  
  delay(50);
  //drive(indices, dump, scoop, clobber);
  
 
}
