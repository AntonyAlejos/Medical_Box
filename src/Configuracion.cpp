#include "Configuracion.h"


Configuracion::Configuracion(){} // constructor inicializa límites por defecto

    // Métodos para configurar límites
void Configuracion::setLimOxigeno(Limite limO){limOxigeno=limO;}
void Configuracion::setLimPulso( Limite limP){limPulso=limP;}
void Configuracion::setLimTemp(Limite limT){limTemp=limT;}
void Configuracion::setLimPSistolica(Limite limPS){limPSistolica=limPS;}
void Configuracion::setLimPDiastolica(Limite limPD){limPDiastolica=limPD;}

    // Métodos para obtener los límites (útil para diagnóstico)