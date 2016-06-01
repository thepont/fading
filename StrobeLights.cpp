#include "StrobeLights.h"

StrobeLights::StrobeLights(int pin, int duration){
    this->pin = pin;
    this->duration = duration;
    this->running = true;
    this->on = false;
    pinMode(pin, OUTPUT);
}

void StrobeLights::run() {
    if(running){
      long currentMillis = millis();
      if(currentMillis - previousMillis > duration) {
          previousMillis = currentMillis;
          if(on){
              on = false;
              digitalWrite(pin, LOW);    
          } else {
              on = true;
              digitalWrite(pin, HIGH);    
          }
      }
    }
}
