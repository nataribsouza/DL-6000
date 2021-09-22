#ifndef Button_h
#define Button_h

#include "Arduino.h"

#define BUTTON PIN1_bm
#define PRESSED_TIME 1000

class Button{
    public:
        boolean buttonLongPress = false;

        void setup();
        void read();
    private:
        boolean wasButtonPressed = false;
        unsigned int time = 0;
        uint16_t counter = 0;
};

extern Button button;
#endif