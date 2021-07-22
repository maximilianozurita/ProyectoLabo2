#ifndef JUGADOR_H
#define JUGADOR_H
#include "Hexagono.h"


class Jugador{
public:
    //gets
    const char* getUsuario();
    int getResultadoPartida();

    int getNumeroJugador();
    int getMadera();
    int getPiedra();
    int getLana();
    int getLadrillo();
    int getTrigo();
    int getPuntosVictoria();
    int getCasasConstruidas();
    int getCaminosConstruidos();
    int getCiudadesConstruidas();
    int setPuntosVictoria();

    //sets
    void setUsuario(char*);

    void setNumeroJugador(int);
    void setMadera(int);
    void setPiedra(int);
    void setLana(int);
    void setLadrillo(int);
    void setTrigo(int);
    void setPuntosVictoria(int);

    void setCasasConstruidas(int);
    void setCaminosConstruidos(int);
    void setCiudadesConstruidas(int);

    void addRecurso(int, TIPO_HEX);


private:
    char usuario[20];
    char password[20];
    int ResultadoPartida=0;


    int numeroJugador;
    int cartaMadera;
    int cartaPiedra;
    int cartaLana;
    int cartaLadrillo;
    int cartaTrigo;
    int puntosVictoria;
    int casasConstruidas;
    int caminosConstruidos;
    int ciudadesConstruidas;
};

#endif // JUGADOR_H
