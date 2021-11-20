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
        int **obs;
        int nFilas, nColumnas;
        Jugador jugador1;
        Jugador jugador2;
        char jug1, jug2;
        char a;
        int Time;
        int dira, dirb, X, Y;
        bool colision;
        int arr[5][2];
        int sum;

        Tablero();

        void tablero();
        void inicio();
        void posicion();
        void obstaculo();
        void delay();
        bool LOSE();
};

