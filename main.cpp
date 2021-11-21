#include "Tablero.h"
#include "Menu.h"

using namespace std;

int main() {  
    Menu menu;                             //Creación de objeto menu para uso de metodos de clase
    while(menu.CERRAR() == true){
        while(menu.LOSE() == true){
            menu.menu_init();
        }
        system("cls");
        Tablero tablero;
        tablero.inicio();
        while(tablero.LOSE() == true){
<<<<<<< HEAD
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
=======
            tablero.tablero();            
            tablero.jugador2.Cola();  
            tablero.jugador1.Cola();
            tablero.posicion();
            tablero.delay();
>>>>>>> e18b9e1a8274009ec4dc873907cdde1a1f6135cc
        }
        while(menu.LOSE() == false){
            menu.menu_final();
        }
    }
	return 0;
}
