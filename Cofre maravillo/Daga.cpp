#include "Daga.h"

Daga::Daga(): Herramientas("Daga",5){}

Daga::~Daga(){}

int Daga::getCantidad() { return cantidad; }
void Daga::setCantidad(int p) { cantidad = p; }
std::string Daga::getNombre() { return "Daga"; }

