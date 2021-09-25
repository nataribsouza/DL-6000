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
        case STANDBY:    standby(); break;
        case WARMING_UP: warmingUp(); break;
        case FINISHED:   finished(); break;
    }    
}

void Controller::standby() {
    relay.turnOff();
    buttonHandler();
    ledHandler();
}


void Controller::warmingUp() {
    relay.turnOn();
    buttonHandler();
    ledHandler();
    if (thermocouple.read() >= MAX_TEMPERATURE) menu++;
}

void Controller::finished() {
    relay.turnOff();
    buttonHandler();
    ledHandler();
    if (thermocouple.read() < RST_TEMPERATURE) menu = 0;
}

void Controller::buttonHandler() {
    if (button.read() && !menu) {
        if (thermocouple.read() < MAX_TEMPERATURE) {
            menu = 1;
        } else {
            menu = 2;
        }
        wasMenuChanged = true;
    } else if (button.read()) {
        menu = 0;
        wasMenuChanged = true;
    }

    if (!button.getButtonLevel()) {
        wasMenuChanged = false;
    }
}

void Controller::ledHandler() {
    if (button.getButtonLevel()) {
        if (!wasMenuChanged) {
            led.turnOn(WHITE);
        } else {
            led.turnAllOff();
            switch (menu) {
                case STANDBY:     led.turnOn(setLedCollor()); break;
                case WARMING_UP:  
                case FINISHED:    led.turnOn(GREEN); break;
            }
        }
    } else {
        switch (menu) {
            case STANDBY:     led.blink (GREEN, SMALL_BLINK, BIG_BLINK); break;
            case WARMING_UP:  led.blink (setLedCollor(), SMALL_BLINK, MEDIUM_BLINK); break; 
            case FINISHED:    led.blink (setLedCollor(), SMALL_BLINK, 0); break;
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