#ifndef RELOJ_H
#define RELOJ_H

#include <Wire.h>
#include <RTClib.h>

class Reloj
{
    public:
        Reloj();
        bool iniciar();
        String obtenerFechaHora();
        String obtenerFecha(); 
        String obtenerHora();
    private:
    RTC_DS1307 rtc;
    
};

#endif