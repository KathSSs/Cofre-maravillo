#include "Tablero.h"

Tablero::Tablero(){
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9;j++) {
			tablero[i][j] = nullptr;
		}
	}
}

Tablero::~Tablero()
{
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9;j++) {
			delete tablero[i][j];
		}
		delete tablero[i];
	}
	delete[]tablero;
}

void Tablero::ingresar(ElementosJuegos* tab)
{

	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9;j++) {
			tablero[i][j] = tab;
		}
	}
}

ElementosJuegos* Tablero::getArma()
{
	return tablero[0][0];
}

bool Tablero::revisaMatriz()
{
	if()
	return false;
}
