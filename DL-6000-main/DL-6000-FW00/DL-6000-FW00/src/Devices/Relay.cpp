#include "Relay.h"

void Relay::setup() {
    // pinMode(RELAY, OUTPUT);
    PORTA.DIR |= RELAY;
}

void Relay::turnOn() {
    // digitalWrite(RELAY, HIGH);
    PORTA.OUT |= RELAY;
}

void Relay::turnOff() {
    // digitalWrite(RELAY, LOW);
    PORTA.OUT &= ~RELAY;
}

Relay relay;