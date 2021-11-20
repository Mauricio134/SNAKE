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
    X = -1;
    Y = -1;
    colision = false;
    sum = -1;
}

void Tablero::obstaculo(){
    obs=new int*[nFilas];
    for(int i=0;i<nFilas;i++){
        obs[i]=new int[nColumnas];
    }


    for (int j = 0; j < nFilas; j++){
        for (int k = 0; k < nColumnas; k++){
            obs[j][k] = 0;
        }
    }

    for (int f = 0; f < jugador1.nTail; f++)
    {
        if (jugador1.tailX[f] == jugador2.x && jugador1.tailY[f] == jugador2.y)
        {
            Y = jugador2.y;
            X = jugador2.x;
            colision = true;
            jugador2.x = nColumnas/2;
            jugador2.y = 2;
            sum++;
        }
        else if (jugador2.tailX[f] == jugador1.x && jugador2.tailY[f] == jugador1.y)
        {
            Y = jugador1.y;
            X = jugador1.x;
            colision = true;
            jugador1.x = nColumnas/2;
            jugador1.y = nFilas - 3;
            sum++;
        }
    }
    if (sum <= 5){
        arr[sum][0] = Y;
        arr[sum][1] = X;
    }

    for (int j = 0; j < nFilas; j++){
        for (int k = 0; k < nColumnas; k++){
            for (int x = 0; x < 5 ; x++){
                if (j == arr[x][0] && k == arr[x][1]){
                    obs[j][k] = 1;
                }
            }
        }
    }
    for (int a = 0; a<5;a++){
        if (jugador1.x == arr[a][1] && jugador1.y == arr[a][0]){
            jugador1.x = nColumnas/2;
            jugador1.y = nFilas - 3;
        }

        if (jugador2.x == arr[a][1] && jugador2.y == arr[a][0]) {
            jugador2.x = nColumnas/2;
            jugador2.y = 2;
        }

    }
    delete [] obs;
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
    for(int i=0;i<nFilas;i++){
        pantalla[i]=new char[nColumnas];
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

			obstaculo();

            for (int m = 0; m < nFilas; m++) {
				for (int n = 0; n < nColumnas; n++) {
					if (obs[m][n] == 1 && i == m && j == n) {
						a = '#';
					}
				}
			}
			pantalla[i][j] = a;
            cout << pantalla[i][j];
        }
        cout << endl;
    }
    cout << "Gusano 1 ( " << jugador1.x << " , " << jugador1.y << " )";
    cout << "    " << "Gusano 2 ( " << jugador2.x << " , " << jugador2.y << " )";
    if (colision == true) {
		for (int e = 0; e < nFilas; e++) {
			for (int f = 0; f < nColumnas; f++) {
				if (obs[e][f] == 1) {
					cout << "\nGusano 1 - ";
					cout << "Gusano 2";
					cout << " ---> Chocaron en ( " <<  e << " , " << f << " )";
				}
			}
		}
	}
	cout << endl;
	delete [] pantalla;
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

<<<<<<< HEAD
=======

void Tablero::inicio()
{
    jugador1.x = nColumnas/2;
	jugador1.y = nFilas - 3;
	jugador2.x = nColumnas/2;
	jugador2.y = 2;

    for(int i=0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            arr[i][j] = -1;
        }
    }
}

>>>>>>> dev
bool Tablero::LOSE()
{
    if (jugador1.x == 0 || jugador1.x == nColumnas - 1 || jugador1.y == 0 || jugador1.y == nFilas - 1 || jugador2.x == 0 || jugador2.x == nColumnas - 1 || jugador2.y == 0 || jugador2.y == nFilas - 1)
    {
		return false;
	}
    return true;
}
