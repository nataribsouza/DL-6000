#ifndef Button_h
#define Button_h

#include "Arduino.h"

//No DL-6000_HW00, trocar pino do botão com o do Led verde
#define BUTTON PIN0_bm
#define PRESSED_TIME 200

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