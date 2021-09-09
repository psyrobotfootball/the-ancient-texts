/*
 * Penn State York Robotics Football Team
 * File name: Output.ino
 * Purpose: Produces standard output
 * Last edited: 2/5/2020
 * Version 1.0
 */

void CHOutput(){

  // Prints standard output to the serial monitor
  Serial.print(" CH0 ");
  Serial.print(channel[0]);
  Serial.print(" CH1 ");
  Serial.print(channel[1]);
  Serial.print(" CH2 ");
  Serial.print(channel[2]);
  Serial.print(" MOVE ");
  Serial.print(MOVE);
  Serial.print(" ABS MOVE ");
  Serial.println(abs(MOVE));
  
}
