#include "Hexagono.h"


Hexagono::Hexagono(){

}

sf::Vector2f Hexagono::getUbicacion(){
    return Ubicacion;
}
TIPO_HEX Hexagono::getTipo(){
    return tipo;
}
Ficha Hexagono::getFicha(){
    return valor;
}
void Hexagono::setUbicacion(sf::Vector2f _ubicacion){
    Ubicacion = _ubicacion;
}

void Hexagono::setTipo(TIPO_HEX _tipo){
    tipo = _tipo;
}
void Hexagono::setFicha(Ficha _valor){
    valor = _valor;
}

void Hexagono::cargarHexagono(){

    switch(tipo){
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

    sp.setTexture(tex);
}
 Estructura& Hexagono::getCasas(int numJugador)
{
    return casas[numJugador];
}
