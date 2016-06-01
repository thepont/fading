#ifndef FlickerLights_h
#define FlickerLights_h

#include "Arduino.h"
#include "LightRunner.h"


class FlickerLights: public LightRunner
{
  public:
    FlickerLights(int pin, int upperValueHigh, int upperValueLow, int lowerValueHigh, int lowerValueLow, int intervalLow, int intervalHigh);
    void run() override;
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
