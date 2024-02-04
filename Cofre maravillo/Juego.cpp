#include "Juego.h"

Juego::Juego() :caballero("Knight Camila") {
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9; j++) {
			matriz[i][j] = nullptr;
		}
	}
    colocarElementosAleatorios<Espada>(7, 'E');
    colocarElementosAleatorios <Ballesta>(6, 'B'); 
    colocarElementosAleatorios<Ogro>(12, 'O'); 

}

Juego::~Juego()
{
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if(matriz[i][j]!=nullptr)
           delete matriz[i][j];
        }
        delete matriz[i];
    }
    delete[]matriz;
}

void Juego::inicializarTablero()
{
     void colocarElementosAleatorios(int cantidad, char caracter);


}

void Juego::imprimirTablero()
{
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if (matriz[i][j] != nullptr) {
                std::cout << "\t" << matriz[i][j] <<"  ";
            }
        }
        std::cout << "\n";
    }
}

bool Juego::puedeDerrotarlo(Enemigos* enemi)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            Herramientas* aux = caballero.getHerramienta(i, j);
            if (typeid(*aux) == typeid(Ballesta)&& typeid(*enemi) == typeid(Gargolas)) {
                    return true;
            }
            else if (typeid(*aux) == typeid(Espada)) {
                if (typeid(*enemi) == typeid(Ogro) || typeid(*enemi) == typeid(Gargolas)) {
                    return true;
                }
            }
            else if (typeid(*aux) == typeid(Yesca) && typeid(*enemi) == typeid(Tentaculos)) {
                return true;
            }
            else if (typeid(*aux) == typeid(Daga) && typeid(*enemi) == typeid(Ogro)) {
                return true;
            }
            else
                //Aqui se podria añadir un metod para la disminución del hp
                return false;
        }
    }
}

void Juego::jugar()
{
    bool puedeDerrotarlo(Enemigos * enemi);
   
}



template <typename T>
void Juego:: colocarElementosAleatorios(int cantidad, char caracter) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> distribucion(0, 8);

    for (int i = 0; i < cantidad; ++i) {
        int x, y;
        do {
            x = distribucion(rng);
            y = distribucion(rng);
        } while (elementosJuego[x][y] != nullptr);

        elementosJuego[x][y] = new T();
        tablero[x][y] = caracter;
    }
}


