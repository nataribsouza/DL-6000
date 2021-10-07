#include "Thermocouple.h"

void Thermocouple :: setup() {
    pinMode(THERMOCOUPLE, INPUT);
}

uint16_t Thermocouple::read() {
    if (readingsNumber <= NUMBER_OF_READINGS && (millis() - thermocoupleTimer) >= TIME_BETWEEN_READINGS) {
        currentTemperature += analogRead(THERMOCOUPLE);
        thermocoupleTimer = millis();
        readingsNumber++;
    } 
    if (readingsNumber > NUMBER_OF_READINGS) {
        currentTemperature /= NUMBER_OF_READINGS;
        lastTemperature = currentTemperature;
        currentTemperature = 0;
        readingsNumber = 0;
    }
    return lastTemperature;

}

Thermocouple thermocouple;