#include "Ogro.h"

Ogro::Ogro():Enemigos(Tipo::TIERRA, 35, "Ogro",12){}

Ogro::~Ogro(){} 

std::string Ogro::getNombre() { return nombre;  }
int Ogro::getCantidad() { return cantidad; }
void Ogro::setCantidad(int c) { cantidad = c;  }

int Ogro::getHpAtaque() { return 35; }
Tipo Ogro::getTipo() { return Tipo::TIERRA; }