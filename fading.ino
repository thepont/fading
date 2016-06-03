#include "LightRunner.h"
#include "FlickerLights.h"
#include "StrobeLights.h"
#include "ConstantLight.h"

FlickerLights fl1(9, 255, 150 , 170, 0, 0, 10);
FlickerLights fl2(10, 160, 40, 170, 10, 6, 60);
FlickerLights fl3(11, 40, 10, 90, 10, 6, 60);

ConstantLight cl1(11, 20);

StrobeLights sl1(9, 60);
StrobeLights sl2(10, 50);
StrobeLights sl3(11, 50);

ConstantLight constantBright1(9, 254);
ConstantLight constantBright2(10, 254);
ConstantLight constantBright3(11, 254);

LightRunner * lightRunnders[12];

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
  lightRunnders[2] = &cl1;
  
  lightRunnders[3] = &fl1;
  lightRunnders[4] = &fl2;
  lightRunnders[5] = &fl3;
  
  lightRunnders[6] = &sl1;
  lightRunnders[7] = &sl2;
  lightRunnders[8] = &sl3;
  
  lightRunnders[9] = &constantBright1;
  lightRunnders[10] = &constantBright2;
  lightRunnders[11] = &constantBright3;

} 

long currentMillis;
long buttonReadMillis;

void loop()  {  
//  fl1.ficker()
//  fl2.ficker();
  lightRunnders[basePtr]->run();
  lightRunnders[basePtr+1]->run();
  lightRunnders[basePtr+2]->run();
  int b1 = digitalRead(buttonInput);
  
  if(b1 == 0){
    if( b1 != buttonPrevious){
      buttonReadMillis = millis(); 
    }
    currentMillis = millis();
    if( currentMillis - buttonReadMillis >= 1000 ){
      buttonReadMillis = currentMillis;
      if(basePtr != 9){
         Serial.print("Light Mode");
         basePtr+=3;
         Serial.print(basePtr / 3);
      }else{
        Serial.println("Zero");
        basePtr = 0;
      }
    }
    //fl1.toggleRunning();
    //fl2.toggleRunning();
  }
  buttonPrevious = b1;
}
