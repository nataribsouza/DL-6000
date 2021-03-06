#include "Controller.h"

void Controller::setup() {
    led.setup();
    relay.setup();
    button.setup();
    thermocouple.setup();
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
    readTemperature();
    ledHandler();

    led.turnOn(GREEN);
    delay(2000);
    led.turnAllOff();
}


void Controller::warmingUp() {
    relay.turnOn();
    buttonHandler();
    readTemperature();
    ledHandler();
    if (temperature >= MAX_TEMPERATURE && !finishingProcess) {
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
    readTemperature();
    ledHandler();
}

void Controller::buttonHandler() {
    if (button.read() && !wasMenuChanged) {
        if (menu == STANDBY) {
            menu = verifyMaxTemperature();
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
            case PROCESS_FINISHED:    led.turnAllOff(); led.turnOn(RED); break;
        }
    }
}

uint8_t Controller::verifyMaxTemperature() {
    if (thermocouple.read() < MAX_TEMPERATURE) {
        return WARMING_UP;
    } else {
        return PROCESS_FINISHED;
    }
}

void Controller::readTemperature() {
    if (led.isLedOff()) temperature = thermocouple.read();
}

uint8_t Controller::setLedCollor() {
    if (temperature <= T150) {
        return BLUE;
    } else if (temperature > T150 && temperature <= T230) {
        return YELLOW;
    } else if (temperature > T230 && temperature <= T300) {
        return PURPLE;
    } else {
        return RED;
    }
}

Controller controller;