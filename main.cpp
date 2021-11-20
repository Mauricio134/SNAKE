#include "Tablero.h"
#include "Funcion.h"
#include "Menu.h"

using namespace std;

int main() {
    Menu menu;
    int turn = 1;
    while(menu.CERRAR() == true){
        while(menu.LOSE() == true){
            menu.menu_init();
        }
        system("cls");
        Tablero tablero;
        tablero.inicio();
        while(tablero.LOSE() == true){
            tablero.tablero();
			tablero.jugador1.posicion();
            tablero.jugador1.Cola();
			tablero.jugador2.posicion2();
            tablero.jugador2.Cola2();
  
        }
        while(menu.LOSE() == false){
            menu.menu_final();
        }
    }
	return 0;
}
