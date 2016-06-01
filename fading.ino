#include "LightRunner.h"
#include "FlickerLights.h"
#include "StrobeLights.h"
//FlickerLights fl1(9, 255, 150, 170, 0, 0, 20);
//FlickerLights fl2(10, 255, 110, 170, 110, 6, 60);
StrobeLights sl1(9, 60);
StrobeLights sl2(10, 50);


int buttonInput = 2;
int buttonPrevious = 0;
void setup(){
  Serial.begin(9600);
  
  //Button Init.
  pinMode(buttonInput,INPUT);
  digitalWrite(buttonInput, HIGH);   
} 

void loop()  {  
//  fl1.ficker();
//  fl2.ficker();
  sl1.run();
  sl2.run();
  
  int b1 = digitalRead(buttonInput);
  if(b1 == 0 && b1 != buttonPrevious){
    sl1.toggleRunning();
    sl2.toggleRunning();
    //fl1.toggleRunning();
    //fl2.toggleRunning();
  }
  buttonPrevious = b1;
}
