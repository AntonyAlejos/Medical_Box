#include "Reloj.h"

Reloj::Reloj(){}

bool Reloj::iniciar(){
    if(!rtc.begin()){
        return false; //ERROR AL INICIAR
        }
    return true;
}

String Reloj::obtenerFecha(){
    DateTime now = rtc.now();
    
    // Ejemplo: DD/MM/YYYY
    String fecha= (now.day() < 10 ? "0" : "") + String(now.day()) + "/" +
                       (now.month() < 10 ? "0" : "") + String(now.month()) + "/" +
                      String(now.year());
                       
        return fecha;
    }
    

