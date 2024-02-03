#pragma once
#include "Enemigos.h"
class Gargolas :
    public Enemigos
{
public:
    Gargolas();
    ~Gargolas(); 
    std::string getNombre();
    int getCantidad();
    void setCantidad(int);
    int getHpAtaque();
    Tipo getTipo();
};

