#include <iostream>
using namespace std;
#include <cstring>
#include <SFML/Graphics.hpp>
#include "Espacio.h"


bool Espacio::isDisponible()
{
    return disponible;

}
bool Espacio::isOcupado()
{
    return ocupado;
}

int Espacio::getNumero()
{
    return numero;
}

void Espacio::setDisponible(bool _disponible)
{
    disponible = _disponible;
}

void Espacio::setOcupado(bool _ocupado)
{
    ocupado = _ocupado;
}

void Espacio::setNumero(int _numero)
{
    numero = _numero;
}

void Espacio::setHexagonos(const int * _hexagonos)
{
    for(int i =0; i < 4; i++)
    {
        hexagonos[i] = _hexagonos[i];
    }
}
const int * Espacio::getHexagonos()
{
    return hexagonos;
}

void Espacio::setEspacioCaminos(const int * _espacioCaminos)
{
    for(int i = 0; i < 4; i++)
    {
        espacioCaminos[i] = _espacioCaminos[i];
    }
}

const int * Espacio::getEspacioCaminos()
{
    return espacioCaminos;
}

void Espacio::setEspacioCasas(const int * _espacioCasas)
{
    for(int i = 0; i < 2; i++)
    {
        espacioCasas[i] = _espacioCasas[i];
    }
}

const int *Espacio::getEspacioCasas()
{
    return espacioCasas;
}
