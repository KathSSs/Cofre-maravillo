#pragma once
#include "Herramientas.h"

class Caballero{
private:
	std::string nombre; 
	int hp; 
	Herramientas* inventario[3][4]; 

public: 
	Caballero(); 
	Caballero(std::string, Herramientas* inven);
	~Caballero(); 
	std::string getNombre(); 
	int getHp();
	void setHp(int);
	void setNombre(std::string);
};

