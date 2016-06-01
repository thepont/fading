#include "StrobeLights.h"

StrobeLights::StrobeLights(int pin, int duration){
    this->pin = pin;
    this->duration = duration;
    this->running = true;
    pinMode(pin, OUTPUT);
}

void StrobeLights::run() {
    long currentMillis = millis();
    if(currentMillis - previousMillis > duration) {
        previousMillis = currentMillis;
        if(digitalRead(pin) == HIGH){
            digitalWrite(pin, LOW);    
        }
        if(digitalRead(pin) == LOW){
            digitalWrite(pin, HIGH);    
        }
    }
}
