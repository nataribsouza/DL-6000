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
void Button::read() {
    boolean buttonLevel = ~PORTA.IN & BUTTON;

    if (buttonLevel) {
        counter ++;
        delay(10);
    }
    if (counter >= 100 && !buttonLongPress) {
        buttonLongPress = true;
    } else if (!buttonLevel && buttonLongPress){
        buttonLongPress = false;
        counter = 0;
    }
}

Button button;