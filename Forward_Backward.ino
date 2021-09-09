/*
 * Penn State York Robotics Football Team
 * File name: Forward_Backward.ino
 * Purpose: Preforms forwards and backwards movements
 * Last edited: 2/8/2020
 * Version 1.1
 */

// @param Move Finds the direction the controller wants the robot to move
void forward(int MOVE){

  // If the controller is pushed up the robot will move forwards
  if(channel[0] > 1550){ 
    digitalWrite(RIGHT_R_EN, HIGH); // Right enable set to on for the right motor controller
    digitalWrite(RIGHT_L_EN, HIGH); // Left enable set to on for the right motor controller
    analogWrite(RIGHT_LPWM, abs(MOVE) - abs(rightSlow())); // Commands the right motor to go forward; Subtracts the turning speed

    digitalWrite(LEFT_R_EN, HIGH); // Right enable set to on for the left motor controller
    digitalWrite(LEFT_L_EN, HIGH); // Left enable set to on for the left motor controller
    analogWrite(LEFT_RPWM, abs(MOVE) - abs(leftSlow())); // Commands the left motor to go forward; Subtracts the turning speed
    }
    
    else {
      analogWrite(RIGHT_LPWM, 0); // Turns the right motor off
      analogWrite(LEFT_RPWM, 0); // Turns the left motor off
    };
}


// @param Move Finds the direction the controller wants the robot to move
void backward(int MOVE){

  // If the controller is pushed down the robot will move backwards
  if(channel[0] < 1450){
      digitalWrite(RIGHT_R_EN, HIGH); // Right enable set to on for the right motor controller
      digitalWrite(RIGHT_L_EN, HIGH); // Left enable set to on for the right motor controller
      analogWrite(RIGHT_RPWM, abs(MOVE) - abs(rightSlow())); // Commands the right motor to go backwards; Subtracts the turning speed
  
      digitalWrite(LEFT_R_EN, HIGH); // Right enable set to on for the left motor controller
      digitalWrite(LEFT_L_EN, HIGH); // Commands the left motor to go forward
      analogWrite(LEFT_LPWM, abs(MOVE) - abs(leftSlow())); // Commands the left motor to go backwards; Subtracts the turning speed
   }

   else{
      analogWrite(LEFT_LPWM, 0); // Turns the right motor off
      analogWrite(RIGHT_RPWM, 0); // Turns the left motor off
   };
  
  
}
