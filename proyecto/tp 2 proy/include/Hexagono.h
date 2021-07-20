#ifndef HEXAGONO_H
#define HEXAGONO_H
#include "Ficha.h"
#include "Entidad.h"
#include "Estructura.h"
#include <SFML/Graphics.hpp>

enum TIPO_HEX {HEXOVEJA, HEXARBOL, HEXLADRILLO, HEXMINERAL, HEXTRIGO, HEXDESIERTO};

class Hexagono: public Entidad{
public:
    Hexagono();
    //Sets
    void setTipo(TIPO_HEX);
    void setEstructuras(int);
    void setFicha(Ficha _valor);
    void fichaSetScale(float _x, float _y);
    void fichaSetPosition(float Tamx, float tamy);
    //Gets
    TIPO_HEX getTipo();
    Ficha getFicha();
    const int * getNivel();
    const int * getEstructuras();
    void setNumero(int _numero);
    int getNumero();

    //Metodos
    void cargarHexagono();
    void cargarFicha();
    void subirNivel(int);
    void variarFicha();


private:

    int estructuras[3];
    int nivel[3];
    int numero;
    TIPO_HEX tipo;
    Ficha valor;
};

#endif // HEXAGONO_H


/*
cin <<
*/
