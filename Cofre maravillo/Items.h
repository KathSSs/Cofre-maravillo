#pragma once
#include "ElementosJuegos.h"

//Esta es la clase que se encarga de manejar
//la hierba y si en el futuro se quiere
//a�adir m�s items al juego 
class Items: public ElementosJuegos{
public:
	Items();
	~Items();
	int getIncrehp();

private:
	int hpIncremento;
};

