#include "GestorData.h"


GestorDatos::GestorDatos(SoftwareSerial& serialRef):espSerial(serialRef){}

void GestorDatos::enviarDatos(String  ficha)
{
    espSerial.println(ficha);
    //MARCA PARA FIN DE FICHA
}

bool GestorDatos::recibirDatos(String& nombre, String& apellido,int& id){
     if (espSerial.available()) {
            String linea = espSerial.readStringUntil('\n');
            int idx1 = linea.indexOf(',');
            int idx2 = linea.indexOf(',', idx1 + 1);
            if (idx1 != -1 && idx2 != -1) {
                nombre = linea.substring(0, idx1);
                apellido = linea.substring(idx1 + 1, idx2);
                id = linea.substring(idx2 + 1).toInt();
                return true;
            }
        }
        return false; // No se recibió o formato incorrecto
}


