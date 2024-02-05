#include "Juego.h"
#include "Tablero.h"
#include "Herramientas.h"
#include "ElementosJuegos.h"
#include <random>
#include "ElementosJuegos.h"
#include "Caballero.h"
#include "Ogro.h"
#include "Espada.h"
#include "Ballesta.h"
#include "Yesca.h"
#include "Daga.h"
#include "Tentaculos.h"
#include "Gargolas.h"
#include "Items.h"
#include "CofreMaravilloso.h"
#include <typeinfo>
#include <iostream>
#include <string>


int main() {
	
	
      
	std::cout << "¡Bienvenido al juego del cofre maravilloso!\n";
	std::cout << "Tu mision es encontrar el cofre maravilloso y derrotar a los enemigos.\n";
	std::cout << "Buena suerte, caballero.\n\n";
	Juego j;
	j.jugar(); 

	system("pause");
	return 0; 
}

