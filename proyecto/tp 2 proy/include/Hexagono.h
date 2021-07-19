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
    void setFicha(Ficha);//----->Set del objeto valor
    void fichaSetScale(float, float); //----->Set del objeto valor
    void fichaSetPosition(float, float); //----->Set del objeto valor

    //Gets
    TIPO_HEX getTipo();
    Ficha getFicha();
    const int * getEstructuras();
    const int * getNivel();

    //Metodos
    void cargarHexagono();
    void cargarFicha();
    void subirNivel(int);
    void variarFicha();


private:

    int estructuras[3];
    int nivel[3];

    TIPO_HEX tipo;
    Ficha valor;
};

#endif // HEXAGONO_H
