#ifndef FICHAMEDICA_H
#define FICHAMEDICA_H
#include <Arduino.h>

struct ExamenCompleto{
    String fecha;
    float temperatura=0;
    int frecuenciaCardiaca=0;
    int spo2=0;
    int presionSistolica=0;
    int presionDiastolica=0;

};
class Paciente{
    public:
        Paciente(String n,String a,int id);

        void setNombre(String n);
        void setApellido(String a);
        void setID(int id);
        void setTemperatura(float temp);
        void setPresion(int pres);
        
        String  generarLineaDatos(String fecha);
        void limpiarDatos();

    
    private:
        String nombre;
        String apellido;
        int idPaciente;
        ExamenCompleto examenActual;        
};
#endif