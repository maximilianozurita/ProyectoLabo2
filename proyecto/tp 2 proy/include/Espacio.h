#ifndef ESPACIO_H
#define ESPACIO_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>


class Espacio: public Entidad {
public:

    bool isDisponible();
    bool isOcupado();
    int getNumero();
    void setDisponible(bool);
    void setOcupado(bool);
    void setNumero(int);
    void setHexagonos(const int *);
    const int *getHexagonos();

protected:
    int hexagonos[4];
    int numero;
    bool disponible;
    bool ocupado;
};

#endif // ESPACIO_H
