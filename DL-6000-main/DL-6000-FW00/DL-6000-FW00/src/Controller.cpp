#include "Controller.h"

void Controller::setup() {
    led.setup();
    relay.setup();
    button.setup();
    thermocouple.setup();
}

void Controller::loop() {   
    if (menu >= MENU_NUMBER) {
        menu = 0;
    }

    switch (menu) {
        case 0: standby(); break;
        case 1: warmingUp(); break;
        case 2: finished(); break;
    }    
}

void Controller::standby() {
    relay.turnOff();
    buttonHandler();
    if (button.getButtonLevel()) {
        led.turnOn(WHITE);
    } else {
        led.blink(RED, SMALL_BLINK, BIG_BLINK);
    }
}


void Controller::warmingUp() {
    relay.turnOn();
    buttonHandler();
    
    if (button.getButtonLevel()) {
        led.turnOn(WHITE);
    } else {
        led.blink(setLedCollor(), SMALL_BLINK, MEDIUM_BLINK);
    }

    if (thermocouple.read() >= MAX_TEMPERATURE) menu++;
}

void Controller::finished() {
    relay.turnOff();
    buttonHandler();
    
    if (button.getButtonLevel()) {
        led.turnOn(WHITE);
    } else {
        led.blink(setLedCollor(), SMALL_BLINK, 0);
    }

    if (thermocouple.read() <= RST_TEMPERATURE) menu = 0;
}

void Controller::buttonHandler() {
    switch (menu) {
        case 0:
            if (button.read() && (thermocouple.read() < MAX_TEMPERATURE)) {
                led.turnAllOff();
                menu++;
            }
            break;

        case 1:
        case 2:
            if (button.read()) {
                led.turnAllOff();
                menu = 0;
            }
            break;
    }
}

uint8_t Controller::setLedCollor() {
    uint16_t temperature = thermocouple.read();

    if (temperature <= 100) {
        return 2;
    } else if (temperature <= 140) {
        return 3;
    } else if (temperature <= 180) {
        return 4;
    } else {
        return 0;
    }
}

Controller controller;