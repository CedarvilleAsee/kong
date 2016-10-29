/*
Main file for ASEE 2017 two robot solution with a STM32 controller.

please don't use 2 spaces for indentation.
*/

#include "pins.h"
#include <Servo.h>
#include "constants.h"

int state;

void setup() {

	state = START_STATE;
	
	pinMode(BIG_B, INPUT_PULLUP);
	pinMode(LIL_B, INPUT_PULLUP);

	pinMode(PC13, OUTPUT);
	
}

void loop() {

	//MAIN STATE MACHINE SWITCH
	switch (state) {
	
		case START_STATE:

			//set led to on
			digitalWrite(LED_PIN, HIGH);
			
			//if start button is pressed, go to line following state.

			if(!digitalRead(BIG_B)){
				state = LINE_FOLLOW_STATE;
			}



			
			break;
			
		case LINE_FOLLOW_STATE:
			//follow line here

			digitalWrite(LED_PIN, LOW);

			if(!digitalRead(LIL_B)){
				state = START_STATE;
			}
		
			//drive forward for like a bit

			//tell left motor to drive forward
			pinMode(WHEEL_DIR_L_F, OUTPUT);
			pinMode(WHEEL_DIR_L_B, OUTPUT);
			digitalWrite(WHEEL_L_F, HIGH);
			digitalWrite(WHEEL_L_B, LOW);

			//tell right motor to drive forward
			pinMode(WHEEL_DIR_R_F, OUTPUT);
			pinMode(WHEEL_DIR_R_B, OUTPUT);
			digitalWrite(WHEEL_R_F, HIGH);
			digitalWrite(WHEEL_R_B, LOW);


			//move lumberjack servo up





			break;
	
		case TEST_STATE:
			//do testing stuff here
			

			
			break;
			
	}
}