#include "Controller.h"

void Controller::setup() {
    led.setup();
    relay.setup();
    button.setup();
    thermocouple.setup();
    
    led.turnOn(GREEN);
    delay(3000);
    led.turnAllOff();
}

void Controller::loop() {   
    switch (menu) {
        case STANDBY:          standby(); break;
        case WARMING_UP:       warmingUp(); break;
        case PROCESS_FINISHED: processFinished(); break;
    }    
}

void Controller::standby() {
    relay.turnOff();
    buttonHandler();
    getTemperature();
    ledHandler();
}


void Controller::warmingUp() {
    relay.turnOn();
    buttonHandler();
    getTemperature();
    ledHandler();
    if (lighterTemperature >= MAX_TEMPERATURE && !finishingProcess) {
        finishingProcess = true;
        warmingUpTimer = millis();
    } else if (finishingProcess && (millis() - warmingUpTimer >= TURN_OF_TIMER)) {
        warmingUpTimer = 0;
        finishingProcess = false;
        menu = PROCESS_FINISHED;
    }
}

void Controller::processFinished() {
    relay.turnOff();
    buttonHandler();
    getTemperature();
    ledHandler();
}

void Controller::buttonHandler() {
    if (button.read() && !wasMenuChanged) {
        if (menu == STANDBY) {
            lighterTemperature >= MAX_TEMPERATURE ? 
            menu = PROCESS_FINISHED : menu = WARMING_UP;
        } else {
            menu = STANDBY;
        }
        wasMenuChanged = true;
        led.turnAllOff();   
    }

    if (!button.getButtonLevel()) {
        wasMenuChanged = false;
    }
}

void Controller::ledHandler() {
    if (button.getButtonLevel()) {
        if (!wasMenuChanged) led.turnOn(WHITE);
        else led.turnAllOff();       
    } else {
        switch (menu) {
            case STANDBY:             led.blink (GREEN, SMALL_BLINK, BIG_BLINK); break;
            case WARMING_UP:          led.blink (setLedCollor(), SMALL_BLINK, MEDIUM_BLINK); break; 
            case PROCESS_FINISHED:    led.blink (setLedCollor(), BIG_BLINK, SMALL_BLINK);
        }
    }
}

void Controller :: getTemperature() {
    lighterTemperature = thermocouple.read();
}

uint8_t Controller::verifyMaxTemperature() {
    if (lighterTemperature < MAX_TEMPERATURE) {
        return WARMING_UP;
    } else {
        return PROCESS_FINISHED;
    }
}

uint8_t Controller::setLedCollor() {
    if (lighterTemperature <= T150) {
        return BLUE;
    } else if (lighterTemperature <= T230) {
        return YELLOW;
    } else if (lighterTemperature <= T300) {
        return PURPLE;
    } else {
        return RED;
    }
}

Controller controller;