#ifndef LADRON_H
#define LADRON_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>


class Ladron: Entidad
{
    public:
        Ladron();
        sf::Vector2f getUbicacion();
        void setUbicacion(sf::Vector2f);
        void reubicar(sf::Vector2f);
    private:
        sf::Vector2f ubicacion;
};

#endif // LADRON_H
