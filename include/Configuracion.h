#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <Arduino.h>


class Limite {
public:
    float mini; // uso float para temperatura, int podría ser suficiente para pulso/presión
    float maxi;

    Limite():mini(0), maxi(0) {} // constructor por defecto
};

class Configuracion {
public:
    Configuracion(); // constructor inicializa límites por defecto

    // Métodos para configurar límites
    void configurarLimites();       // carga todos los límites, por ejemplo desde Serial o menú
    void setLimOxigeno(Limite limO);
    void setLimPulso( Limite limP);
    void setLimTemp(Limite limT);
    void setLimPSistolica(Limite limPS);
    void setLimPDiastolica(Limite limPD);

    // Métodos para obtener los límites (útil para diagnóstico)
    Limite getLimOxigeno() const { return limOxigeno; }
    Limite getLimPulso() const { return limPulso; }
    Limite getLimTemp() const { return limTemp; }
    Limite getLimPSistolica() const { return limPSistolica; }
    Limite getLimPDiastolica() const { return limPDiastolica; }

private:
    Limite limOxigeno;
    Limite limPulso;
    Limite limTemp;
    Limite limPSistolica;
    Limite limPDiastolica;
};




#endif