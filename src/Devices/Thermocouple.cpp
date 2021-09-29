#include "Thermocouple.h"

void Thermocouple::setup() {
    pinMode(THERMOCOUPLE, INPUT);
}

uint16_t Thermocouple::read() {
    unsigned long int temperature = 0;

    for (uint8_t i = 0; i <= READINGS_NUMBER; i++) {
        temperature += analogRead(THERMOCOUPLE);
        delay(1);
    }

    temperature /= READINGS_NUMBER;
    return temperature;
}

Thermocouple thermocouple;