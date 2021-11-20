#include "Jugador.h"
#include "Tablero.h"

Jugador::Jugador()
{
    jug = ' ';
    gameover = 0;
    dira = 0;
    dirb = 0;
    nTail = 0;
};

void Jugador::posicion()
{
    if (_kbhit())
	{
		switch (_getch())
		{
            case 'a':
                dira = 1;
                break;
            case 'd':
                dira = 2;
                break;
            case 's':
                dira = 3;
                break;
            case 'w':
                dira = 4;
                break;
		}
	}
}

void Jugador::posicion2()
{
    if (_kbhit())
	{
		switch (_getch())
		{
            case 'j':
                dirb = 5;
                break;
            case 'l':
                dirb = 6;
                break;
            case 'k':
                dirb = 7;
                break;
            case 'i':
                dirb = 8;
                break;
		}
	}
}

char Jugador::jugador()
{
    cout << "Elegir icono de jugador: ";
    cin >> jug;
    return jug;
}

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

	switch (dira)
    {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            y--;
            break;
    }

}

void Jugador::Cola2()
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

	switch (dirb)
    {
        case 5:
            x--;
            break;
        case 6:
            x++;
            break;
        case 7:
            y++;
            break;
        case 8:
            y--;
            break;
    }

}
