#include "Jugador.h"
#include "Tablero.h"

Jugador::Jugador()              // Constructor
{
    jug = ' ';
    gameover = 0;
    nTail = 0;
};

void Jugador::Cola()           //Lógica de movimiento de cola
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	if (Timer%20 == 0)        //Condicional de incremento de cola con variable Timer 
    {
        nTail++;
	}


}

char Jugador::jugador()        // Ingreso de caracter para reconocera a la serpiente
{
    cout << "Elegir icono de jugador: ";
    cin >> jug;
    return jug;
}
