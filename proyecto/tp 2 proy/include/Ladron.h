#ifndef LADRON_H
#define LADRON_H
#include "Hexagono.h"
#include "Entidad.h"
#include <SFML/Graphics.hpp>


class Ladron:public Entidad
{
    public:
        Ladron();
        void setHexagonoBloqueado(Hexagono);
        void setActivado(bool);

        Hexagono getHexagonoBloqueado();
        bool isActivado();

        void reubicar();
    private:
        Hexagono hexagonoBloqueado;
        bool activado=false;
};

#endif // LADRON_H
