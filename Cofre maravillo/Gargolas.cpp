#include "Gargolas.h"

Gargolas::Gargolas() :Enemigos(Tipo::AIRE, 40, "Gargolas",10) {}
Gargolas::~Gargolas(){}

std::string Gargolas::getNombre() { return nombre; }
int Gargolas::getCantidad() { return cantidad; }
void Gargolas::setCantidad(int k) { cantidad = k; }
int Gargolas::getHpAtaque() { return hpAtaque; }
Tipo Gargolas::getTipo() { return Tipo::AIRE; }
