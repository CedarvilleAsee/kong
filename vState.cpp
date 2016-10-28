#include "vState.h"

static vState vState::getCurrentState(){
	return currentState;
}

static void vState::setCurrentState(vState newState){
	currentState = newState;
}