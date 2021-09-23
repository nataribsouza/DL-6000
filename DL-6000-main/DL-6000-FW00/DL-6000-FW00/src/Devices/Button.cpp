#include "Button.h"

void Button::setup() {
    PORTA.DIRCLR = BUTTON;
}
/*
void Button::read() {
    boolean buttonLevel = ~PORTA.IN & BUTTON;

    if (buttonLevel && !wasButtonPressed) {
        wasButtonPressed = true;
        time = millis();
    } else if (!buttonLevel && wasButtonPressed && !buttonLongPress) {
        if ((millis() - time) >= PRESSED_TIME) {
            buttonLongPress = true;
            wasButtonPressed = false;
        } else {
            buttonLongPress = false;
            wasButtonPressed = false;
        }
    } else if (!buttonLevel && !wasButtonPressed) {
        buttonLongPress = false;
        wasButtonPressed = false;
    }
}

void Button::read() {
    boolean buttonLevel = ~PORTA.IN & BUTTON;

    if (buttonLevel && !wasButtonPressed) {
        wasButtonPressed = true;
        buttonLongPress = true;
    } else if (buttonLevel && wasButtonPressed) {
        buttonLongPress = false;
    } else if (!buttonLevel) {
        wasButtonPressed = false;
        buttonLongPress = false;
    }
}
*/
boolean Button::read() {
    boolean buttonLevel = ~PORTA.IN & BUTTON;

    if (buttonLevel && !buttonPressed) {
        buttonCounter++;
        delay(10);
    }
    if (buttonCounter >= 100 && !buttonPressed) {
        buttonPressed = true;
        return true;
    }
    if (!buttonLevel) {
        buttonCounter = 0;
        buttonPressed = false;
    }

    return false;
}

boolean Button::getButtonLevel() {
    return ~PORTA.IN & BUTTON;
}

Button button;