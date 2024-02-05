#pragma once
#include "ElementosJuegos.h"
class CofreMaravilloso :
    public ElementosJuegos
{
public:
    CofreMaravilloso();
    ~CofreMaravilloso();
    std::string getNombre();
    int getCantidad();
    void setCantidad(int);

};

