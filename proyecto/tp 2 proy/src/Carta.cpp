#include "Carta.h"

void Carta::setTipo(TIPO_HEX _tipo)
{
    tipo = _tipo;
}
TIPO_HEX Carta::getTipo()
{
    return tipo;
}

void Carta::cargarTextura()
{
    switch(tipo)
    {
    case HEXARBOL:
        tex.loadFromFile("sprites/recursos/cartaArbol.png");
        break;

    case HEXOVEJA:
        tex.loadFromFile("sprites/recursos/cartaOveja.png");
        break;

    case HEXLADRILLO:
        tex.loadFromFile("sprites/recursos/cartaLadrillo.png");
        break;

    case HEXTRIGO:
        tex.loadFromFile("sprites/recursos/cartaTrigo.png");
        break;

    case HEXMINERAL:
        tex.loadFromFile("sprites/recursos/cartaMineral.png");
        break;

    }
    setTexture(tex);
}
