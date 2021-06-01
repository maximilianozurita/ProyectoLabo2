#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Puerto.h"
#include "Map.h"
#include "Ladron.h"
#include "Dado.h"

//faltan incluir las demás clases que se usan como atributos

class GamePlay
{
    public:
        GamePlay();
        void run();
    private:
        sf::RendeWindow ventana;
        Jugador jugadores[4];
        Puerto puertos[9];
        Map mapa;
        Ladron ladron;
        Dado dado;

        void init();
        void update();
        void draw();
        void finish();
};

#endif // GAMEPLAY_H
