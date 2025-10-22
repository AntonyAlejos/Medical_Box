#include "Reloj.h"

Reloj::Reloj(){}

bool Reloj::iniciar(){
    if(!rtc.begin()){
        return false; //ERROR AL INICIAR
        }
    return true;
}

String Reloj::obtenerFechaHora(){
    DateTime now = rtc.now();
    
    // Ejemplo: DD/MM/YYYY HH:MM:SS
    String fechaHora = (now.day() < 10 ? "0" : "") + String(now.day()) + "/" +
                       (now.month() < 10 ? "0" : "") + String(now.month()) + "/" +
                      String(now.year()) + " " +
                       (now.hour() < 10 ? "0" : "") + String(now.hour()) + ":" +
                       (now.minute() < 10 ? "0" : "") + String(now.minute()) + ":" +
                       (now.second() < 10 ? "0" : "") + String(now.second());
                       
        return fechaHora;
    }
    

