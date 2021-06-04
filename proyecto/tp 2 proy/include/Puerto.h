#ifndef PUERTO_H
#define PUERTO_H
#include "Entidad.h"

enum TIPO_PUERTO{OVEJA, ARBOL, LADRILLO, MINERAL, TRIGO};

class Puerto: public Entidad
{
public:
    Puerto();
    char *getIdentificacion();
    TIPO_PUERTO getTipo();
    void setIdentificacion(char *);
    void setTipo(TIPO_PUERTO);

private:
    char identificacion[2];
    TIPO_PUERTO tipo;

};

#endif // PUERTO_H
