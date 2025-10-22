#ifndef NODOMENU_H
#define NODOMENU_H

#include <Arduino.h>
#define MAX_HIJOS 4
class NodoMenu;
class NodoMenu{
    
    public:
        NodoMenu(const String& nom, uint8_t=0);
        
        void agregarHijo(NodoMenu* hijo);
        
        const String& getNombre()const;
        
        NodoMenu* getPadre() const;
        
        NodoMenu* getHijo(uint8_t index) const;

        uint8_t getCantidadHijos() const;

        bool tieneHijos() const;

        uint8_t get_idApp();
    
    private:
        
        String nombre;
        NodoMenu* padre;
        NodoMenu* hijos[MAX_HIJOS];
        uint8_t num_hijos;
        uint8_t idApp;
        

};



#endif
