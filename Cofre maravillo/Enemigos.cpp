#include "Enemigos.h"

Enemigos::Enemigos(Tipo t, int Ataq, std::string n) : ElementosJuegos(n), tipo(t),hpAtaque(Ataq)
{}

Enemigos:: ~Enemigos() {}