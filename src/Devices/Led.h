#ifndef Led_h
#define Led_h

#include "Arduino.h"
#include <avr/io.h>

#define RED PIN2_bm
#define GREEN PIN1_bm
#define BLUE PIN3_bm

class Led {
    public:
        void setup();
        void turnOn(uint8_t led);
        void turnAllOff();
        void blink(uint8_t led, uint16_t highTime, uint16_t lowTime);              //Função que faz o LED piscas
    private:                                                                       // Parâmetro 2: tempo do LED ligado
        unsigned long ledTimer = 0;

        boolean getLedLevel(uint8_t led);
};

extern Led led;

#endif 