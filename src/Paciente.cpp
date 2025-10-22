#include"Paciente.h"

//FichaMedica::FichaMedica(String n,String a,String id):nombre(n),apellido(a),idPaciente(id){}

Paciente::Paciente(String n,String a,int id):nombre(n),apellido(a),idPaciente(id){}

void Paciente::setNombre(String n){nombre=n;}
void Paciente::setApellido(String a){apellido=a;}
void Paciente::setID(int id){idPaciente=id;}


void Paciente::setTemperatura(float temp){
    examenActual.temperatura=temp;
}



void  Paciente::setPresion(int pres){
    examenActual.presionDiastolica=pres;
}
void  Paciente::limpiarDatos(){examenActual=ExamenCompleto();}

String Paciente::generarLineaDatos(String fecha){
    
    String datos = nombre + "," + apellido + "," + idPaciente + ",";
    datos += String(examenActual.temperatura, 1) + ",";
    datos += String(examenActual.frecuenciaCardiaca) + ",";
    datos += String(examenActual.spo2) + ",";
    datos += fecha;

    return datos;

}