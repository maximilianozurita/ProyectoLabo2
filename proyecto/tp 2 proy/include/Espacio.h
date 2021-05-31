#ifndef ESPACIO_H
#define ESPACIO_H
#include "Entidad.h"

class Espacio: public Entidad {
public:
    void setEstado(bool);
    bool getEstado();

protected:
    bool estado;
};

#endif // ESPACIO_H
