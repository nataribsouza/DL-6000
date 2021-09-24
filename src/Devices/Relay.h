#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

#define RELAY PIN7_bm

class Relay{
    public:
        void setup();
        void turnOn();
        void turnOff();
};

extern Relay relay;
#endif