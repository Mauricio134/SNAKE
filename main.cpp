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
<<<<<<< HEAD
			tablero.jugador1.posicion();
            tablero.jugador1.Cola();
			tablero.jugador2.posicion2();
            tablero.jugador2.Cola2();
  
=======
            tablero.jugador2.Cola();
            tablero.jugador1.Cola();
            tablero.posicion();
            tablero.delay();
>>>>>>> dev
        }
        while(menu.LOSE() == false){
            menu.menu_final();
        }
    }
	return 0;
}
