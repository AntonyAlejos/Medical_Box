#include"AsistenteMedico.h"

AsistenteMedico::AsistenteMedico(DisplayLCD & lcd,SensorTemp & tmp,Botones& btns,Paciente& paciente,GestorDatos& gestorsDatos,Reloj&reloj): 
pantalla(lcd), snrTmp(tmp),botones(btns),paciente(paciente),gestorDatos(gestorsDatos),reloj(reloj){}

void AsistenteMedico::tomarTemperatura(){
    pantalla.clear();
    pantalla.mensaje(F("Por favor colocar"), 0, 0);
    pantalla.mensaje(F("el termometro"), 0, 1);
    pantalla.mensaje(F("Mantener 1 min"), 0, 2);

    const int totalSegundos = 60;  // 1 minutos

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
        delay(2000);
    } else {
        paciente.setTemperatura(tempC);
        pantalla.mensaje("Temperatura:", 0, 0);
        pantalla.mensaje(String(tempC) + (char)223 + "C", 0, 1);
        
        while (!botones.pushOK()){}
    }
    pantalla.clear();
}
void AsistenteMedico::terminarExamen(){
    paciente.setFecha(reloj.obtenerFecha());
    pantalla.clear();
    pantalla.mensaje(F("Examen terminado..."),0,0);
    while (!botones.pushOK()){}
    pantalla.clear();

}
void AsistenteMedico::enviar_Data(){
    pantalla.clear();   
    gestorDatos.enviarDatos("0"); 
    gestorDatos.enviarDatos(paciente.generarLineaDatos(configuracion));
    pantalla.mensaje(F("Su ficha medica"),0,0);
    pantalla.mensaje(F("electronica esta"),0,1);
    pantalla.mensaje(F("disponible en su"),0,2);
    pantalla.mensaje(F("Telefono"),0,3);        
    while (!botones.pushOK()){}
    pantalla.clear();
}
void AsistenteMedico::registrarPaciente(){
    pantalla.clear();
    pantalla.mensaje(F("Esperando datos"), 0, 0);
    pantalla.mensaje(F("del paciente..."), 0, 2);

    char sexo;

    String nombre,apellido,domicilio,telefono,contactoEmerg;
    int ed;
    // limpiar cualquier dato residual en el buffer Serial
    while (Serial.available()) {Serial.read();}

    while (!gestorDatos.recibirDatos(nombre, apellido,ed,sexo,domicilio,telefono,contactoEmerg)) {
        delay(100);
        if(botones.pushhAtras()){
            pantalla.clear();
            pantalla.mensaje(F("Cancelando....."), 0, 0);
            delay(1000);
            return ;}
        // espera hasta recibir datos correctos
    }
    nombre.trim();
    apellido.trim();
    domicilio.trim();
    telefono.trim();
    contactoEmerg.trim();

    
    paciente.setNombre(nombre);
    paciente.setApellido(apellido);
    paciente.setEdad(ed);
    paciente.setSexo(sexo);
    paciente.setDomicilio(domicilio);
    paciente.setTelefono(telefono);
    paciente.setContactoEmerg(contactoEmerg);
    delay(10);

// 🔹 Verificar que los datos se guardaron bien


    pantalla.clear();
    pantalla.mensaje(F("Paciente registrado"), 0, 0);
    while (!botones.pushOK()){}
    pantalla.clear();
}
void AsistenteMedico::Configurar_Limites(){
    
    pantalla.clear();
    pantalla.mensaje(F("Cargando limites"),0,0);
    pantalla.mensaje(F("del equipo....."),0,2);

    

    Limite limOxigeno,limPulso, limTemp,limPSistolica, limPDiastolica;

    while (!gestorDatos.recibirLimites(limOxigeno.mini, limOxigeno.maxi,limPulso.mini,limPulso.maxi,
                                    limTemp.mini, limTemp.maxi, limPSistolica.mini, limPSistolica.maxi,
                                    limPDiastolica.mini, limPDiastolica.maxi)) {
        delay(100);
        if(botones.pushhAtras()){
            pantalla.clear();
            pantalla.mensaje(F("Cancelando....."), 0, 0);
            delay(1000);
            return ;}
        // espera hasta recibir datos correctos
    }
    configuracion.setLimOxigeno(limOxigeno);
    configuracion.setLimPulso(limPulso);
    configuracion.setLimTemp(limTemp);
    configuracion.setLimPSistolica(limPSistolica);
    configuracion.setLimPDiastolica(limPDiastolica);
    pantalla.clear();
    pantalla.mensaje(F("Limites Cargados"), 0, 0);
    pantalla.mensaje(F("correctamente...."), 0, 2);
    while (!botones.pushOK()){}
    delay(300);
    
    // 🔹 Verificar en Serial que se guardaron correctamente(borrar o comentar despues)
Serial.println(F("==== Límites Configurados ===="));

Serial.print(F("Oxigeno: min="));
Serial.print(limOxigeno.mini);
Serial.print(F(", max="));
Serial.println(limOxigeno.maxi);

Serial.print(F("Pulso: min="));
Serial.print(limPulso.mini);
Serial.print(F(", max="));
Serial.println(limPulso.maxi);

Serial.print(F("Temperatura: min="));
Serial.print(limTemp.mini);
Serial.print(F(", max="));
Serial.println(limTemp.maxi);

Serial.print(F("Presion Sistólica: min="));
Serial.print(limPSistolica.mini);
Serial.print(F(", max="));
Serial.println(limPSistolica.maxi);

Serial.print(F("Presion Diastólica: min="));
Serial.print(limPDiastolica.mini);
Serial.print(F(", max="));
Serial.println(limPDiastolica.maxi);

Serial.println(F("=============================="));
    
}

void AsistenteMedico::tomarPulsoOxigeno(){
    pantalla.clear();
    pantalla.mensaje(F("Colocar dedo"), 0, 0);
    pantalla.mensaje(F("Mantener firme"), 0, 1);
    pantalla.mensaje(F("Esperando medicion"), 0, 2);
    
    String lectura;
    ExamenCompleto ex;
    unsigned long t0;
    t0=millis();
    gestorDatos.enviarDatos("-1");
    while ((millis() - t0 < 2000) ){}
    lectura=gestorDatos.leerLineaESP32();
    if(lectura.length()>0){
        ex.oxigeno=lectura.toFloat();
    }
    lectura="";
    t0=millis();
    gestorDatos.enviarDatos("1");
    while ((millis() - t0 < 2000) ){}
    lectura=gestorDatos.leerLineaESP32();
    if (lectura.length()>0)
    {
        ex.pulso=lectura.toFloat();
        // Estimación aproximada basada en HR y SpO2
        // Valores base típicos
        float baseSBP = 110.0;
        float baseDBP = 70.0;

        // Ajuste muy simple por HR y oxígeno
        ex.presionSistolica = baseSBP + (ex.pulso - 70) * 0.5 + (100 - ex.oxigeno) * 0.3;
        ex.presionDiastolica = baseDBP + (ex.pulso - 70) * 0.3 + (100 - ex.oxigeno) * 0.2;
    
    }
    paciente.setExamen(ex);
    pantalla.clear();
    pantalla.mensaje(F("Medicion realizada"), 0, 0);
    while (!botones.pushOK()) {}
    pantalla.clear();
}