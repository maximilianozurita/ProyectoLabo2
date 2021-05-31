#ifndef DADO_H
#define DADO_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>


class Dado: public Entidad {
public:
    void tirarDado();
    int getNumero();

private:
    int numero;
};

#endif // DADO_H
