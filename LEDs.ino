/* Hayden Orleth-Diener 
   ROBOT_FOOTBALL LEDs
   10/10/2020
  This program is made to display a constant blue color on a defined number of LEDs until a hit is recieved at 
  at which point the lights will all flash red 3 times.*/
#include <FastLED.h>
// Number of LEDs connected to the DATA_PIN 6
#define NUM_LEDS 60
#define DATA_PIN 6

const int buttonPin = 2;
int buttonstate = 0;

// Define an array leds which is used to change individual led data
CRGB leds[NUM_LEDS];


void setup() {
  // Setup for RGB WS2812B LED strip
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  //Sample pinout for a tackle sensor
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Turn the LEDs all Penn State (4,30,66) blue
  changeColor(NUM_LEDS, 4, 30, 66);
  FastLED.show();
  delay(1000);

  //Function call to flash lights red if a sensor is tripped. In this case if a button is held.
  buttonstate = digitalRead(buttonPin);
  if (buttonstate == LOW){
    tackle_flash();
  }
}

// Function to change the color of the leds to a specified RGB setting.
void changeColor(int num_LEDs, int r, int g, int b){
  for (int n = NUM_LEDS; n >= 0; n--) {
    leds[n] = CRGB(r,g,b);
}
}

// Function for Tackle indicator. Flashes the LEDs red 3 times.
void tackle_flash (){
  for (int i = 0; i < 3; i++){
    changeColor(NUM_LEDS,0,0,0);
    FastLED.show();
    delay(100);
    changeColor(NUM_LEDS,100,0,0);
    FastLED.show();
    delay(200);
  }
  
}
