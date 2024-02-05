#ifndef JUEGO_H
#define JUEGO_H
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

class Juego{
private:
	Caballero caballero;
	ElementosJuegos* matriz[9][9];
	char tablero[9][9];
public:
	Juego(); 
	~Juego();
	void inicializarTablero();
	void imprimirTablero(); 
	bool puedeDerrotarlo(Enemigos* enemi);
	bool reduccionDeVida(Enemigos*, Caballero& );
	ElementosJuegos* revisaSiesHerramienta(ElementosJuegos* elem );
	bool ingresaHerramienta(ElementosJuegos* elem,Caballero& );
	void jugar();
	template <typename T>
	void colocarElementosAleatorios(int cantidad, char caracter);

	//metodos para usar archivos
	// tenemos que ver si van aqui
	//void guardarPartida();
	//void cargarPartida(); 
};

#endif JUEGO_H