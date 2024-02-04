#ifndef JUEGO_H
#define JUEGO_H
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

class Juego{
private:
	Caballero caballero;
	ElementosJuegos* matriz[9][9];

public:
	Juego(); 
	~Juego();
	void inicializarTablero();
	void imprimirTablero(); 
	bool puedeDerrotarlo();
	void jugar();
	template <typename T>
	void colocarElementosAleatorios(int cantidad, char caracter);

	//metodos para usar archivos
	// tenemos que ver si van aqui
	//void guardarPartida();
	//void cargarPartida(); 
};

#endif JUEGO_H