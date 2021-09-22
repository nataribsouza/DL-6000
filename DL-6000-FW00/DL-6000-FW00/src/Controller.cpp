#include "Controller.h"

void Controller::setup() {
    led.setup();
    relay.setup();
    button.setup();
    thermocouple.setup();
}

void Controller::loop() {   
    switch (menu) {
        case 0:
            standby();
            break;
        case 1:
            //onHot();
            break;
        case 2:
            //onCold();
            break;
    }    
}

void Controller::standby() {
    led.blink(RED, SMALL_BLINK, BIG_BLINK);
}

/*
void Controller::onHot() {
    relay.turnOn();
    led.blink(setLedCollor(), BLINK_SHORT);
    // led.blink(0, BLINK_SHORT);
    button.read();

    if (button.buttonLongPress || thermocouple.read() >= MAX_TEMP) {
        menu++;
    }
}

void Controller::onCold() {
    relay.turnOff();
    led.turnAllOff();
    led.turnOn(setLedCollor());
    // led.turnOn(2);
    // led.turnOn(0);
    button.read();

    if (button.buttonLongPress && (thermocouple.read() < MAX_TEMP)) {
        menu = 1;
    }
}

uint8_t Controller::setLedCollor() {
    uint16_t temperature = thermocouple.read();

    if (temperature <= 100) {
        return 2;
    } else if (temperature <= 200) {
        return 3;
    } else {
        return 0;
    }
}
*/

Controller controller;