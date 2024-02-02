#pragma once
#include "ElementosJuegos.h"

enum class Tipo { AIRE, TIERRA, AGUA, NINGUNO };

class Enemigos : public ElementosJuegos
{
public:
    Enemigos(Tipo, int,std::string);
    ~Enemigos();
    virtual std::string getNombre() = 0; 
    virtual int getHpAtaque()=0;
    virtual Tipo getTipo() = 0; 
protected:
    Tipo tipo; 
   int hpAtaque; 
};

