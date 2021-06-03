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

void Hexagono::cargarHexagono(TIPO_Hex _tipo){


    tipo = _tipo;
    switch(tipo){
        case ARBOL:
            tex.loadFromFile("sprites/hexagonos/arbol.png");
            break;

        case OVEJA:
            tex.loadFromFile("sprites/hexagonos/oveja.png");
            break;

        case LADRILLO:
            tex.loadFromFile("sprites/hexagonos/ladrillo.png");
            break;

        case TRIGO:
            tex.loadFromFile("sprites/hexagonos/trigo.png");
            break;

        case MINERAL:
            tex.loadFromFile("sprites/hexagonos/mineral.png");
            break;

        case DESIERTO:
            tex.loadFromFile("sprites/hexagonos/desierto.png");
            break;
    }

    sp.setTexture(tex);
}
