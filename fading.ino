#include "LightRunner.h"
#include "FlickerLights.h"
#include "StrobeLights.h"
FlickerLights fl1(9, 255, 150, 170, 0, 0, 20);
FlickerLights fl2(10, 255, 110, 170, 110, 6, 60);
StrobeLights sl1(9, 60);
StrobeLights sl2(10, 50);

LightRunner * lightRunnders[4];
int basePtr = 0;

int buttonInput = 2;
int buttonPrevious = 0;
void setup(){
  Serial.begin(9600);
  
  //Button Init.
  pinMode(buttonInput,INPUT);
  digitalWrite(buttonInput, HIGH);   
  lightRunnders[0] = &fl1;
  lightRunnders[1] = &fl2;
  lightRunnders[2] = &sl1;
  lightRunnders[3] = &sl2;

} 

void loop()  {  
//  fl1.ficker()
//  fl2.ficker();
  lightRunnders[basePtr]->run();
  lightRunnders[2]->run();
  
  int b1 = digitalRead(buttonInput);
  if(b1 == 0 && b1 != buttonPrevious){
    if(basePtr != 2)
       basePtr+=2;
    else
      basePtr = 0;
    //fl1.toggleRunning();
    //fl2.toggleRunning();
  }
  buttonPrevious = b1;
}
