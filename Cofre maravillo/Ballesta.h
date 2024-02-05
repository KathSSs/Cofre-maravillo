#pragma once
#include "Herramientas.h"
class Ballesta :
    public Herramientas
{
public:
    Ballesta();
    ~Ballesta();
    int getCantidad();
    void setCantidad(int);
    std::string getNombre();


};

