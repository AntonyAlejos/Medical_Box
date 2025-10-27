#ifndef FICHAMEDICA_H
#define FICHAMEDICA_H
#include <Arduino.h>
#include "Configuracion.h"

struct ExamenCompleto{
    String fecha="x/x/xxxx";
    float oxigeno=0;
    float pulso=0;
    float temperatura=0;
    float presionSistolica=0;
    float presionDiastolica=0;

};
class Paciente{
    public:
        Paciente();

        void setNombre(String n);
        void setApellido(String a);
        void setEdad(int ed);
        void setTemperatura(float temp);
        void setPresion(int pres);
        void setSexo(char s);
        void setDomicilio(String d);
        void setTelefono(String t);
        void setContactoEmerg(String CE);
        void setFecha(String fecha);
        String  generarLineaDatos(Configuracion& limites);
        void setExamen(ExamenCompleto ex){examenActual=ex;}
        void limpiarDatos();

    
    private:
        String nombre="n";
        String apellido="a";
        int edad=0;
        char sexo='O';
        String domicilio="SD";
        String telefono="444";
        String contactoEmerg="555";


        ExamenCompleto examenActual;

};
#endif