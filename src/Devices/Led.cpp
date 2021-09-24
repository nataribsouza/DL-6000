#include "Led.h"

void Led::setup() {
    PORTA.DIR |= RED;
    PORTA.DIR |= GREEN;
    PORTA.DIR |= BLUE;

    PORTA.OUT &= ~GREEN;
}

void Led::turnOn(uint8_t led) {
    switch (led) {
    case 0: PORTA.OUT |= RED; break;
    case 1: PORTA.OUT |= GREEN; break;
    case 2: PORTA.OUT |= BLUE; break;
    case 3: PORTA.OUT |= RED; PORTA.OUT |= BLUE; break;                           // Liga o LED na cor roxo
    case 4: PORTA.OUT |= RED; PORTA.OUT |= GREEN; break;                          // Liga o LED na cor amarela
    case 5: 
            PORTA.OUT |= RED; 
            PORTA.OUT |= GREEN; 
            PORTA.OUT |= BLUE;
            break;                         

    }
}

void Led::turnAllOff() {
    PORTA.OUT &= ~RED;
    PORTA.OUT &= ~GREEN;
    PORTA.OUT &= ~BLUE;
}

void Led::blink(uint8_t led, uint16_t highTime, uint16_t lowTime) {
    if (!getLedLevel(led) && (millis() - ledTimer) >= lowTime) {
        turnOn(led);
        ledTimer = millis();
    } else if (getLedLevel(led) && (millis() - ledTimer >= highTime)) {
        turnAllOff();
        ledTimer = millis();
    }
}

boolean Led::getLedLevel(uint8_t led) {
    switch (led) {
    case 0: return PORTA.IN & RED;
    case 1: return PORTA.IN & GREEN;
    case 2: return PORTA.IN & BLUE;
    case 3: 
    case 4: 
    case 5: return PORTA.IN & RED;           
    }
}

Led led;