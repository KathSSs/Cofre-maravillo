#ifndef CABALLERO_H
#define CABALLERO_H
#include "Herramientas.h"

class Caballero{
private:
	std::string nombre; 
	int hp; 
	Herramientas* inventario[3][4]; 

public: 
	Caballero(); 
	Caballero(std::string);
	Caballero(std::string, Herramientas* inven);
	~Caballero(); 
	std::string getNombre(); 
	int getHp();
	void setHp(int);
	void setNombre(std::string);
	Herramientas* getHerramienta(int i, int j);
	Herramientas* setHerramientas(Herramientas* , int , int );
	void eliminarHerramienta(int i, int j); 
};
#endif CABALLERO_H
