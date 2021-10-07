#include "Button.h"

void Button::setup() {
    PORTA.DIRCLR = BUTTON;
}

boolean Button::read() {
    boolean buttonLevel = ~PORTA.IN & BUTTON;

    if (buttonLevel && !buttonPressed) {
        buttonCounter++;
        delay(1);
    }
    if (buttonCounter >= PRESSED_TIME && !buttonPressed) {
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