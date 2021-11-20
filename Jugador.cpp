#include "Jugador.h"
#include "Tablero.h"

Jugador::Jugador()
{
    jug = ' ';
    gameover = 0;
    nTail = 0;
};

void Jugador::Cola()
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

	if (Timer%20 == 0)
    {
        nTail++;
	}

}

char Jugador::jugador()
{
    cout << "Elegir icono de jugador: ";
    cin >> jug;
    return jug;
}
