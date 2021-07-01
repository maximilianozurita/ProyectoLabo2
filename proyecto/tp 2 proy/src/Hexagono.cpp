#include "Hexagono.h"


Hexagono::Hexagono()
{

}

TIPO_HEX Hexagono::getTipo()
{
    return tipo;
}
Ficha Hexagono::getFicha()
{
    return valor;
}

void Hexagono::setTipo(TIPO_HEX _tipo)
{
    tipo = _tipo;
}
void Hexagono::setFicha(Ficha _valor)
{
    valor = _valor;
}

void Hexagono::cargarHexagono()
{

    switch(tipo)
    {
    case HEXARBOL:
        tex.loadFromFile("sprites/hexagonos/arbol.png");
        break;

    case HEXOVEJA:
        tex.loadFromFile("sprites/hexagonos/oveja.png");
        break;

    case HEXLADRILLO:
        tex.loadFromFile("sprites/hexagonos/ladrillo.png");
        break;

    case HEXTRIGO:
        tex.loadFromFile("sprites/hexagonos/trigo.png");
        break;

    case HEXMINERAL:
        tex.loadFromFile("sprites/hexagonos/mineral.png");
        break;

    case HEXDESIERTO:
        tex.loadFromFile("sprites/hexagonos/desierto.png");
        break;
    }

    setTexture(tex);
}
const Estructura* Hexagono::getCasas(int numJugador)
{
    return casas[numJugador];
}

void Hexagono::fichaSetScale(float _x, float _y)
{
    valor.setScale(_x, _y);
}

void Hexagono::fichaSetPosition(float Tamx  , float tamy)
{
    valor.setPosition(getPosition().x+(65*Tamx), getPosition().y+(85*tamy));
}
void Hexagono::cargarFicha()
{
    valor.cargarFicha();
}
