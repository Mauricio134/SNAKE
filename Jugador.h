#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class Jugador{
    public:
        char jug;
        int x, y;
        int gameover;
        int Timer;
        int tailX[100], tailY[100];
        int nTail;

        Jugador();

        char jugador();
        void Cola();
};
