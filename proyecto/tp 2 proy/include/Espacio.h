#ifndef ESPACIO_H
#define ESPACIO_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>

class Espacio: public Entidad {
public:

    bool isDisponible();
    bool isOcupado();
    bool getCoord();

    void setDisponible(bool);
    void setOcupado(bool);
    void setCoord(sf::Vector2f);

protected:
    bool disponible;
    bool ocupado;
    sf::Vector2f coord;
};

#endif // ESPACIO_H
