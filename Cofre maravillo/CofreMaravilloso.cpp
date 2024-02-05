#include "CofreMaravilloso.h"

CofreMaravilloso::CofreMaravilloso(): ElementosJuegos("Cofre Maravilloso",1){}

CofreMaravilloso::~CofreMaravilloso(){}


std::string CofreMaravilloso::getNombre() { return nombre; }
int CofreMaravilloso::getCantidad() { return cantidad; }
void CofreMaravilloso::setCantidad(int x) { cantidad = x; }


