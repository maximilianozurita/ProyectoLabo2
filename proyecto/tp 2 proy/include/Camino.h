#ifndef CAMINO_H
#define CAMINO_H
#include "Espacio.h"
#include <SFML/Graphics.hpp>

class Camino: public Espacio {
public:
    void setCoord(sf::Vector2f);
    sf::Vector2f getCoord();

private:
    sf::Vector2f coord;
    //Inclinación
};

#endif // CAMINO_H
