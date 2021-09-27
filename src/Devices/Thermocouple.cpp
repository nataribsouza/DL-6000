#include "Thermocouple.h"

void Thermocouple::setup() {
    pinMode(THERMOCOUPLE, INPUT);
}

uint16_t Thermocouple::read() {
    unsigned int temperature = analogRead(THERMOCOUPLE);
    return temperature;
}

Thermocouple thermocouple;