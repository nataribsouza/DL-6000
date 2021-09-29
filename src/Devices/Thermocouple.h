#ifndef Thermocouple_h
#define Thermocouple_h

#include "Arduino.h"
#include <avr/io.h>

#define THERMOCOUPLE 0
#define READINGS_NUMBER 20

class Thermocouple {
    public:
        void setup();
        uint16_t read();
    private:
    uint8_t numberReadings = 0;
    unsigned long int actualTemperature= 0;
    unsigned int lastTemperature = 0;
};

extern Thermocouple thermocouple;
#endif