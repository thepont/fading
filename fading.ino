
#include "FlickerLights.h"

FlickerLights fl1(9, 255, 150, 170, 0, 0, 20);
FlickerLights fl2(10, 255, 120, 170, 110, 6, 120);
boolean running = true;
int buttonInput = 2;
int buttonPrevious = 0;
void setup()  { 
  Serial.begin(9600);
  digitalWrite(buttonInput, HIGH);
  pinMode(buttonInput,INPUT);
  // nothing happens in setup 
} 

void loop()  {
  if (running){
    fl1.ficker();
    fl2.ficker();
  }
  int b1 = digitalRead(buttonInput);
  if(b1 = 1 && b1 != buttonPrevious){
    running = !running; 
  }
   Serial.println(b1);
   buttonPrevious = b1;
}
