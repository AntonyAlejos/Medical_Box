#ifndef ROBOT_MEDICO_H
#define ROBOT_MEDICO_H
#include "SensorTemp.h"
#include "DisplayLCD.h"
#include "Botones.h"
#include"Paciente.h"
#include "GestorData.h"
#include "Reloj.h"

class AsistenteMedico{
    public:
    AsistenteMedico(DisplayLCD & lcd,SensorTemp & tmp,Botones & btns,Paciente& paciente,GestorDatos& gestorDatos,Reloj& reloj);
    void tomarTemperatura();
    void enviar_Data();
    void registrarPaciente();
    

    


    private:

        DisplayLCD &pantalla;
        SensorTemp &snrTmp;
        Botones& botones;
        Paciente& paciente;
        GestorDatos& gestorDatos;
        Reloj& reloj;
};


#endif