#include "Tablero.h"

Tablero::Tablero()
{
    pantalla = nullptr;
    obs = nullptr;
    cout<<"Ingrese número de filas: ";
    cin>>nFilas;
    cout<<"Ingrese número de columnas: ";
    cin>>nColumnas;
    Time = 0;
	jug1 = jugador1.jugador();
	jug2 = jugador2.jugador();
    a = ' ';
    dira = 0;
    dirb = 0;
    colision = false;
    X = 0;
    Y = 0;
}

void Tablero::inicio()
{
    jugador1.x = nColumnas/2;
	jugador1.y = nFilas - 3;
	jugador2.x = nColumnas/2;
	jugador2.y = 2;
}

void Tablero::tablero()
{
    pantalla=new char*[nFilas];
    obs=new char*[nFilas];
    for(int i=0;i<nFilas;i++){
        pantalla[i]=new char[nColumnas];
        obs[i]=new char[nColumnas];
    }
    system("cls");
    Time++;
    jugador1.Timer = Time;
    jugador2.Timer = Time;

    for(int i=0; i<nFilas; i++){
        for(int j=0; j<nColumnas; j++){
            if (i == 0 && j == 0) {
				a = 201;
			}
			else if (i == nFilas - 1 && j == 0) {
				a = 200;
			}
			else if (i == 0 && j == nColumnas - 1) {
				a = 187;
			}
			else if (i == nFilas - 1 && j == nColumnas - 1) {
				a = 188;
			}
			else if (j == 0 || j == nColumnas - 1) {
				a = 186;
			}
			else if (i == 0 || i == nFilas - 1) {
				a = 205;
			}
			else if (i == jugador1.y && j == jugador1.x) {
				a = jug1;
			}
			else if (i == jugador2.y && j == jugador2.x) {
				a = jug2;
			}
			else {
				a = ' ';
			}

			for (int k = 0; k < jugador1.nTail; k++) {
				if (jugador1.tailX[k] == j && jugador1.tailY[k] == i) {
					a = '+';
				}
			}

			for (int m = 0; m < jugador2.nTail; m++) {
				if (jugador2.tailX[m] == j && jugador2.tailY[m] == i) {
					a = 'o';
				}
			}

			for (int f = 0; f < jugador1.nTail; f++)
            {
                if (jugador1.tailX[f] == jugador2.x && jugador1.tailY[f] == jugador2.y)
                {
                    obs[jugador2.y][jugador2.x] = '#';
                    colision = true;
                }
            }

            for (int t = 0; t < jugador2.nTail; t++) {
                if (jugador2.tailX[t] == jugador1.x && jugador2.tailY[t] == jugador1.y)
                {
                    obs[jugador1.y][jugador1.x] = '#';
                    colision = true;
                }
            }

			for (int m = 0; m < nFilas; m++) {
				for (int n = 0; n < nColumnas; n++) {
					if (obs[m][n] == '#' && i == m && j == n) {
						a = '#';
					}
				}
			}
			pantalla[i][j] = a;
            cout << pantalla[i][j];
        }
        cout << endl;
    }

    if (obs[jugador1.x][jugador1.y] == '#') {
        jugador1.x = nColumnas/2;
        jugador1.y = nFilas - 3;
    }

    if (obs[jugador2.x][jugador2.y] == '#') {
        jugador2.x = nColumnas/2;
        jugador2.y = 2;
    }
    cout << "Gusano 1 ( " << jugador1.x << " , " << jugador1.y << " )";
    cout << "    " << "Gusano 2 ( " << jugador2.x << " , " << jugador2.y << " )";
    for (int m = 0; m < nFilas; m++) {
        for (int n = 0; n < nColumnas; n++) {
            cout << obs[m][n];
        }
        cout << endl;
    }
    if (colision == true) {
		for (int e = 0; e < nFilas; e++) {
			for (int f = 0; f < nColumnas; f++) {
				if (obs[e][f] == '#') {
					cout << "\nGusano 1 - ";
					cout << "Gusano 2";
					cout << " ---> Chocaron en ( " <<  e<< " , " << f << " )";
				}
			}
		}
	}
	delete [] pantalla;
	delete [] obs;
}

void Tablero::posicion()
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

	switch (dira)
    {
        case 1:
            jugador1.x--;
            break;
        case 2:
            jugador1.x++;
            break;
        case 3:
            jugador1.y++;
            break;
        case 4:
            jugador1.y--;
            break;
    }

    switch (dirb)
    {
        case 5:
            jugador2.x--;
            break;
        case 6:
            jugador2.x++;
            break;
        case 7:
            jugador2.y++;
            break;
        case 8:
            jugador2.y--;
            break;
    }
}

void Tablero::delay()
{
	for (int c = 1; c <= 15000; c++) {
		for (int d = 1; d <= 15000; d++) {
		}
	}
}


void Tablero::inicio()
{
    jugador1.x = nColumnas/2;
	jugador1.y = nFilas - 3;
	jugador2.x = nColumnas/2;
	jugador2.y = 2;
}

bool Tablero::LOSE()
{
    if (jugador1.x == 0 || jugador1.x == nColumnas - 1 || jugador1.y == 0 || jugador1.y == nFilas - 1 || jugador2.x == 0 || jugador2.x == nColumnas - 1 || jugador2.y == 0 || jugador2.y == nFilas - 1)
    {
		return false;
	}
    return true;
}
