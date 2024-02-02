#include "Enemigos.h"

Enemigos::Enemigos(Tipo t, int Ataq, std::string n, int cant) : ElementosJuegos(n, cant), tipo(t),hpAtaque(Ataq)
{}

Enemigos:: ~Enemigos() {}