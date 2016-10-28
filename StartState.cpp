//#include "vState.h"
#include "StartState.h"
#include "pins.h"

StartState::StartState(){
	
}

void StartState::update(){
	if(digitalRead(START_BUTTON_PIN) == HIGH){
		vState.getCurrentState()->setState(new LineFollowState());
	}
}