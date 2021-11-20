#include "Tablero.h"
#include "Menu.h"

using namespace std;

int main() {
    Menu menu;
    while(menu.CERRAR() == true){
        while(menu.LOSE() == true){
            menu.menu_init();
        }
        system("cls");
        Tablero tablero;
        tablero.inicio();
        while(tablero.LOSE() == true){
            tablero.tablero();
            tablero.jugador2.Cola();
            tablero.jugador1.Cola();
            tablero.posicion();
            tablero.delay();
        }
        while(menu.LOSE() == false){
            menu.menu_final();
        }
    }
	return 0;
}
