#ifndef CAMINO_H
#define CAMINO_H
#include "Espacio.h"
#include "Estructura.h"
#include <SFML/Graphics.hpp>

class Camino: public Estructura{
public:
    void cargarTextura()override;
    void setEspacio(Espacio)override;
private:

};

#endif // CAMINO_H
