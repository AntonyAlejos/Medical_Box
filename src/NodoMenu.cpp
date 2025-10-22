#include "NodoMenu.h"

NodoMenu::NodoMenu(const String& nom,uint8_t id)
    :nombre(nom),padre(nullptr), num_hijos(0),idApp(id){
}

void NodoMenu::agregarHijo(NodoMenu* hijo) {
    if (num_hijos < MAX_HIJOS && hijo != nullptr) {
        hijos[num_hijos++] = hijo;
        hijo->padre = this;
    }
}

// --- Getters ---
const String& NodoMenu::getNombre() const {
    return nombre;
}

NodoMenu* NodoMenu::getPadre() const {
    return padre;
}

NodoMenu* NodoMenu::getHijo(uint8_t index)const {
    if (index >= 0 && index < num_hijos)
        return hijos[index];
    return nullptr;
}

uint8_t NodoMenu::getCantidadHijos() const {
    return num_hijos;
}

bool NodoMenu::tieneHijos() const {
    return (num_hijos > 0);
}

uint8_t NodoMenu::get_idApp(){return idApp;};


