#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "Entidad.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

class Estructura: public Entidad {
public:
    int getNumJugador();
    Espacio getEspacio();

    void setNumJugador(int);
    void setEspacio(Espacio);

private:
    int numJugador;
    Espacio espacio;

};

#endif // ESTRUCTURA_H

