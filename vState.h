#ifndef STATE_H
#define STATE_H

class vState{
public:

	void update(){
		
	}

	static vState getCurrentState();

	static void setCurrentState(vState newState);

private:

	static vState currentState;

};

#endif