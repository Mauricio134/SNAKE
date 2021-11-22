#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Jugador.h"
#include "Menu.h"

using namespace std;

class Tablero{
    public:
        char **pantalla;   // puntero para pantalla
        int **obs;         // puntero para registrar obstaculos
        int nFilas, nColumnas;  // variables a ingresar para el alto y ancho de trablero
        Jugador jugador1;   // creación de snake con clase Jugador
        Jugador jugador2;   // creación de snake con clase Jugador
        char jug1, jug2;    // se igualan a metodo jugador de clase Jugador
        char a;             // Variable que va cambiando para imprimir caracteres
        int Time;           // contador que dará su valor al metodo Timer de jugador, para incrementar cola
        int dira, dirb, X, Y; // variables de dirección y de almacenamiento de "coordenadas" para obstaculos
        bool colision;      // bool para poder imprimir mensaje en caso de colisión
        int arr[5][2];      // array  que contiene las coordenadas de los 5  choque posibles
        int sum;            // contador de choques
        bool cha;
        bool chb;

        Tablero();

        void tablero();    // Metodo para imprimir tablero y obstaculos
        void inicio();     // se da valores a los atributos x , y de ambas snakes  y se inicializa array
        void posicion();   // Metodo encargado del movimiento del snake a travez de los atributos de cada una
        void obstaculo();  // Metodo encargado de choques y guardado de coordenadas de choque en array con modificacion en obs
        void delay();      // Metodo de delay para hacer más lenta la impresión de pantalla
        bool LOSE();       // Metodo que verifica perdida del juego al chocar con bordes
};

