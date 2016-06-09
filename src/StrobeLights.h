
#ifndef StrobeLights_h
#define StrobeLights_h

#include "Arduino.h"
#include "LightRunner.h"

class StrobeLights: public LightRunner
{
  public:
    StrobeLights(int pin, int duration);
    void run() override;
  private:
    int duration;
    long previousMillis;
    boolean on;
};
#endif
