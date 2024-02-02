#pragma once
#include "ElementosJuegos.h"
class Tablero
{

private:
	ElementosJuegos* tablero[9][9];
public:

	Tablero();
	~Tablero();
	void ingresar(ElementosJuegos* tab);
	ElementosJuegos* getArma();
	bool revisaMatriz();

};

