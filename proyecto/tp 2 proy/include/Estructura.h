#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "Entidad.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

class Estructura: public Entidad {
public:
    int getNumJugador();
    Espacio getEspacio();
    virtual void setEspacio(Espacio);
    void setNumJugador(int);

protected:
    int numJugador;
    Espacio espacio;


};

#endif // ESTRUCTURA_H

