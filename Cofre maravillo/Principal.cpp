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

    Juego j;

    std::cout << "¡Bienvenido al juego del cofre maravilloso!\n";
    std::cout << "Tu mision es encontrar el cofre maravilloso y derrotar a los enemigos, si es que el codigo sirve\n";
    std::cout << "En ese caso tu mision es descubrir como solucionar el codigo!.\n\n";
    std::cout << "Buena suerte, caballero.\n\n";

    int opcion;
   
   
        do {
            std::cout << "\nMenú:\n";
            std::cout << "1. Jugar\n";
            std::cout << "2. Salir\n";
            std::cout << "3. Guardar Partida\n";
            std::cout << "4. Cargar Partida\n";
            std::cout << "Ingrese su opción: ";
            std::cin >> opcion;


            switch (opcion) {
            case 1:

                j.jugar();
                break;
            case 2:
                std::cout << "Gracias por jugar. ¡Hasta luego!\n";

                break;
            case 3:
                std::cout << "Guardando Partida....\n";
                j.guardarPartida();
                break;
            case 4:
                std::cout << "Cargando Partida...\n";
                j.cargarPartida();
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }

        } while (opcion != 2);
    

    
	system("pause");
	return 0; 
}

