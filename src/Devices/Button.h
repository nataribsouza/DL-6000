#ifndef Button_h
#define Button_h

#include "Arduino.h"

#define BUTTON PIN0_bm
#define PRESSED_TIME 1000

class Button{
    public:
        void setup();
        boolean read();
        boolean getButtonLevel();
    private:
        boolean buttonPressed = false;
        uint16_t buttonCounter = 0;
};

extern Button button;
#endif