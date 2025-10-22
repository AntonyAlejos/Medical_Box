#ifndef GESTOR_DATA_H
#define GESTOR_DATA_H
#include <Arduino.h>
#include <SoftwareSerial.h>


class GestorDatos{
    public:
        GestorDatos(SoftwareSerial& serialRef);
        void enviarDatos(String ficha);
        bool recibirDatos(String &nombre,String&apellido,int& id);

        /*------------------------------------------------------------------        
                          ESTO SE RESULVE EN EL ESP32 

        bool inicializarSD();
        bool guardarFichaSSD(const char* nombreArchivo, const char* ficha);
        bool leerFichaSSD(const char* nombreArchivo);
        void enviarFichasSSDSerial();
        ------------------------------------------------------------------ */
        
    private:
        SoftwareSerial& espSerial;
        int cs=10;
};


#endif