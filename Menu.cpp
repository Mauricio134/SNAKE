#include "Menu.h"

Menu::Menu(){
    opcion = 0;
    cerrar = 0;
}

void Menu::menu_final(int obs[5][2],bool cha, bool chb)       // Menú del final de juego que pide presionar tecla pra reiniciar o salir
{
    system("cls");
    cout << "\n\n\n";
	cout << "================ " << "Game Over" << " ==================";
    cout << "\n\n";
    cout << "\n1) Estadisticas: " << endl;
	cout << endl;

	cout << "Gusano 1";
	if (cha == true) {
		cout << " --> Choco";
	}
	else {
		cout << " --> Intacto";
	}
	cout << "    " << "Gusano 2";
	if (chb == true) {
		cout << " --> Choco";
	}
	else {
		cout << " --> Intacto";
	}
	cout << endl;
	cout << "2) Colisiones: " << endl;

    for (int e = 0; e < 5; e++) {
        if (obs[e][0] != -1 && obs[e][1] != -1){
            cout << "\nGusano 1 - ";
            cout << "Gusano 2";
            cout << " ---> Chocaron en ( " << obs[e][0] << " , " << obs[e][1] << " ) \n" << endl;
        }
    }
	cout << "     " << "Presionar [x] para regresar a Menu" << endl;
	cout << "    " << "Presionar [q] para terminar de jugar" << endl;

	if (_kbhit())         // se registra pulsación
	{
		switch (_getch())   // dependiendo del caso se otorgan valores diferentes a las variables
		{
            case 'x':
                opcion = 0;
                break;
            case 'q':
                opcion = 0;
                cerrar = 1;
                break;
		}
	}
}

void Menu::menu_init()  // Menú del comienzo de juego que pide presionar tecla pra iniciar
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "================ " << "SNAKE 3.0" << " ==================" << endl;
	cout << "\n\n";
	cout << "     " << "Presionar [p] para empezar a jugar" << endl;

	if (_kbhit())  // se registra la pulsación para iniciar a jugar
	{
		switch (_getch())
		{
        case 'p':
			opcion = 1;
			break;
		}
	}
}

bool Menu::LOSE()       //Función que retorna bool para reinicar bucle en main y volver a jugar
{
    if (opcion == 1)
    {
		return false;
	}
    return true;
}

bool Menu::CERRAR()    //Función que retorna bool para reinicar bucle en main y volver a jugar
{
    if (cerrar == 1)
    {
		return false;
	}
    return true;
}
