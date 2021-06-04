#ifndef HEXAGONO_H
#define HEXAGONO_H
#include "Ficha.h"
#include "Entidad.h"
#include <SFML/Graphics.hpp>

enum TIPO_HEX {HEXOVEJA, HEXARBOL, HEXLADRILLO, HEXMINERAL, HEXTRIGO, HEXDESIERTO};

class Hexagono: public Entidad{
public:
    Hexagono();
    sf::Vector2f getUbicacion();
    TIPO_HEX getTipo();
    Ficha getFicha();
    void setUbicacion(sf::Vector2f);
    void setTipo(TIPO_HEX);
    void setFicha(Ficha);
    void cargarHexagono();

private:
    sf::Vector2f Ubicacion;
    TIPO_HEX tipo;
    Ficha valor;
};

#endif // HEXAGONO_H
