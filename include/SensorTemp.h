#ifndef SENSOR_TEMP_H
#define SENSOR_TEMP_H

#include <OneWire.h>
#include <DallasTemperature.h>

class SensorTemp{

    private:
        OneWire oneWire;
        DallasTemperature sensors;

    public:
        SensorTemp(uint8_t pin);

        void begin();

        float leerCelsius();       

};
#endif