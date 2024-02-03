#include "Espada.h"

Espada::Espada(): Herramientas("Espada",0){}

Espada::~Espada(){}

int Espada::getCantidad() { return 7; }
void Espada::setCantidad(int n) { cantidad = n;  }
std::string Espada::getNombre() { return "Espada"; }