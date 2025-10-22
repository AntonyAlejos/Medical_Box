#include "DisplayLCD.h"

DisplayLCD::DisplayLCD (uint8_t dir,uint8_t col,uint8_t filas) : lcd(dir,col,filas){}

void DisplayLCD::begin(){
    lcd.init();
    lcd.backlight();
}
void DisplayLCD::mensaje(const String &texto,uint8_t col=0,uint8_t fila=0){
    lcd.setCursor(col, fila);
    lcd.print(texto);
}
void DisplayLCD::clear(){
    lcd.clear();
}