#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class Jugador{                          // Clase para la construcción de las snakes
    public:
        char jug;                       // Clase para la construcción de las snakes
        int x, y;                       // Variables para la ubicación de la cabeza del snake
        int gameover;                    
        int Timer;                      // Contador que funciona con un if para acresentar la cola
        int tailX[100], tailY[100];     //Arrays que contienen la cola de la snake
        int nTail;                      // Variable que designa el tamaño de la snake

        Jugador();                      // Metodo para construcción

        char jugador();                 // Metodo para ingresar valor de variable jug
        void Cola();                    // Metodo que contiene el funcionamiento de la cola
};
