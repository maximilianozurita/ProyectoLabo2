#include <iostream>
using namespace std;
#include <cstring>
#include "Jugador.h"
#include <cstring>

char* Jugador::getUsuario(){
    return usuario;
};

int Jugador::getResultadoPartida(){
    return ResultadoPartida;
};

int Jugador::getNumeroJugador(){
    return numeroJugador;
};
int Jugador::getMadera(){
    return cartaMadera;
};
int Jugador::getPiedra(){
    return cartaPiedra;
};
int Jugador::getLana(){
    return cartaLana;
};
int Jugador::getLadrillo(){
    return cartaLadrillo;
};
int Jugador::getTrigo(){
    return cartaTrigo;
};
int Jugador::getPuntosVictoria(){
    return puntosVictoria;
};

int Jugador::getCasasConstruidas(){
    return casasConstruidas;
};

int Jugador::getCaminosConstruidos(){
    return caminosConstruidos;
};
int Jugador::getCiudadesConstruidas(){
    return ciudadesConstruidas;
};

//sets
void Jugador::setUsuario(char* _usuario){
    strcpy(usuario,_usuario);
};

void Jugador::setResultadoPartida(int _ganadas){
    ResultadoPartida=_ganadas;
};

void Jugador::setNumeroJugador(int _numero){
    numeroJugador=_numero;
};
void Jugador::setMadera(int _madera){
    cartaMadera=_madera;
};
void Jugador::setPiedra(int _piedra){
    cartaPiedra=_piedra;
};
void Jugador::setLana(int _lana){
    cartaLana=_lana;
};
void Jugador::setLadrillo(int _ladrillo){
    cartaLadrillo=_ladrillo;
};
void Jugador::setTrigo(int _trigo){
    cartaTrigo=_trigo;
};
void Jugador::setPuntosVictoria(int _pVictoria){
    puntosVictoria=_pVictoria;
};

void Jugador::setCasasConstruidas(int _casas){
    casasConstruidas=_casas;
};
void Jugador::setCaminosConstruidos(int _caminos){
    caminosConstruidos=_caminos;
};
void Jugador::setCiudadesConstruidas(int _ciudades){
    ciudadesConstruidas=_ciudades;
};

void Jugador::addRecurso(int cant, TIPO_HEX recurso)
{
    switch(recurso)
    {
        case HEXARBOL: cartaMadera+= cant;
                        break;
        case HEXTRIGO: cartaTrigo+= cant;
                        break;
        case HEXMINERAL: cartaPiedra+= cant;
                        break;
        case HEXLADRILLO: cartaLadrillo+= cant;
                        break;
        case HEXOVEJA: cartaLana+= cant;
                        break;
    }
}

    //METODOS archivo:
    //LEER EN DISCO
    bool Jugador::leerDeDisco(int pos)
    {
        FILE *p;
        p = fopen("jugador.dat", "rb");
        if (p == NULL){
            return false;
        }
        bool ok;
        fseek(p, sizeof(Jugador) * pos , 0);
        ok = fread(this, sizeof(Jugador), 1, p);
        fclose(p);
        return ok;
    }


    //GRABAR EN DISCO
    bool Jugador::grabarEnDisco()
    {
        FILE *p;
        p = fopen("jugador.dat", "ab");
        if (p == NULL){
            return false;
        }
        bool ok;
        ok = fwrite(this, sizeof(Jugador), 1, p);
        fclose(p);
        return ok;
    }

    //MODIFICAR EN DISCO
    bool Jugador::ModificarEnDisco(int pos)
    {
        bool guardo;
        FILE *p;
        p = fopen("jugador.dat", "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, sizeof(Jugador)*pos, SEEK_SET);
        guardo = fwrite(this, sizeof(Jugador), 1, p);
        fclose(p);
        return guardo;
    }
