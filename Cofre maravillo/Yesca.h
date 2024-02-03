#pragma once
#include "Herramientas.h"
class Yesca :
    public Herramientas
{
public:
    Yesca();
    ~Yesca();
    int getCantidad();
    void setCantidad(int);
    std::string getNombre();
};

