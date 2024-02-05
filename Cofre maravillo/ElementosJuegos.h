#pragma once
#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
class ElementosJuegos
{
protected: 
	std::string nombre; 
	int cantidad ;
public:
	virtual std::string getNombre() = 0;
	virtual int getCantidad() = 0;
	virtual void setCantidad(int) = 0;
	ElementosJuegos(std::string t, int cant) { nombre = t; cantidad = cant; }

};

