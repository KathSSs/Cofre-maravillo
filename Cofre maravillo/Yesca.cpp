#include "Yesca.h"

Yesca::Yesca(): Herramientas("Yesca",10){}

Yesca::~Yesca(){}

int Yesca::getCantidad() { return cantidad; }
void Yesca::setCantidad(int m) { cantidad = m; }
std::string Yesca::getNombre() { return "Yesca"; }

