/*
 * Penn State York Robotics Football Team
 * File name: Turns.ino
 * Purpose: Preforms turning movements
 * Last edited: 2/8/2020
 * Version 1.2
 */

// @return boolean Returns true/flase based on if the robot should or should not move
double  leftSlow(){

  double TURN;
  
  TURN = map(channel[1], 1000, 2000, -500, 500); // Centers value over zero
  TURN = filterMove(1);
  TURN = constrain(TURN, -255, 255); // Valid PWM Values


  if(channel[0] > 1550 && channel[1] < 1450) { // Forwards Left
      return TURN/4;
  }

  else if(channel[0] < 1450 && channel[1] < 1450) { // Backwards Left
      return TURN/4;
  }

  else{ // If their is no turn 
      return 0;
  }
}



// @return TURN Returns the turn slow speed
double  rightSlow(){

  double TURN;
  
  TURN = map(channel[1], 1000, 2000, -500, 500); // Centers value over zero
  TURN = filterMove(1);
  TURN = constrain(TURN, -255, 255); // Valid PWM Values


  if(channel[0] > 1550 && channel[1] > 1550) { // Forwards Right
      return TURN/4;
  }

  else if(channel[0] < 1450 && channel[1] > 1550) { // Backwards Right
      return TURN/4;
  }

  else{ // If their is no turn
      return 0;
  }
  
}
