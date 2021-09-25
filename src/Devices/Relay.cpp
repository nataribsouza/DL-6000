#include "Relay.h"

void Relay::setup() {
    PORTA.DIR |= RELAY;
}

void Relay::turnOn() {
    PORTA.OUT |= RELAY;
}

void Relay::turnOff() {
    PORTA.OUT &= ~RELAY;
}

Relay relay;