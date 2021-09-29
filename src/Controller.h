#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include <avr/io.h>
#include "Devices/Thermocouple.h"
#include "Devices/Button.h"
#include "Devices/Relay.h"
#include "Devices/Led.h"

//==== DEFINIÇÕES DO MENU ====
#define MENU_NUMBER 3
#define STANDBY 0
#define WARMING_UP 1
#define PROCESS_FINISHED 2 
//============================

//==== DEFINIÇÕES DAS TEMPERATURAS ====
#define T100 54
#define T150 107
#define T230 197
#define T300 257
#define T400 397
#define MAX_TEMPERATURE 397
#define RST_TEMPERATURE 106
//======================================

//==== DEFINIÇÃO TEMPO ATÉ DESLIGAR ====
#define TURN_OF_TIMER 5000
//======================================

//==== DEFINIÇÕES DOS LED'S ====
#define SMALL_BLINK 200
#define MEDIUM_BLINK 1000
#define BIG_BLINK 5000

#define RED 0
#define GREEN 1
#define BLUE 2
#define PURPLE 3
#define YELLOW 4
#define WHITE 5
//===============================

class Controller{
    public:
        void setup();
        void loop();
    private:
        boolean wasMenuChanged = false;
        boolean finishingProcess = false;
        unsigned long int warmingUpTimer = 0;
        unsigned int temperature = 0;

        uint8_t verifyMaxTemperature();
        uint8_t menu = 0;

        uint8_t setLedCollor();
        void buttonHandler();
        void readTemperature();
        void ledHandler();
        void standby();
        void warmingUp();
        void processFinished();
};

extern Controller controller;

#endif