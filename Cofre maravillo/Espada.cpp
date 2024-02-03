#include "Espada.h"

Espada::Espada(): Herramientas("Espada",7){}

Espada::~Espada(){}

int Espada::getCantidad() { return cantidad; }
void Espada::setCantidad(int n) { cantidad = n;  }
std::string Espada::getNombre() { return "Espada"; }