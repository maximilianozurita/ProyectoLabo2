#ifndef DADO_H
#define DADO_H
#include "Entidad.h"


class Dado :: public Entidad
{
    public:
        Dado();
        int getNumero(){return numer}
    private:
        numero;
};

#endif // DADO_H
