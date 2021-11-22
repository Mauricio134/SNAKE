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
        while(tablero.LOSE() == true){
            tablero.tablero();
            tablero.jugador2.Cola();
            tablero.jugador1.Cola();
            tablero.posicion();
            tablero.delay();
        }
        while(menu.LOSE() == false){
            menu.menu_final(tablero.arr, tablero.cha, tablero.chb);
        }
    }
	return 0;
}
