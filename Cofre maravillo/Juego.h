#ifndef JUEGO_H
#define JUEGO_H
#include "ElementosJuegos.h"
#include "Caballero.h"
#include "Ogro.h"
class Juego{
private:
	Caballero caballero;
	ElementosJuegos* matriz[9][9];

public:
	Juego(); 
	~Juego();
	void inicializarTablero();
	void imprimirTablero(); 
	void jugar();

	//metodos para usar archivos
	// tenemos que ver si van aqui
	//void guardarPartida();
	//void cargarPartida(); 
};

#endif JUEGO_H