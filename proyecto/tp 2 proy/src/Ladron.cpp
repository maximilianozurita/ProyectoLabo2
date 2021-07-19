#include "Ladron.h"

Ladron::Ladron()
{
    //ctor
}

void Ladron::setHexagonoBloqueado(Hexagono _hexagono)
{
    hexagonoBloqueado = _hexagono;
}
Hexagono Ladron::getHexagonoBloqueado()
{
    return hexagonoBloqueado;
}
void Ladron::reubicar()
{
    sf::Vector2f tam = hexagonoBloqueado.getScale();
    setPosition(hexagonoBloqueado.getPosition().x+(65*tam.x),hexagonoBloqueado.getPosition().y+(85*tam.y));
}

void Ladron::setActivado(bool _activado)
{
    activado = _activado;
}

bool Ladron::isActivado()
{
    return activado;
}
