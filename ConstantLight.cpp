#include "ConstantLight.h"

ConstantLight::ConstantLight(int pin, int amount){
  this->amount = amount;
  this->running = true;
  
  
}

void ConstantLight::run(){
//  if(running){
    long currentMs = millis(); 
    if( currentMs - lastWriteMs >= 1000 ){
      lastWriteMs = currentMs;
      Serial.print(amount);
      analogWrite(pin, amount);
    }
    
//
}

