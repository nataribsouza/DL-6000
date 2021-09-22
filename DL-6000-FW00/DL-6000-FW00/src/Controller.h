#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include <avr/io.h>
#include "Devices/Thermocouple.h"
#include "Devices/Button.h"
#include "Devices/Relay.h"
#include "Devices/Led.h"


#define SMALL_BLINK 200
#define MEDIUM_BLINK 1000
#define BIG_BLINK 5000

#define RED 0
#define GREEN 1
#define BLUE 2
#define PURPLE 3
#define YELLOW 4


class Controller{
    public:
        void setup();
        void loop();
    private:
        uint8_t menu = 0;

        uint8_t setLedCollor();
        void standby();
        void onHot();
        void onCold();
};

extern Controller controller;

#endif