#include "GestorData.h"


GestorDatos::GestorDatos(SoftwareSerial& serialRef):espSerial(serialRef){}

void GestorDatos::enviarDatos(String  datos)
{
    
    espSerial.println(datos);
    Serial.println(datos);
}

bool GestorDatos::recibirDatos(String& nombre, String& apellido,int& edad,char &sexo,String & domicilio,String& telefono,String& contacto_Emerg){
  if (Serial.available()) {
        String linea = Serial.readStringUntil('\n');
        linea.trim();
        Serial.println("DEBUG - Linea recibida: '");
        Serial.println(linea);
        Serial.println("'");

        String partes[7];
        int start = 0;
        for (int i = 0; i < 6; i++) {
            int pos = linea.indexOf(',', start);
            if (pos == -1) return false;
            partes[i] = linea.substring(start, pos);
            partes[i].trim();
            start = pos + 1;
        }
        partes[6] = linea.substring(start);
        partes[6].trim();

        // validar que todos los campos tengan datos
    
        nombre = partes[0];
        nombre.trim();
        apellido = partes[1];
        apellido.trim();
        edad = partes[2].toInt();
        partes[3].trim();
        sexo = partes[3].length() > 0 ? partes[3][0] : ' ';
        domicilio = partes[4];
        domicilio.trim();
        telefono = partes[5];
        telefono.trim();
        contacto_Emerg = partes[6];
        contacto_Emerg.trim();

        return true;
    }
    return false; // No se recibió o formato incorrect

}

bool GestorDatos::recibirLimites(float& minO,float& maxO,float& minP,float& maxP,float& minT,float& maxT,float& maxPS,float& minPS,float& minPD,float& maxPD)
{
    if (Serial.available()) {
        String partes[10];
        int index = 0;
        String linea = Serial.readStringUntil('\n');

        while (index < 10) {
            int pos = linea.indexOf(',');
            if (pos == -1) {
            partes[index++] = linea;
            break;
            }
            partes[index++] = linea.substring(0, pos);
            linea = linea.substring(pos + 1);
        }
        minO=(partes[0]).toFloat();
        maxO=(partes[1]).toFloat();

        minP=partes[2].toFloat();
        maxP=partes[3].toFloat();
        
        minT=partes[4].toFloat();
        maxT=partes[5].toFloat();
        
        minPS=partes[6].toFloat();
        maxPS=partes[7].toFloat();

        minPD=partes[8].toFloat();
        maxPD=partes[9].toFloat();
        return true;

   }
        
        return false; // No se recibió o formato incorrect

}

String GestorDatos::leerLineaESP32(){

    return espSerial.readStringUntil('\n');
}

