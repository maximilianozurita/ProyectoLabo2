#ifndef FICHA_H
#define FICHA_H
#include "Entidad.h"


class Ficha : public Entidad
{
public:
    Ficha();
    int getNumero();
    void setNumero(int);
private:
    int numero;

};

#endif // FICHA_H
