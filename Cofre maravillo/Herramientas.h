#pragma once

#include "ElementosJuegos.h"
class Herramientas : public ElementosJuegos
{
public:
	Herramientas(std::string n, int cant);
	~Herramientas();
	virtual int getCantidad() = 0;
	virtual void setCantidad(int) = 0;
	virtual std::string getNombre() = 0;
};

