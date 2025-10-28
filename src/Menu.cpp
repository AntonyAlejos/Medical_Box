#include"Menu.h"

Menu::Menu(AsistenteMedico & doc,DisplayLCD & lcd,Botones& botonera,NodoMenu *inicio):doc(doc),pantalla(lcd),botonera(botonera),actual(inicio){};


void Menu::mostrarMenu(){
    
    pantalla.clear();
    pantalla.mensaje(actual->getNombre(),0,0);
    uint8_t n=actual->getCantidadHijos();
    for ( uint8_t i = 0; i < n; i++)
    {
        String linea=(i==indiceSelec)?">" :" ";
        pantalla.mensaje(linea + actual->getHijo(i)->getNombre(), 0,i + 1);   
    }

}
uint8_t Menu::navegar(){
    mostrarMenu();
    
    while (true)
    {
        if(botonera.pushOpcion()){
            indiceSelec++;
            if (indiceSelec>=actual->getCantidadHijos())
                indiceSelec=0;
            mostrarMenu();
            delay(150);            
        }
        
        if (botonera.pushOK())
        {
            NodoMenu* hijo=actual->getHijo(indiceSelec);
            if(hijo && hijo->tieneHijos()){
                actual=hijo;
                indiceSelec=0;
                mostrarMenu();
            }
            else if(hijo&&hijo->get_idApp() >=0){
                switch (hijo->get_idApp())
                {
                case 1:
                    doc.tomarTemperatura();
                    break;
                case 2:
                    doc.tomarPulsoOxigeno();
                
                case 3:
                    doc.terminarExamen();
                    break;;
                case 4:
                    doc.enviar_Data();
                    break;
                case 5:
                    doc.registrarPaciente();
                    break;
                case 6:
                    //CASO REGISTRAR LIMITES
                    doc.Configurar_Limites();
                    break;
                case 7:
                    doc.ayuda();
                    break;
                default:
                    break;
                }                   
            
            }
            mostrarMenu();
            delay(200);
        }
        if(botonera.pushhEmergencia()){
            if(actual->getPadre() != nullptr){
                actual=actual->getPadre();
                indiceSelec=0;
                mostrarMenu();
            }
            delay(200);
        }
        if (botonera.pushhAtras()){
            if(actual->getPadre() != nullptr){
                actual=actual->getPadre();
                indiceSelec=0;
                mostrarMenu();
            }
            delay(200);
        }
    }
}