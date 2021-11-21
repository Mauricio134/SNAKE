#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Menu{                 //Clase para la creación de menus 
    public:
        int opcion;         //
        int cerrar;         // Variables que funcionan como bool que se confirman con condicionales para mostrar los menús o salir
        Menu();

        void menu_init();   // Menú del comienzo de juego que pide presionar tecla pra iniciar
        void menu_final();  // Menú del final de juego que pide presionar tecla pra reiniciar o salir
        bool LOSE();        //Función que retorna valor para reinicar bucle y volver a jugar
        bool CERRAR();      //Función que retorna valor para reinicar bucle y volver a jugar o cerrar juego

};
