#include <iostream>
using namespace std;
#include <cstring>
#include "Entidad.h"
#include <SFML/Graphics.hpp>

Entidad::Entidad()
{

}
sf::Texture Entidad::getTex()
{
    return tex;
}

void Entidad::cargarTextura(char * cadena)
{
    tex.loadFromFile(cadena);
    setTexture(tex);
}
void Entidad::setMostrar(bool _mostrar)
{
    mostrar = _mostrar;
}

bool Entidad::getMostrar()
{
    return mostrar;
}
