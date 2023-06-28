/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab5/src/Lab5.ino"

void setup();
void loop();
#line 2 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab5/src/Lab5.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

//internal variables
int current_min = 5000;
int current_max = 0; 
int potentiometer_voltage;

void setup() {

  //initialize pins
  pinMode(A5, INPUT);
  pinMode(D5, OUTPUT);

}

void loop() {

  //maps output to (0,255) then lights up the light with the power
  potentiometer_voltage = analogRead(A5);
  current_min = min(current_min, potentiometer_voltage);
  current_max = max(current_max, potentiometer_voltage);

  int light_brightness = map(potentiometer_voltage, current_min, current_max, 0, 255);
  analogWrite(D5, light_brightness);
  
}

