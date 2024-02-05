#pragma once
#include "Herramientas.h"
class Espada :
    public Herramientas
{
public:
    Espada();
    ~Espada();
    int getCantidad();
    void setCantidad(int);
    std::string getNombre();

};

