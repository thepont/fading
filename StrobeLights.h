
#ifndef StrobeLights_h
#define StrobeLights_h

#include "Arduino.h"

class StrobeLights
{
  public:
    StrobeLights(int pin, int duration);
    void run() override;
  private:
    int duration;
    long currentMillis;
};
#endif