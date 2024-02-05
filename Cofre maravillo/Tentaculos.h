#pragma once
#include "Enemigos.h"
class Tentaculos :
    public Enemigos
{
public: 
    Tentaculos(); 
    ~Tentaculos(); 
    std::string getNombre();
    int getCantidad();
    void setCantidad(int);
    int getHpAtaque();
    Tipo getTipo();

};

