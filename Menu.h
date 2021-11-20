#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Menu{
    public:
        int opcion;
        int cerrar;
        Menu();

        void menu_init();
        void menu_final();
        bool LOSE();
        bool CERRAR();

};
