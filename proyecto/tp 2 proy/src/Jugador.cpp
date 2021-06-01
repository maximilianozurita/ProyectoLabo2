#include <iostream>
using namespace std;
#include <cstring>
#include "Jugador.h"
#include <cstring>

char* Jugador::getUsuario(){
    return usuario;
};

char* Jugador::getPassword(){
    return password;
};
int Jugador::getPartidasGanadas(){
    return partidasGanadas;
};

int Jugador::getNumeroJugador(){
    return numeroJugador;
};
int Jugador::getMadera(){
    return madera;
};
int Jugador::getPiedra(){
    return piedra;
};
int Jugador::getLana(){
    return lana;
};
int Jugador::getLadrillo(){
    return ladrillo;
};
int Jugador::getTrigo(){
    return trigo;
};
int Jugador::getPuntosVictoria(){
    return puntosVictoria;
};

int Jugador::setCasasConstruidas(){
    return casasConstruidas;
};
int Jugador::setCaminosConstruidos(){
    return caminosConstruidos;
};
int Jugador::setCiudadesConstruidas(){
    return ciudadesConstruidas;
};

//sets
void Jugador::setUsuario(char* _usuario){
    strcpy(usuario,_usuario);
};
void Jugador::setPassword(char* _password){
    strcpy(password,_password);
};

void Jugador::setPartidasGanadas(int _ganadas){
    partidasGanadas=_ganadas;
};

void Jugador::setNumeroJugador(int _numero){
    numeroJugador=_numero;
};
void Jugador::setMadera(int _madera){
    madera=_madera;
};
void Jugador::setPiedra(int _piedra){
    piedra=_piedra;
};
void Jugador::setLana(int _lana){
    lana=_lana;
};
void Jugador::setLadrillo(int _ladrillo){
    ladrillo=_ladrillo;
};
void Jugador::setTrigo(int _trigo){
    trigo=_trigo;
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
