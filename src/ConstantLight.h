
#ifndef ConstantLight_h
#define ConstantLight_h

#include "Arduino.h"
#include "LightRunner.h"

class ConstantLight: public LightRunner
{
  public:
    ConstantLight(int pin, int amount);
    void run() override;
  private:
    int amount;
    long lastWriteMs = 0;
};
#endif
