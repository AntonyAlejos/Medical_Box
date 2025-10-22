#include <SensorTemp.h>

SensorTemp::SensorTemp(uint8_t pin):oneWire(pin) ,sensors(&oneWire){}

void SensorTemp::begin(){
    sensors.begin();
} 
float SensorTemp::leerCelsius()
{
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0); 
}