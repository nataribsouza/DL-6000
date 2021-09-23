#include "Thermocouple.h"

void Thermocouple::setup() {
    pinMode(THERMOCOUPLE, INPUT);
    /*
    ADCA.CTRLA |= THERMOCOUPLE;
    ADCA.MUXPOS = 0X06;
    */
}

uint16_t Thermocouple::read() {
    uint16_t temperature = 0;

    // ADCA.STCONV = 0x01;
    // temperature = ADCA.RES;
    // temperature = ((VOLTAGE_REF * analogRead(THERMOCOUPLE) / RESOLUTION) - ONE_HUNDRED_MARK) * CELSIUS_FACTOR;
    
    temperature = analogRead(THERMOCOUPLE) * VOLTAGE_REF;
    temperature /= RESOLUTION;
    temperature -= ONE_HUNDRED_MARK;
    temperature *= CELSIUS_FACTOR; 

    return temperature;
}

Thermocouple thermocouple;