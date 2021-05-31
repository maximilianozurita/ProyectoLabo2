#include "Hexagono.h"


Hexagono::Hexagono()
{

}

sf::Vector2f Hexagono::getUbicacion()
{
    return Ubicacion;
}
TIPO_HEX Hexagono::getTipo()
{
    return tipo;
}
Ficha Hexagono::getFicha()
{
    return valor;
}
void Hexagono::setUbicacion(sf::Vector2f _ubicacion)
{
    Ubicacion = _ubicacion;
}

void Hexagono::setTipo(TIPO_HEX _tipo)
{
    tipo = _tipo;
}
void Hexagono::setFicha(Ficha _valor)
{
    valor = _valor;
}
