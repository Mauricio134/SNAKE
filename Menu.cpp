#include "Menu.h"

Menu::Menu(){
    opcion = 0;
    cerrar = 0;
}

void Menu::menu_final()       // Menú del final de juego que pide presionar tecla pra reiniciar o salir
{
    system("cls");
    cout << "\n\n\n";
	cout << "================ " << "Game Over" << " ==================";
    cout << "\n\n";
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
