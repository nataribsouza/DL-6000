#include "Thermocouple.h"

void Thermocouple::setup() {
    pinMode(THERMOCOUPLE, INPUT);
}

uint16_t Thermocouple::read() {
    uint16_t temperature = analogRead(THERMOCOUPLE);
    return temperature;
}

Thermocouple thermocouple;