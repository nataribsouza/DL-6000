#include "Led.h"

void Led::setup() {
    //RSTPINCFG

    // PORTA.DIR |= RED;
    pinMode(3, OUTPUT);
    PORTA.DIR |= GREEN;
    PORTA.DIR |= BLUE;
}

void Led::turnOn(uint8_t led) {
    switch (led) {
    case 0: PORTA.OUT |= RED; break;
    case 1: PORTA.OUT |= GREEN; break;
    case 2: PORTA.OUT |= BLUE; break;
    case 3: PORTA.OUT |= RED; PORTA.OUT |= BLUE; break;                           // Liga o LED na cor roxo
    case 4: PORTA.OUT |= RED; PORTA.OUT |= GREEN; break;                          // Liga o LED na cor amarela
    }
}

/*
void Led::blink(uint8_t led, uint16_t period) {
    if ((millis() - time) >= period) {
        isLedOn = !isLedOn;
        if (isLedOn) {
            turnOn(led);
            time = millis();
        }   else {
            turnAllOff();
            time = millis();
        }
    }
}
*/

void Led::blink(uint8_t led, uint16_t highTime, uint16_t lowTime) {
    if (!digitalRead(3) && (millis() - ledTimer) >= lowTime) {
        turnOn(led);
        ledTimer = millis();
    } else if (digitalRead(3) && (millis() - ledTimer >= highTime)) {
        turnAllOff();
        ledTimer = millis();
    }
}

void Led::turnAllOff() {
    PORTA.OUT &= ~RED;
    PORTA.OUT &= ~GREEN;
    PORTA.OUT &= ~BLUE;
}

/*
void Led::yellow() {
    analogWrite(RED, PWM_255);                                                   // Combinando vermelho com verde nestas 
    analogWrite(GREEN, PWM_250);                                                 // proporções, obtem-se amarelo
}

void Led::orange() {
    analogWrite(RED, PWM_255);                                                    // Combinando vermlho com verde nestas 
    analogWrite(GREEN, PWM_110);                                                  // proporções, obtem-se laranja
}
*/

Led led;