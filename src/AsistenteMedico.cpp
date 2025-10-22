#include"AsistenteMedico.h"

AsistenteMedico::AsistenteMedico(DisplayLCD & lcd,SensorTemp & tmp,Botones& btns,Paciente& paciente,GestorDatos& gestorsDatos,Reloj&reloj): 
pantalla(lcd), snrTmp(tmp),botones(btns),paciente(paciente),gestorDatos(gestorsDatos),reloj(reloj){}

void AsistenteMedico::tomarTemperatura(){
    pantalla.clear();
    pantalla.mensaje(F("Por favor colocar"), 0, 0);
    pantalla.mensaje(F("el termometro"), 0, 1);
    pantalla.mensaje(F("Mantener 2 min"), 0, 2);

    const int totalSegundos = 120;  // 2 minutos

    for (int t = totalSegundos; t > 0; t--) {
        int minutos = t / 60;
        int segundos = t % 60;

    // Última línea con la cuenta regresiva
        String tiempo = "Tiempo: " + String(minutos) + ":" + (segundos < 10 ? "0" : "") + String(segundos);
        pantalla.mensaje(tiempo, 0, 3);  // línea 4 del display
        delay(1000);
    }


    pantalla.clear();
    float tempC =snrTmp.leerCelsius();
    if (tempC == DEVICE_DISCONNECTED_C) {
        pantalla.mensaje(F("Error de sensor"), 0, 0);
        delay(3000);
    } else {
        paciente.setTemperatura(tempC);
        pantalla.mensaje("Temperatura:", 0, 0);
        pantalla.mensaje(String(tempC) + (char)223 + "C", 0, 1);
        
        while (!botones.pushOK()){}
    }
    pantalla.clear();
}

void AsistenteMedico::enviar_Data(){
    
    gestorDatos.enviarDatos(paciente.generarLineaDatos(reloj.obtenerFechaHora()));
    delay(1000);

}

void AsistenteMedico::registrarPaciente(){
    pantalla.clear();
    pantalla.mensaje(F("Esperando datos"), 0, 0);
    pantalla.mensaje(F("del paciente..."), 0, 1);

    String nombre,apellido;
    int id;
    while (!gestorDatos.recibirDatos(nombre, apellido, id)) {
        delay(100);
        if(botones.pushhAtras()){break;}

        // espera hasta recibir datos correctos
    }
    
    paciente.setNombre(nombre);
    paciente.setApellido(apellido);
    paciente.setID(id);
    pantalla.clear();
    pantalla.mensaje(F("Paciente registrado"), 0, 0);
    pantalla.mensaje(nombre + " " + apellido, 0, 1);
    while (!botones.pushOK()){}
}