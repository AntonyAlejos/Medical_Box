#ifndef MENU_H
#define MENU_H

#include<Arduino.h>
#include"DisplayLCD.h"
#include"Botones.h" 
#include"NodoMenu.h"
#include"AsistenteMedico.h"


class Menu{
    
    private:
        AsistenteMedico& doc;
        DisplayLCD & pantalla;    
        Botones &botonera;
        NodoMenu *actual; //Nodo Al menu ACtual
        uint8_t indiceSelec;  //Que opcion esta selecionada
    public:
        Menu (AsistenteMedico& ,DisplayLCD &,Botones&,NodoMenu*);

        void mostrarMenu();
        void limpiarMenu();
        uint8_t navegar();

};
#endif