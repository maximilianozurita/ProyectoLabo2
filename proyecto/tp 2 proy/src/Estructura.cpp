#include <iostream>
using namespace std;
#include <cstring>
#include "Estructura.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

int Estructura::getNumJugador()
{
    return numJugador;
}

Espacio Estructura::getEspacio()
{
    return espacio;
}

void Estructura::setNumJugador(int _numJugador)
{
    numJugador = _numJugador;
}

void Estructura::setEspacio(Espacio _espacio)
{
    espacio = _espacio;
    setPosition(espacio.getPosition().x-15,espacio.getPosition().y-18);
    setScale(espacio.getScale());
}
