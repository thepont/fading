#ifndef LightRunner_h
#define LightRunner_h

#include "Arduino.h"

class LightRunner
{
    public:
        virtual void run() = 0;
        void toggleRunning(){
            running = !running;
            if(!running){
                analogWrite(pin, 0);
            }
        };
    protected:
        int pin;
        bool running;
};
#endif
