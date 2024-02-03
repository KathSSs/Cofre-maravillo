#pragma once
#include "Enemigos.h"

class Ogro :
    public Enemigos{
public: 
    Ogro(); 
    ~Ogro();
    std::string getNombre();
        int getCantidad();
        void setCantidad(int);
        int getHpAtaque();
         Tipo getTipo();
};

