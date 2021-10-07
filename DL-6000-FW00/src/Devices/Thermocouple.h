#ifndef Thermocouple_h
#define Thermocouple_h

#include "Arduino.h"
#include <avr/io.h>

#define THERMOCOUPLE 0
#define NUMBER_OF_READINGS 20
#define TIME_BETWEEN_READINGS 2

class Thermocouple {
    public:
        void setup();
        uint16_t read();

    private:
    uint8_t readingsNumber = 0;
    uint16_t lastTemperature = 0;
    unsigned long int currentTemperature = 0;

    unsigned int thermocoupleTimer = 0;
};

extern Thermocouple thermocouple;
#endif