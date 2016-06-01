/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef FlickerLights_h
#define FlickerLights_h

#include "Arduino.h"

class FlickerLights
{
  public:
    FlickerLights(int pin, int upperValueHigh, int upperValueLow, int lowerValueHigh, int lowerValueLow, int intervalLow, int intervalHigh);
    void ficker();
    void toggleRunning();
  private:
    int intervalLow;
    int intervalHigh;
    int upperValue;
    int lowerValue;
    int fadeValue= 0;
    int upperValueHigh;
    int upperValueLow;
    int lowerValueHigh;
    int lowerValueLow;   
    int volocity = 5;
    int pin = 0;
    int interval = 0;
    long previousMillis = 0;
    bool running;
};
#endif
