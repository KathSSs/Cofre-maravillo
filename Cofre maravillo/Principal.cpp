#include "Juego.h"
#include "Tablero.h"

int main() {
	Caballero* caballero=new Caballero("Katy");
	Tablero* tab= new Tablero();
	Juego juego;

	juego.jugar();
	
	juego.imprimirTablero();

	system("pause");
	return 0; 
}

