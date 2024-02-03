#include "Juego.h"

Juego::Juego() :caballero("Knight Camila") {
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9; j++) {
			matriz[i][j] = nullptr;
		}
	}

    colocarElementosAleatorios<Ogro>(12, 'O'); 

}


template <typename T>
void colocarElementosAleatorios(int cantidad, char caracter) {
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


