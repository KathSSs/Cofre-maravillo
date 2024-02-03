#include "Items.h"

Items::Items(): ElementosJuegos("Nombre", 6),hpIncremento { 15 } {}

Items::~Items(){}

int Items::getIncrehp(){return hpIncremento;}
