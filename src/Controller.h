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
#define FINISHED 2 
//============================

//==== DEFINIÇÕES DAS TEMPERATURAS ====
#define T100 54
#define T140 94
#define T180 135
#define T200 156
#define MAX_TEMPERATURE 156
#define RST_TEMPERATURE 54
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
        uint8_t menu = 0;

        uint8_t setLedCollor();
        void buttonHandler();
        void ledHandler();
        void standby();
        void warmingUp();
        void finished();
};

extern Controller controller;

#endif