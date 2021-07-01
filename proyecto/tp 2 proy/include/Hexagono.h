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


    TIPO_HEX getTipo();
    Ficha getFicha();
    void setTipo(TIPO_HEX);
    void setFicha(Ficha);
    void cargarHexagono();
    void setEstructuras(int);

    const int * getEstructuras();
    const int * getNivel();

    void fichaSetScale(float, float);
    void fichaSetPosition(float, float);
    void cargarFicha();
    void subirNivel(int);


private:
    int estructuras[3]{};
    int nivel[3]{};

    TIPO_HEX tipo;
    Ficha valor;
};

#endif // HEXAGONO_H
