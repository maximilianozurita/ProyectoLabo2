#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Puerto.h"
#include "Map.h"
#include "Ladron.h"
#include "Dado.h"
#include "Estructura.h"
#include "Camino.h"
#include "Hexagono.h"

//faltan incluir las demás clases que se usan como atributos

class GamePlay
{
    public:
        GamePlay();
        void run();

    private:
        sf::RenderWindow ventana;
        Jugador jugadores[4];
        Puerto puertos[9];
        Map mapa;
        Ladron ladron;
        Dado dados[2];
        Estructura casa;
        Camino camino;
        Hexagono hexagonos[19];
        sf::Font fuente;
        sf::Text texto;
        Espacio espacioCaminos[72];
        Espacio espacioCasas[54];
        void init();
        void update();
        void draw();
        void finish();

};

#endif // GAMEPLAY_H
