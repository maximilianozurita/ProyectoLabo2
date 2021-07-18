#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include "Ficha.h"
#include "Jugador.h"
#include "Puerto.h"
#include "Map.h"
#include "Ladron.h"
#include "Dado.h"
#include "Estructura.h"
#include "Camino.h"
#include "Hexagono.h"
#include "Carta.h"

enum ESTADO {TIRAR_DADO,SELECCIONAR_ACCION,CONSTRUCCION,COLOCACION_CASA,COLOCACION_EDIFICIO,COLOCACION_CAMINO};
//faltan incluir las dem�s clases que se usan como atributos

class GamePlay
{
    public:
        GamePlay();
        void run();

    private:
        ESTADO estado;
        sf::RenderWindow ventana;
        Jugador jugadores[4];
        Puerto puertos[9];
        Map mapa;
        Ladron ladron;
        Dado dados[2];
        Estructura casas[54];
        Carta cartas[2][5];
        sf::Text textCartasPuntos[2][5];
        sf::Text textNumCaminos[72];
        bool pressA;

        Camino caminos[72];
        Hexagono hexagonos[19];
        ///Ficha fichas[18];
        sf::Font fuente;
        sf::Text texto;
        Espacio espacioCaminos[72];
        Espacio espacioCasas[54];
        int turno;

        ///BOTONES
        Entidad bConstruir, bFinalizar, bCasa, bEdificio, bCamino;

        void init();
        void update();
        void draw();
        void finish();


        void cargarCaminos();
        void cargarHexagonos();
        void cargarVecEspacios();
        void cargarEspacios();

        void cargarVecCaminos();
        void cargarBotones();
        void prueba();

};

#endif // GAMEPLAY_H

