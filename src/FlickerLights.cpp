#include "FlickerLights.h"

FlickerLights::FlickerLights(int pin, int upperValueHigh, int upperValueLow, int lowerValueHigh, int lowerValueLow, int intervalLow, int intervalHigh){
  this->running = true;
  this->pin = pin;
  this->upperValueHigh = upperValueHigh;
  this->upperValueLow = upperValueLow;
  this->lowerValueLow = lowerValueLow;
  this->lowerValueHigh = lowerValueHigh;
  this->intervalLow = intervalLow;
  this->intervalHigh = intervalHigh;
}

void FlickerLights::run(){
  if(running){
    long currentMillis = millis();
    if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      fadeValue += volocity;
      analogWrite(pin, fadeValue);
      if(fadeValue >= upperValue || fadeValue <= lowerValue){
        volocity = -volocity;
        interval = random(intervalLow,intervalHigh);
        upperValue = random(upperValueLow, upperValueHigh);
        lowerValue = random(lowerValueLow, lowerValueHigh);
        fadeValue = volocity < 0 ? upperValue : lowerValue;
      }
    }
  }
}
  
void FlickerLights::toggleRunning(){
    running = !running;
    if(!running){
        analogWrite(pin, 0);
    }
}

