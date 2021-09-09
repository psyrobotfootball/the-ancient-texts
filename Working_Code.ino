/*
 * Penn State York Robotics Football Team
 * File name: Main.ino
 * Purpose: To be the main executable file for the runningback robot
 * Last edited: 2/8/2020
 * Version 1.2
 */

// Initializes variables to pins
// #define statements are not comments!
#define RIGHT_R_EN 22
#define RIGHT_L_EN 24
#define RIGHT_RPWM 9
#define RIGHT_LPWM 10

#define LEFT_R_EN 26
#define LEFT_L_EN 28
#define LEFT_RPWM 3
#define LEFT_LPWM 11



double channel[2]; // Channel list

int MOVE; // Intializes the MOVE variable


void setup() {
  pinMode(13, INPUT); // Forward & Reverse 
  pinMode(4, INPUT); // Left & Right Stick

  channel[0] = pulseIn(13, HIGH); // Forward & Reverse Stick
  channel[1] = pulseIn(4, HIGH); // Left & Right Stick


  Serial.begin(9600); // Braudrate
  
  // Right Motor
  pinMode(RIGHT_R_EN, OUTPUT); // Right enable declared as an output
  pinMode(RIGHT_L_EN, OUTPUT); // Left enable declared as an output

  digitalWrite(RIGHT_R_EN, LOW); // Right enable set to off
  digitalWrite(RIGHT_L_EN, LOW); // Left enable set to off

  pinMode(RIGHT_RPWM, OUTPUT); // Right PWM declared as an output
  pinMode(RIGHT_LPWM, OUTPUT); // Left PWM declared as an output

  analogWrite(RIGHT_RPWM, 0); // Right PWM turned off
  analogWrite(RIGHT_LPWM, 0); // Left PWM turned off
  

  // Left Motor
  pinMode(LEFT_R_EN, OUTPUT); // Right enable declared as an output
  pinMode(LEFT_L_EN, OUTPUT); // Left enable declared as an output

  digitalWrite(LEFT_R_EN, LOW); // Right enable set to off
  digitalWrite(LEFT_L_EN, LOW); // Left enable set to off

  pinMode(LEFT_RPWM, OUTPUT); // Right PWM declared as an output
  pinMode(LEFT_LPWM, OUTPUT); // Left PWM declared as an output

  analogWrite(LEFT_RPWM, 0); // Right PWM turned off
  analogWrite(LEFT_LPWM, 0); // Left PWM turned off

  
}




void loop() { // Loops the program

  channel[0] = pulseIn(13, HIGH); // Forward & Reverse Stick
  channel[1] = pulseIn(4, HIGH); // Left & Right Stick

  CHOutput(); // See file for the output string
  
  forward(Move()); // Executes forward movement

  backward(Move()); // Executes backward movement

}
