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

enum ESTADO {TIRAR_DADO,SELECCIONAR_ACCION,CONSTRUCCION,COLOCACION_CASA,COLOCACION_EDIFICIO,COLOCACION_CAMINO,SELECCIONAR_HEX,SELECT_CASA,SELECT_CAMINO};
//faltan incluir las demas clases que se usan como atributos

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
        sf::Text textCargando;
        sf::Text textCantEstructuras[2][3];
        sf::Text mensaje;
        sf::Text errorMensaje;
        bool pressA;
        bool pressB;
        int contador;
        Espacio ultimo;
        Entidad cuadroInfo;
        Entidad figuras[2][3];



        Camino caminos[72];
        Hexagono hexagonos[19];
        //Ficha fichas[18];
        sf::Font fuente;
        sf::Font fuenteMensaje;
        sf::Text texto;
        sf::Text nombres[2];
        sf::Text nombre;
        sf::Text textTurno;
        Espacio espacioCaminos[72];
        Espacio espacioCasas[54];
        Espacio espacioCiudad[54];
        int turno;

        //BOTONES
        Entidad bConstruir, bFinalizar, bCasa, bEdificio, bCamino;

        void init();
        void update();
        void draw();
        void finish();


        void inicioJ();
        void cargarCaminos();
        void cargarHexagonos();
        void cargarVecEspacios();
        void cargarEspacios();

        void cargarVecCaminos();
        void cargarBotones();
        void cargarPuntuacion();
        sf::FloatRect achicarFloatRect(sf::FloatRect,float);
        void cambiarTurno();


};











#endif // GAMEPLAY_H

