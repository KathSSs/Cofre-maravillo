#pragma once
#include "ElementosJuegos.h"
class Items: public ElementosJuegos{
public:
	Items();
	~Items();
	int getIncrehp();

private:
	int hpIncremento;
};

