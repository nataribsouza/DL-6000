#ifndef Led_h
#define Led_h

#include "Arduino.h"

#define RED PIN2_bm
#define GREEN PIN0_bm
#define BLUE PIN3_bm;

class Led {
    public:
        void setup();
        void turnOn(uint8_t led);
        void turnAllOff();
        void blink(uint8_t led, uint16_t highTime, uint16_t lowTime);
    private:
        unsigned long ledTimer = 0;
};

extern Led led;

#endif 