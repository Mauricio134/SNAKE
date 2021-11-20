#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Jugador.h"
#include "Menu.h"

using namespace std;

class Tablero{
    public:
        char **pantalla;
        char **obs;
        int nFilas, nColumnas;
        Jugador jugador1;
        Jugador jugador2;
        char jug1, jug2;
        char a;
        int Time;
        int dira, dirb, X, Y;
        bool colision;

        Tablero();

        void tablero();
        void inicio();
        void posicion();
        void obstaculos();
        void delay();
        bool LOSE();
};

