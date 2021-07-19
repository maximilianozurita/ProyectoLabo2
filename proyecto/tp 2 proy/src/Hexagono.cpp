#include "Hexagono.h"


Hexagono::Hexagono()
{
    for(int i = 0; i < 3; i++)
    {
        estructuras[i] = 0;
        nivel[i] = 0;
    }
}

//----------------------Sets
void Hexagono::setEstructuras(int numJugador)
{
    for(int i = 0; i < 3 ; i++)
    {
        if(estructuras[i] == 0)
        {
            estructuras[i] = numJugador;
            nivel[i] = 1;
            return ;
        }
    }
}

void Hexagono::fichaSetScale(float _x, float _y)
{
    valor.setScale(_x, _y);
}

void Hexagono::fichaSetPosition(float Tamx, float tamy)
{
    valor.setPosition(getPosition().x+(65*Tamx), getPosition().y+(85*tamy));
}

void Hexagono::setTipo(TIPO_HEX _tipo)
{
    tipo = _tipo;
}

void Hexagono::setFicha(Ficha _valor)
{
    valor = _valor;
}

//---------------Gets
TIPO_HEX Hexagono::getTipo()
{
    return tipo;
}

Ficha Hexagono::getFicha()
{
    return valor;
}

const int * Hexagono::getEstructuras()
{
    return estructuras;
}

const int * Hexagono::getNivel()
{
    return nivel;
}


//----------METODOS
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


void Hexagono::cargarFicha()
{
    valor.cargarFicha();
}


void Hexagono::subirNivel(int numJugador)
{
    for(int i = 0; i < 3; i++)
    {
        if(estructuras[i]==numJugador && nivel[i]==1)
        {
            nivel[i]++;
            return ;
        }
    }
}


void Hexagono::variarFicha()
{
    valor.variarFicha();
}

void Hexagono::setNumero(int _numero)
{
    numero = _numero;
}
int Hexagono::getNumero()
{
    return numero;
}
