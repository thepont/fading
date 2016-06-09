#include "LightRunner.h"
#include "FlickerLights.h"
#include "StrobeLights.h"
#include "ConstantLight.h"

const int BUTTON_INPUT = 2;
const int MODE_ARRAY_SIZE = 12;
const int LED_1_PIN = 9;
const int LED_2_PIN = 10;
const int LED_3_PIN = 11;


FlickerLights fl1(LED_1_PIN, 255, 150 , 170, 0, 0, 10);
FlickerLights fl2(LED_2_PIN, 160, 40, 170, 10, 6, 60);
FlickerLights fl3(LED_3_PIN, 40, 10, 90, 10, 6, 60);

ConstantLight cl1(LED_2_PIN, 20);

StrobeLights sl1(LED_1_PIN, 60);
StrobeLights sl2(LED_2_PIN, 50);
StrobeLights sl3(LED_3_PIN, 50);

ConstantLight constantBright1(LED_1_PIN, 255);
ConstantLight constantBright2(LED_2_PIN, 255);
ConstantLight constantBright3(LED_3_PIN, 255);

LightRunner * lightRunnders[MODE_ARRAY_SIZE];

int basePtr = 0;
int buttonPrevious = 0;
long currentMillis;
long buttonReadMillis;
int b1;

void setup(){
  // Serial.begin(9600);

  //Button Init.
  pinMode(BUTTON_INPUT,INPUT);
  digitalWrite(BUTTON_INPUT, HIGH);

  //Populate Light Runners
  lightRunnders[0] = &fl1;
  lightRunnders[1] = &fl2;
  lightRunnders[2] = &cl1;

  lightRunnders[3] = &fl1;
  lightRunnders[4] = &fl2;
  lightRunnders[5] = &fl3;

  lightRunnders[6] = &constantBright1;
  lightRunnders[7] = &constantBright2;
  lightRunnders[8] = &constantBright3;

  lightRunnders[9] = &sl1;
  lightRunnders[10] = &sl2;
  lightRunnders[11] = &sl3;
}

void loop()  {
  lightRunnders[basePtr]->run();
  lightRunnders[basePtr+1]->run();
  lightRunnders[basePtr+2]->run();

  b1 = digitalRead(BUTTON_INPUT);

  if(b1 == 0){
    if( b1 != buttonPrevious){
      buttonReadMillis = millis();
    }
    currentMillis = millis();
    if( currentMillis - buttonReadMillis >= 1000 ){
      buttonReadMillis = currentMillis;
      if(basePtr <= 9){
         basePtr+=3;
      }else{
        basePtr = 0;
      }
    }
  }
  buttonPrevious = b1;
}
