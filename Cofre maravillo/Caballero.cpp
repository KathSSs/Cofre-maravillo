
#include "Caballero.h"

void Caballero::setNombre(std::string n)
{
	nombre = n; 
}

Caballero::Caballero(){
	hp = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			inventario[i][j] = nullptr; 
		}
	}

}

Caballero::Caballero(std::string, Herramientas* inven) { 
	hp = 100;
for (int i = 0; i < 3; i++) {
	for (int j = 0; j < i; j++) {
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
std::string Caballero::getNombre() { return nombre; }
int Caballero::getHp() { return hp; }
void Caballero::setHp(int JD) { hp = JD; }