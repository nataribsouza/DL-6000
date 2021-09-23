#ifndef Led_h
#define Led_h

#include "Arduino.h"
#include <avr/io.h>

#define FUSE_SYSCFG0_DEFAULT  0xc0

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

        boolean getLedLevel(uint8_t led);
};

extern Led led;

#endif 