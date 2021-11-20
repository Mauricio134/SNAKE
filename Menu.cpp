#include "Menu.h"

Menu::Menu(){
    opcion = 0;
    cerrar = 0;
}

void Menu::menu_final()
{
    system("cls");
    cout << "\n\n\n";
	cout << "================ " << "Game Over" << " ==================";
    cout << "\n\n";
	cout << "     " << "Presionar [x] para regresar a Menu" << endl;
	cout << "    " << "Presionar [q] para terminar de jugar" << endl;

	if (_kbhit())
	{
		switch (_getch())
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

void Menu::menu_init()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "================ " << "SNAKE 3.0" << " ==================" << endl;
	cout << "\n\n";
	cout << "     " << "Presionar [p] para empezar a jugar" << endl;

	if (_kbhit())
	{
		switch (_getch())
		{
        case 'p':
			opcion = 1;
			break;
		}
	}
}

bool Menu::LOSE()
{
    if (opcion == 1)
    {
		return false;
	}
    return true;
}

bool Menu::CERRAR()
{
    if (cerrar == 1)
    {
		return false;
	}
    return true;
}
