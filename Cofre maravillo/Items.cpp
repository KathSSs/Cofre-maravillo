#include "Items.h"

Items::Items(): ElementosJuegos("Hierba", 6),hpIncremento { 15 } {}

Items::~Items(){}

int Items::getIncrehp(){return hpIncremento;}

std::string Items::getNombre() { return "Hierba"; }
int Items::getCantidad() { return 6; }
void Items::setCantidad(int c) { cantidad = c; }
