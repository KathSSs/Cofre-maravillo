#include "Ogro.h"

Ogro::Ogro():Enemigos(Tipo::TIERRA, 35, "Ogro",0){}

Ogro::~Ogro(){} 

std::string Ogro::getNombre() {
	return "Ogro";
}
int Ogro::getCantidad() {
	return 12;
}
void Ogro::setCantidad(int c) { cantidad = c;  }

int Ogro::getHpAtaque() { return 35; }
Tipo Ogro::getTipo() { return Tipo::TIERRA; }