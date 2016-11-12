
//#include "PT6961.h"

#include "pins.h"
#include "constants.h"
#include "stateMachine.h"
#include <Arduino.h>

extern int currentState;
/*
  void stateMachine::drive()//everything to do with the wheels
  {
    
   int* sensorsData = stateMachine::readData();
   int firstIndex = sensorsData[0];
   int lastIndex = sensorsData[1];
   int amountSeen = sensorsData[2];

  extern PT6961 display;
   
   delete[] sensorsData;
   
   int rightWheelOut;
   int leftWheelOut;


    if(true amountSeen == 2){//ultra simple version for starters
    	if(firstIndex == 3){
    		rightWheelOut = FULL_SPEED;
    		leftWheelOut = FULL_SPEED;
    	}
    	else if(firstIndex < 3){
    		rightWheelOut = FULL_SPEED;
    		leftWheelOut = TURN_SPEED;
    	}
    	else{  // firstIndex > 3
    		rightWheelOut = TURN_SPEED;
    		leftWheelOut = FULL_SPEED;
    	}


    }
    else if(amountSeen == 1){
    	if(firstIndex == 3 || firstIndex == 4){
    		rightWheelOut = FULL_SPEED;
    		leftWheelOut = FULL_SPEED;
    	}
    }

    display.sendNum(amountSeen,0);
    writeToWheels(leftWheelOut, rightWheelOut);
  }
*/

  void stateMachine::drive(const stateMachine::SensorIndices& data){

    int rightWheelOut = 0;
    int leftWheelOut  = 0;

    

    //Switch on current state 
    //WHAT ACTIONS TO DO IN THIS STATE\
    //int state = stateMape[currentState];
    
    switch(stateMap[currentState]) {
      case LINE_FOLLOW: {

        if(data.amountSeen > 0) {

            if(data.firstIndex < 4 && data.amountSeen > 3)
            {
              leftWheelOut = FULL_SPEED + 50;
            }
            else if(data.lastIndex > 2 && data.amountSeen > 3)
            {
              rightWheelOut = FULL_SPEED + 50;
            }
            else if(data.firstIndex > 3)
            {
              rightWheelOut = FULL_SPEED;
              leftWheelOut  = TURN_SPEEDS[data.firstIndex % 3];
            }
            else if(data.firstIndex < 3)
            {
              rightWheelOut = TURN_SPEEDS[data.firstIndex % 3];
              leftWheelOut  = FULL_SPEED;
            }
            else if((data.firstIndex == 3) || (data.firstIndex == 4))
            {
              rightWheelOut = FULL_SPEED;
              leftWheelOut  = FULL_SPEED;
            }
        }
        
        break; }
    }

    //Switch on current state
    //WHAT CONDITION TO MOVE TO NEXT STATE

    switch(stateMap[currentState]){
      
    }

    writeToWheels(leftWheelOut, rightWheelOut);
    //writeToWheels(0, 0);
    
  }

    /*
   * writeToWheels method:
   *    Writes a specific left and right turn speed to the wheels.
   *    
   *    leftSpeed  - the speed to write to the left wheel
   *    rightSpeed - the speed to write to the right wheel
   */
  void stateMachine::writeToWheels( int leftSpeed, int rightSpeed )
  {
    analogWrite( MC_PWMA, rightSpeed );
    analogWrite( MC_PWMB, leftSpeed );  
  }
  


  int stateMachine::readData(){ // return an array of length 3, first int is the firstIndex, second is lastIndex, third is amountSeen
     
      int lineData[8];
      lineData[0] = digitalRead(SENSOR_0);
      lineData[1] = digitalRead(SENSOR_1);
      lineData[2] = digitalRead(SENSOR_2);//can't use a for() b/c of alphanumeric pin ids
      lineData[3] = digitalRead(SENSOR_3);
      lineData[4] = digitalRead(SENSOR_4);
      lineData[5] = digitalRead(SENSOR_5);
      lineData[6] = digitalRead(SENSOR_6);
      lineData[7] = 0;
    //cheating didn't work  lineData[7] = analogRead(SENSOR_7); // Sensor 7 is busted for sure

      int dataNum = 0;
      for(int i = 0; i < 8; i++){
        dataNum += lineData[i]<<i;
      }

      return dataNum;
  }
  
  stateMachine::SensorIndices stateMachine::interpretData(int dataNum) {
      stateMachine::SensorIndices indices;

      indices.firstIndex = 9;
      indices.lastIndex = 9;
      indices.amountSeen = 0;
  
      for(int i = 0; i < 8; i++){
        /*int j = (dataNum>>i)%1<<(8-i);*/
        int j = (dataNum >> i) & 1;
        if(j == 1){
          indices.amountSeen++;
          indices.lastIndex = i;
          if(indices.firstIndex == 9){
            indices.firstIndex = i;
          }
          
        }
        /*if(lineData[i] != 0){
          indices.amountSeen++;
          indices.lastIndex = i;
          if(indices.firstIndex == -1){
            indices.firstIndex = i;
          }
        }*/
      }

      /* TEMP
          Confirmed: Sending a negative 1 to a PT6961 kills it.
                      There needs to be a guard against this. ( See below for basic,
                      kiddy way of doing it )
      */
      
  
      return indices;
  }




