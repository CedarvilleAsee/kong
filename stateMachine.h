#include <Servo.h>


#ifndef STATE_MACHINE
#define STATE_MACHINE



namespace stateMachine{
  
  /*
   * UPDATE:
   *      Possibly unnecessary, but more self-explanitory than an array.
   */
 struct SensorIndices {
    int firstIndex;
    int lastIndex;
    int amountSeen;
  };

  /**
   * Attaches the Servos for output.
   */
  void initServos();
  
  //gets data and sends ouput to wheels
  void drive(const stateMachine::SensorIndices& data, Servo dump, Servo scoop, Servo clobber);

  //outputs values to wheels 
   void writeToWheels( int leftSpeed, int rightSpeed );

  //reads data from line sensors
  /*
   * UPDATE:
   *      The board was giving confusing data, and the compiler warned against returning 
   *      a pointer to a local array. When I switched it to a mutator method, the compiler
   *      no longer complained and the data was much more consistent. I believe, though 
   *      annoying, this way must be used unless a better way is found.
   */
  int readData();

  
  void ejectBarrel(Servo clobber);

  
  // interprets data that was read from the line sensors.
  // Specifically returns the first index, last index, and amount seen.
  // this may be redundant because if we know the first index and the 
  // amount seen, we can easily calculate the last index with firstIndex + amountSeen.
  SensorIndices interpretData(int dataNum); 

 
  
}

#endif
