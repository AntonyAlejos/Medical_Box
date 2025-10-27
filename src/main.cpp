#include <Arduino.h>
#include "SensorTemp.h"
#include "Botones.h"
#include "DisplayLCD.h"
#include "Menu.h"
#include "Paciente.h"
#include "AsistenteMedico.h"
#include "GestorData.h"
#include <SoftwareSerial.h>
#include <RTClib.h>
#include "Reloj.h"


// Pines y configuración
#define LCD_ADDR1 0x27
#define LCD_ADDR2 0x26
#define PIN_SENSOR 2
#define ATRAS_BUTTOM 4
#define OK_BUTTOM 5
#define OP1_BUTTOM 6
#define EMERGENCY_BUTTOM 7
#define TX_PIN 10
#define RX_PIN 11
SoftwareSerial esp32Serial(RX_PIN, TX_PIN);
Reloj reloj;
SensorTemp sensor(PIN_SENSOR);
DisplayLCD pantalla(LCD_ADDR1, 20, 4);
GestorDatos gestorDatos(esp32Serial);
//DisplayLCD pantalla2(LCD_ADDR2, 16, 2);
Botones botones(OK_BUTTOM, OP1_BUTTOM, EMERGENCY_BUTTOM, ATRAS_BUTTOM);

// NODOS DEL MENU
NodoMenu raiz("     BIENVENIDO     ");
NodoMenu menu_Principal("Asistente Medico");
NodoMenu menu_Examen_Comp("Examen Completo");
NodoMenu menu_Cofiguraciones("Configuracion");
NodoMenu menu_tu_doctor("Diagnosticar",4);
NodoMenu menuTemp("Tomar Temperatura",1);
NodoMenu menu_Pulso_Oxigeno("Pulso y Oxigeno",2);
NodoMenu menu_terminar("Terminar Examen",3);
NodoMenu menu_Registrar_Paciente("Registrar Paciente",5);
NodoMenu menu_Conf_Limites("Configurar limites",6);

// Construcción de objetos

Paciente paciente;
AsistenteMedico doc(pantalla, sensor, botones, paciente, gestorDatos, reloj);
Menu menu(doc, pantalla, botones, &raiz);

void setup() {
    reloj.iniciar();
    Serial.begin(9600);
    esp32Serial.begin(9600);
    pantalla.begin();
    // pantalla2.begin();

    sensor.begin();
    botones.iniciar();

     //CONSTRUYENDO NUESTRO MUNDO
    
    raiz.agregarHijo(&menu_Principal);
    raiz.agregarHijo(&menu_Cofiguraciones);
    
    menu_Principal.agregarHijo(&menu_Examen_Comp);
    menu_Principal.agregarHijo(&menu_tu_doctor);
    
    menu_Examen_Comp.agregarHijo(&menuTemp);
    menu_Examen_Comp.agregarHijo(&menu_Pulso_Oxigeno);
    menu_Examen_Comp.agregarHijo(&menu_terminar);

    menu_Cofiguraciones.agregarHijo(&menu_Registrar_Paciente);
    menu_Cofiguraciones.agregarHijo(&menu_Conf_Limites);
}

void loop() {
    menu.navegar();
}
