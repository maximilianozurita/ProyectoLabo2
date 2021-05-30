#include "Ladron.h"

Ladron::Ladron()
{
    //ctor
}

sf::Vector2f Ladron::getUbicacion()
{
    return ubicacion;
}

void Ladron::setUbicacion(sf::Vector2f _ubicacion)
{
    ubicacion = _ubicacion;
}

void Ladron::reubicar(sf::Vector2f nuevaUbicacion)
{
    setUbicacion(nuevaUbicacion);
}

