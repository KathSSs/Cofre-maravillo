#pragma once
#include "ElementosJuegos.h"
#include "Herramientas.h"
static enum class Tipo { AIRE, TIERRA, AGUA, NINGUNO };

class Enemigos : public ElementosJuegos
{
public:
    Enemigos(Tipo, int,std::string, int cant);
    ~Enemigos();
    virtual std::string getNombre() = 0; 
   virtual int getCantidad() = 0;
   virtual void setCantidad() = 0;
    virtual int getHpAtaque()=0;
    virtual Tipo getTipo() = 0;
protected:
    Tipo tipo; 
   int hpAtaque; 
};

