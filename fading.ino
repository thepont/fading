
#include "FlickerLights.h"

FlickerLights fl1(9, 255, 150, 170, 0, 0, 20);
FlickerLights fl2(10, 255, 110, 170, 110, 6, 60);

int buttonInput = 2;
int buttonPrevious = 0;
void setup()  { 
  Serial.begin(9600);
  
  //Button Init.
  pinMode(buttonInput,INPUT);
  digitalWrite(buttonInput, HIGH);   
} 

void loop()  {  
  fl1.ficker();
  fl2.ficker();
    
  int b1 = digitalRead(buttonInput);
  if(b1 == 0 && b1 != buttonPrevious){
    fl1.toggleRunning();
    fl2.toggleRunning();
  }
  buttonPrevious = b1;
}
