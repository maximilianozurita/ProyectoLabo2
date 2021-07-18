#include <iostream>
using namespace std;
#include <cstring>
#include "Camino.h"
#include <SFML/Graphics.hpp>

void Camino::cargarTextura()
{
    char camino90G[40];
    char caminoM28G[40];
    char camino28G[40];

    switch(numJugador)
    {
        case 1: strcpy(camino90G,"sprites/estructuras/caminoRojo90G.png");
                strcpy(camino28G,"sprites/estructuras/caminoRojo28G.png");
                strcpy(caminoM28G,"sprites/estructuras/caminoRojo-28G.png");
                break;

        case 2: strcpy(camino90G,"sprites/estructuras/caminoAzul90G.png");
                strcpy(camino28G,"sprites/estructuras/caminoAzul28G.png");
                strcpy(caminoM28G,"sprites/estructuras/caminoAzul-28G.png");
                break;

        case 3: strcpy(camino90G,"sprites/estructuras/caminoVerde90G.png");
                strcpy(camino28G,"sprites/estructuras/caminoVerde28G.png");
                strcpy(caminoM28G,"sprites/estructuras/caminoVerde-28G.png");
                break;
    }

    if( espacio.getNumero() >= 0 && espacio.getNumero() < 48 )
    {
        if(espacio.getNumero() % 2 ==0)
            tex.loadFromFile(camino28G);
        else
            tex.loadFromFile(caminoM28G);
    }
    else
        tex.loadFromFile(camino90G);

    setTexture(tex);

}

void Camino::setEspacio(Espacio _espacio)
{
    espacio = _espacio;
    setPosition(espacio.getPosition());
    setScale(espacio.getScale());

}
