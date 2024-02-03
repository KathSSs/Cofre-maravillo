#include "Tentaculos.h"

Tentaculos::Tentaculos() :Enemigos(Tipo::AGUA, 20, "Tentaculos",0) {}

Tentaculos::~Tentaculos(){}

std::string Tentaculos::getNombre() { return "Tentaculos"; }
int Tentaculos::getCantidad() { return cantidad; }
void Tentaculos::setCantidad(int j) { cantidad = j;  }
int Tentaculos::getHpAtaque() { return hpAtaque; }
Tipo Tentaculos::getTipo() { return Tipo::AGUA; }
