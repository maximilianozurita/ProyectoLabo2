#ifndef FICHA_H
#define FICHA_H
#include "Entidad.h"


class Ficha : public Entidad
{
public:

    int getNumero();
    void setNumero(int);
    void cargarFicha();
private:
    int numero;

};

#endif // FICHA_H
