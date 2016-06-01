#include "StrobeLights.h"

StrobeLights::StrobeLights(int pin, int duration){
    this->pin = pin;
    this->duration = duration;
    this->running = true;
    pinMode(pin, OUTPUT);
}

virtual void StrobeLights::run() override {
    long currentMillis = millis();
    if(currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;
        if(digitalRead(pin) == HIGH){
            digitalWrite(pin, LOW);    
        }
        if(digitalRead(pin) == LOW){
            digitalWrite(pin, HIGH);    
        }
    }
}
