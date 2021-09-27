#ifndef Thermocouple_h
#define Thermocouple_h

#include "Arduino.h"
#include <avr/io.h>

#define THERMOCOUPLE 0
#define READINGS_NUMBER 100

class Thermocouple {
    public:
        void setup();
        uint16_t read();
    private:
};

extern Thermocouple thermocouple;
#endif