#include "Botones.h"

Botones::Botones (uint8_t OK, uint8_t DESLIZADOR, uint8_t EMERGENCIA,uint8_t ATRAS):
    OK(OK),DESLIZADOR(DESLIZADOR),EMERGENCIA(EMERGENCIA),ATRAS(ATRAS){}
void Botones::iniciar(){
    pinMode(OK, INPUT_PULLUP);
    pinMode(DESLIZADOR, INPUT_PULLUP);
    pinMode(EMERGENCIA, INPUT_PULLUP);
    pinMode(ATRAS, INPUT_PULLUP);
}   
        //Metodos de consulta
bool Botones::pushOK(){
    unsigned long ahora =millis();

    if (digitalRead(OK)==LOW && (ahora- antes)>200)
    {
        antes=ahora;
        return true;
    }

    return false;
}



bool Botones::pushOpcion()
{

    unsigned long ahora =millis();

    if (digitalRead(DESLIZADOR)==LOW && (ahora- antes)>200)
    {
        antes=ahora;
        return true;
    }

    return false;
}
bool Botones::pushhAtras()
{

    unsigned long ahora =millis();

    if (digitalRead(ATRAS)==LOW && (ahora- antes)>200)
    {
        antes=ahora;
        return true;
    }

    return false;
}

bool Botones::pushhEmergencia()
{
    return digitalRead(EMERGENCIA)==LOW;
}