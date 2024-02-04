
#include "Caballero.h"

void Caballero::setNombre(std::string n)
{
	nombre = n; 
}

Herramientas* Caballero::getHerramienta(int i, int j)
{
	return inventario[i][j];
}

Caballero::Caballero(){
	hp = 100;
	nombre = "Caballero Misterioso"; 
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 4; j++) {
			inventario[i][j] = nullptr; 
		}
	}

}

Caballero::Caballero(std::string n) : nombre{ n }, hp{ 100 } {
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 4; j++) {
			inventario[i][j] = nullptr;
		}
	}
}



Caballero::Caballero(std::string m, Herramientas* inven) { 
	hp = 100;
for (int i = 0; i < 3; i++) {
	for (int j = i; j < 4; j++) {
		inventario[i][j] = inven;
	}
}


}



Caballero::~Caballero() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			delete inventario[i][j]; 
       
		}
		delete inventario[i]; 
	}
	delete[] inventario;
}

Herramientas* Caballero::setHerramientas(Herramientas* herramienta, int i, int j) {
	if (i >= 0 && i < 3 && j >= 0 && j < 4) {
		if (inventario[i][j] == nullptr) {
			inventario[i][j] = herramienta;
		}
		else {
			std::cout << "El espacio en el inventario ya está ocupado. No se pudo agregar la herramienta.\n";
		}
	}
	else {
		std::cout << "Índices fuera de rango. No se pudo agregar la herramienta al inventario.\n";
	}
}

void Caballero::eliminarHerramienta(int i, int j) {
	if (i >= 0 && i < 3 && j >= 0 && j < 4) {
		delete inventario[i][j];
		inventario[i][j] = nullptr;
	}
	else {
		// Manejar el caso cuando los índices están fuera de rango
		std::cout << "Índices fuera de rango. No se pudo eliminar la herramienta del inventario.\n";
	}
}

std::string Caballero::getNombre() { return nombre; }
int Caballero::getHp() { return hp; }
void Caballero::setHp(int JD) { hp = JD; }