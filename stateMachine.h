
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
  
  //gets data and sends ouput to wheels
  void drive(const SensorIndices& data);

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

  
  
  // interprets data that was read from the line sensors.
  // Specifically returns the first index, last index, and amount seen.
  // this may be redundant because if we know the first index and the 
  // amount seen, we can easily calculate the last index with firstIndex + amountSeen.
  SensorIndices interpretData(int dataNum); 

 
  
}

#endif
