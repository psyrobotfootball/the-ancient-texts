/*
 * Penn State York Robotics Football Team
 * File name: Move.ino
 * Purpose: Preforms movement constraints
 * Last edited: 2/6/2020
 * Version 1.1
 */

 #include<math.h> // Imports math
 #define pi acos(-1.0) // Defines pi as 3.14......

// @return MOVE This function returns the move command
int Move(){

  MOVE = map(channel[0], 1000,2000,-500,500); // Centers value over zero
  
  // Filtering 
  MOVE = filterMove(0);
  MOVE = constrain(MOVE, -255,255); // Valid PWM Values

  return MOVE;

}

// @param cNumber Imports the channel number
// @return MOVE Returns the movement speed
double filterMove(int cNumber){
  double Movement;
  double filtering = asin((channel[cNumber]-1490) /  500.0); // Smooths out curve using inverse tangent function
  filtering = filtering * (2.0 / pi); // Cancels out normal trig Function
  Movement = filtering * 255; // sets amplitude to 255 at 500 or -255 at -500 Note: 285 because of margin error

  return Movement; 
  
}
