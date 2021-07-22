#include <iostream>
#include <cstring>
#include "Estructura.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

using namespace std;

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
    setScale(espacio.getScale().x*0.55,espacio.getScale().y*0.55);

}

void Estructura::cargarTextura()
{

    switch(numJugador)
    {
        case 1: tex.loadFromFile("sprites/estructuras/casaRoja.png");
                break;

        case 2: tex.loadFromFile("sprites/estructuras/casaAzul.png");
                break;

        case 3: tex.loadFromFile("sprites/estructuras/casaVerde.png");
                break;
    }
    setTexture(tex);
}
void Estructura::cargarTextura(int _numJugador)
{
    switch(_numJugador)
    {
        case 1: tex.loadFromFile("sprites/estructuras/edificioRojo.png");
                break;

        case 2: tex.loadFromFile("sprites/estructuras/edificioAzul.png");
                break;

        case 3: tex.loadFromFile("sprites/estructuras/edificioVerde.png");
                break;
    }
    setTexture(tex);
    setPosition(espacio.getPosition().x+2,espacio.getPosition().y-10);
    setScale(0.5,0.5);
}
