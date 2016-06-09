#include "LightRunner.h"
#include "FlickerLights.h"
#include "StrobeLights.h"
#include "ConstantLight.h"

const int MODE_ARRAY_SIZE = 12;
const int LED_AMOUNT = 3;
const int UPPER_BOUNDS = MODE_ARRAY_SIZE - LED_AMOUNT;

const int BUTTON_INPUT_PIN = 2;
// How long to wait before switching modes
const int BUTTON_READ_MS = 1000;

// Pins that the LEDS are on
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

  //Button Init Pull Up
  pinMode(BUTTON_INPUT_PIN,INPUT);
  digitalWrite(BUTTON_INPUT_PIN, HIGH);

  //Populate Light Runners
  //Flicker and 1 Constant
  lightRunnders[0] = &fl1;
  lightRunnders[1] = &fl2;
  lightRunnders[2] = &cl1;

  //All Flicker
  lightRunnders[3] = &fl1;
  lightRunnders[4] = &fl2;
  lightRunnders[5] = &fl3;

  //Constant On High
  lightRunnders[6] = &constantBright1;
  lightRunnders[7] = &constantBright2;
  lightRunnders[8] = &constantBright3;

  //Strobe off beat pulse
  lightRunnders[9] = &sl1;
  lightRunnders[10] = &sl2;
  lightRunnders[11] = &sl3;
}

void loop()  {
  for(int i = 0; i < LED_AMOUNT; i++){
    lightRunnders[basePtr+i]->run();
  }

  b1 = digitalRead(BUTTON_INPUT_PIN);

  if(b1 == 0){
    if( b1 != buttonPrevious){
      buttonReadMillis = millis();
    }
    currentMillis = millis();
    if( currentMillis - buttonReadMillis >= BUTTON_READ_MS ){
      buttonReadMillis = currentMillis;
      if(basePtr <= UPPER_BOUNDS){
         basePtr += LED_AMOUNT;
      }else{
        basePtr = 0;
      }
    }
  }
  buttonPrevious = b1;
}
