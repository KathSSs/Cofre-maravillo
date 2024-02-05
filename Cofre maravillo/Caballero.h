#ifndef CABALLERO_H
#define CABALLERO_H
#include "Herramientas.h"

class Caballero{
private:
	std::string nombre; 
	int hp; 
	ElementosJuegos* inventario[3][4]; 

public: 
	Caballero(); 
	Caballero(std::string);
	Caballero(std::string, Herramientas* inven);
	~Caballero(); 
	std::string getNombre(); 
	int getHp();
	void setHp(int);
	void setNombre(std::string);
	ElementosJuegos* getHerramienta(int i, int j);
	//std::string toString(); //Hacerlo Katy
	bool setHerramientas(Herramientas* h, int , int );
	void eliminarHerramienta(int i, int j); 
};
#endif CABALLERO_H
