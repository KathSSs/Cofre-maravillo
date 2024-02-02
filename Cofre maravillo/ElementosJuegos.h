#pragma once
#include <iostream>
#include <string> 

class ElementosJuegos
{
protected: 
	std::string nombre; 

public:
	virtual std::string getNombre() = 0; 
	ElementosJuegos(std::string t) { nombre = t;  }
};

