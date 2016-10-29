/*
Main file for ASEE 2017 two robot solution with a STM32 controller.

please don't use 2 spaces for indentation.
*/

#include "pins.h"
#include <Servo.h>

void setup() {

	enum state {
		TEST_STATE = 0,
		START_STATE = 1,
		LINE_FOLLOW_STATE = 2
	};
	state = START_STATE;
	
	pinMode(START_BUTTON_PIN, INPUT_PULLUP);
	
}

void loop() {
	
	//MAIN STATE MACHINE SWITCH
	switch (state) {
	
		case START_STATE:
			
			//if start button is pressed, go to line following state.
			if(digitalRead(START_BUTTON_PIN) == HIGH){
				state = LINE_FOLLOW_STATE;
			}
			//if second button is pressed, go to testing state.
			if(digitalRead(BUTTON_TWO) == HIGH){
				state = TEST_STATE;
			}
			
			break;
			
		case LINE_FOLLOW_STATE:
			//follow line here
		
		
			break;
			
		case TEST_STATE:
			//do testing stuff here
			
			
			break;
			
	}
}