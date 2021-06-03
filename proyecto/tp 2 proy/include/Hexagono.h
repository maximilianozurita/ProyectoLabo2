#ifndef HEXAGONO_H
#define HEXAGONO_H
#include "Ficha.h"
#include "Entidad.h"
#include <SFML/Graphics.hpp>

enum TIPO_HEX {OVEJA, ARBOL, LADRILLO, MINERAL, TRIGO, DESIERTO};

class Hexagono: public Entidad{
public:
    Hexagono();
    sf::Vector2f getUbicacion();
    TIPO_HEX getTipo();
    Ficha getFicha();
    void setUbicacion(sf::Vector2f);
    void setTipo(TIPO_HEX);
    void setFicha(Ficha);
    void cargarHexagono(TIPO_HEX);

private:
    sf::Vector2f Ubicacion;
    TIPO_HEX tipo;
    Ficha valor;
};

#endif // HEXAGONO_H
