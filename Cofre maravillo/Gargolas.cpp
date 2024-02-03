#include "Gargolas.h"

Gargolas::Gargolas() :Enemigos(Tipo::AIRE, 40, "Gargolas",0) {}
Gargolas::~Gargolas(){}

std::string Gargolas::getNombre() { return "Gargolas"; }
int Gargolas::getCantidad() { return cantidad; }
void Gargolas::setCantidad(int k) { cantidad = k; }
int Gargolas::getHpAtaque() { return hpAtaque; }
Tipo Gargolas::getTipo() { return Tipo::AIRE; }
