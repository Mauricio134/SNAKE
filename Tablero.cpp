#include "Tablero.h"

Tablero::Tablero()
{
    pantalla = nullptr;
    cout<<"Ingrese número de filas: ";
    cin>>nFilas;
    cout<<"Ingrese número de columnas: ";
    cin>>nColumnas;
    Time = 0;
	jug1 = jugador1.jugador();
	jug2 = jugador2.jugador();
    a = ' ';
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
    system("cls");
    pantalla=new char*[nFilas];
    for(int i=0;i<nFilas;i++){
        pantalla[i]=new char[nColumnas];
    }
    Time++;
    jugador1.Timer = Time;

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
					a = '@';
				}
			}

			for (int m = 0; m < jugador2.nTail; m++) {
				if (jugador2.tailX[m] == j && jugador2.tailY[m] == i) {
					a = '@';
				}
			}

			pantalla[i][j] = a;
            cout << pantalla[i][j];
        }
        cout << endl;
    }
    delete[]pantalla;
    cout << "Gusano 1 ( " << jugador1.x << " , " << jugador1.y << " )";
    cout << "    " << "Gusano 2 ( " << jugador2.x << " , " << jugador2.y << " )";
}

bool Tablero::LOSE()
{
    if (jugador1.x == 0 || jugador1.x == nColumnas - 1 || jugador1.y == 0 || jugador1.y == nFilas - 1 || jugador2.x == 0 || jugador2.x == nColumnas - 1 || jugador2.y == 0 || jugador2.y == nFilas - 1)
    {
		return false;
	}
    return true;
}
