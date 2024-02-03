#pragma once
#include "Herramientas.h"
class Daga :
    public Herramientas
{
public: 
    Daga();
    ~Daga();
    int getCantidad();
    void setCantidad(int);
    std::string getNombre();
};

