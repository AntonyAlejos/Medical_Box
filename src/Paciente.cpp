#include"Paciente.h"

//FichaMedica::FichaMedica(String n,String a,String id):nombre(n),apellido(a),idPaciente(id){}

Paciente::Paciente(){}

void Paciente::setNombre(String n){nombre=n;}
void Paciente::setApellido(String a){apellido=a;}
void Paciente::setEdad(int ed){edad=ed;}
void Paciente::setSexo(char s){sexo=s;}
void Paciente::setDomicilio(String d){domicilio=d;}
void Paciente::setTelefono(String t){telefono=t;}
void Paciente::setContactoEmerg(String  CE){contactoEmerg=CE;}

void Paciente::setTemperatura(float temp){examenActual.temperatura=temp;}
void Paciente::setPresion(int pres){examenActual.presionDiastolica=pres;}
void Paciente::setFecha(String fecha){examenActual.fecha=fecha;}
void Paciente::limpiarDatos(){examenActual=ExamenCompleto();}


String Paciente::generarLineaDatos(Configuracion& limites){
    


    
    String datos = nombre + "," + apellido + "," + edad + ","+sexo+","+domicilio+","+telefono+","+contactoEmerg+","+examenActual.fecha+",";
    datos += String(examenActual.oxigeno, 1) + ",";
    datos += String(examenActual.pulso,1) + ",";
    datos += String(examenActual.temperatura,1) + ",";
    datos += String(examenActual.presionSistolica,1) + ",";
    datos += String(examenActual.presionDiastolica,1);
/*
    datos +=(examenActual.oxigeno< limites.getLimOxigeno().mini) ? '0' : (examenActual.oxigeno> limites.getLimOxigeno().maxi? '1' : 'n');
    datos +=(examenActual.pulso< limites.getLimPulso().mini) ? '0' : (examenActual.pulso > limites.getLimPulso().maxi? '1' : 'n');    
    datos +=(examenActual.temperatura< limites.getLimTemp().mini) ? '0' : (examenActual.temperatura> limites.getLimTemp().maxi? '1' : 'n');
    datos +=(examenActual.presionSistolica< limites.getLimPSistolica().mini) ? '0' : (examenActual.presionSistolica> limites.getLimPSistolica().maxi? '1' : 'n');
    datos +=(examenActual.presionDiastolica< limites.getLimPDiastolica().mini) ? '0' : (examenActual.presionDiastolica> limites.getLimPDiastolica().maxi? '1' : 'n');
    

    */   
    return datos;

}