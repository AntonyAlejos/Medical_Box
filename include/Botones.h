#ifndef BOTONES_H
#define BOTONES_H
#include <Arduino.h>
/**
 * @brief Clase que representa un conjunto de botones físicos.
 * 
 * Esta clase permite inicializar y leer el estado de  4 botones:
 * OK, DESLIZADOR, EMERGENCIA, y ATRAS .Usa entradas digitales con resistencias pull-up
*/
class Botones{
    private:
        uint8_t OK;             ///< Pin conectado al botón OK
        uint8_t DESLIZADOR;     ///< Pin conectado al botón de opción
        uint8_t EMERGENCIA;     ///< Pin conectado al botón de emergencia
        uint8_t ATRAS;          ///< Pin conectado al botón Atrás
        unsigned long  antes=0; ///<Marca de tiempo para antirrebote

    public:
        /**
        * @brief Constructor de la clase Botones.
        * 
        * @param OK         Pin del botón OK
        * @param DESLIZADOR Pin del botón de opción
        * @param EMERGENCIA Pin del botón de emergencia
        * @param ATRAS      Pin del botón de retroceso
        */
        

        Botones(uint8_t OK, uint8_t DESLIZADOR, uint8_t EMERGENCIA,uint8_t ATRAS);
        
        /**
        * @brief Inicializa los pines como entradas con pull-up.
        */
        void iniciar();

        /**
         * @brief Devuelve si el botón OK está presionado.
         * @return true si el botón está presionado (LOW), false si no.
        */
        bool pushOK();

        /**
        * @brief Verifica si se presionó el botón de opción.
        * 
        * Usa antirrebote con control de tiempo.
        * 
        * @return true si fue una nueva pulsación válida.
        */
        bool pushOpcion(); 

        /**
        * @brief Verifica si se presionó el botón Atrás.
        * 
        * Usa antirrebote con control de tiempo.
        * 
        * @return true si fue una nueva pulsación válida.
        */
        bool pushhAtras();

        /**
        * @brief Devuelve si el botón de emergencia está presionado.
        * @return true si el botón está presionado (LOW), false si no.
        */ 
        bool pushhEmergencia();


        
        void setCont();
};

#endif