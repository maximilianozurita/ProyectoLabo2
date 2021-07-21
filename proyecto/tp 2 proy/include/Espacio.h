#ifndef ESPACIO_H
#define ESPACIO_H
#include "Entidad.h"
#include <SFML/Graphics.hpp>


class Espacio: public Entidad {
public:

    //Set
    void setEspacioCasas(const int *);
    void setDisponible(bool);
    void setOcupado(bool);
    void setNumero(int);
    void setEspacioCaminos(const int *);
    void setHexagonos(const int *);

    //get
    const int *getHexagonos();
    const int *getEspacioCasas();
    int getNumero();
    const int *getEspacioCaminos();
    bool isDisponible();
    bool isOcupado();

protected:
    int hexagonos[4];
    int espacioCaminos[4];
    int espacioCasas[2];
    int numero;
    bool disponible=true;
    bool ocupado=false;
};

#endif // ESPACIO_H
