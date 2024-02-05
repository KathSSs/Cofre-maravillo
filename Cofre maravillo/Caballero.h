#ifndef CABALLERO_H
#define CABALLERO_H
#include "Herramientas.h"
#include <sstream>
#include <fstream>
#include <fstream>

class Caballero{
private:
	std::string nombre; 
	int hp; 
	ElementosJuegos* inventario[3][4]; 

public: 
	Caballero(); 
	Caballero(std::string);
	Caballero(std::string, Herramientas* inven);
	Caballero(std::string, int h);
	~Caballero(); 
	std::string getNombre(); 
	int getHp();
	void setHp(int);
	void setNombre(std::string);
	ElementosJuegos* getHerramienta(int i, int j);
	void mostrarInventario(); 
	bool setHerramientas(Herramientas* h, int , int );
	void eliminarHerramienta(int i, int j); 
	void guardarPartida();
	Caballero* cargarPartida();
};
#endif CABALLERO_H
