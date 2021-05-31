#ifndef CASA_H
#define CASA_H
#include "Espacio.h"
#include <SFML/Graphics.hpp>

class Casa: public Espacio{
public:
    void setCoord(sf::Vector2f);
    sf::Vector2f getCoord();

private:
    sf::Vector2f coord;
};

#endif // CASA_H
