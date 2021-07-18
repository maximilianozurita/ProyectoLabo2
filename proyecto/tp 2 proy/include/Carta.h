#ifndef CARTA_H
#define CARTA_H
#include <SFML/Graphics.hpp>
#include "Hexagono.h"

class Carta: public Entidad
{
public:
    void setTipo(TIPO_HEX);
    TIPO_HEX getTipo();
    void cargarTextura();

private:
    TIPO_HEX tipo;
};

#endif // CARTA_H
