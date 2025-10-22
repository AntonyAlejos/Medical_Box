#ifndef DISPLAY_LCD_H
#define DISPLAY_LCD_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class DisplayLCD{
    private:
        LiquidCrystal_I2C lcd;
    public:
        DisplayLCD (uint8_t dir,uint8_t col,uint8_t filas);

        void begin();

        void mensaje(const String &,uint8_t,uint8_t);
        
        void clear();
};


#endif