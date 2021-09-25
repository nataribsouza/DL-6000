#ifndef Thermocouple_h
#define Thermocouple_h

#include "Arduino.h"
#include <avr/io.h>

#define THERMOCOUPLE 0
#define RESOLUTION 1023
#define VOLTAGE_REF 5
#define ONE_HUNDRED_MARK 53
#define CELSIUS_FACTOR 200

class Thermocouple {
    public:
        void setup();
        uint16_t read();
    private:
};

extern Thermocouple thermocouple;
#endif