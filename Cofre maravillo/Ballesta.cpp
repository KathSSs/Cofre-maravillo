#include "Ballesta.h"

Ballesta::Ballesta(): Herramientas("Ballesta",0){}

Ballesta::~Ballesta(){}

int Ballesta::getCantidad() { return cantidad; }
void Ballesta::setCantidad(int l) { cantidad = l; }
std::string Ballesta::getNombre() { return "Ballesta"; }