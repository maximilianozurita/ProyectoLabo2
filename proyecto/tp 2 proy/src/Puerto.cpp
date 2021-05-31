#include "Puerto.h"
#include <cstring>


Puerto::Puerto()
{

}
char * Puerto::getIdentificacion()
{
    return identificacion;
}

TIPO_PUERTO Puerto::getTipo()
{
    return tipo;
}

void Puerto::setIdentificacion(char *cadena)
{
    strcpy(identificacion,cadena);
}

void Puerto::setTipo(TIPO_PUERTO _tipo)
{
    tipo = _tipo;
}
