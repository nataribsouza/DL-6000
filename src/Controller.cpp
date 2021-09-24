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
        led.blink(GREEN, SMALL_BLINK, BIG_BLINK);
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
    if (!menu) {
        if (button.read() && (thermocouple.read() < MAX_TEMPERATURE)) {
                led.turnAllOff();
                menu++;
            }
    } else {
        if (button.read()) {
                led.turnAllOff();
                menu = 0;
            }
    }
}

uint8_t Controller::setLedCollor() {
    uint16_t temperature = thermocouple.read();

    if (temperature <= T100) {
        return BLUE;
    } else if (temperature <= T140) {
        return PURPLE;
    } else if (temperature <= T180) {
        return YELLOW;
    } else {
        return RED;
    }
}

Controller controller;