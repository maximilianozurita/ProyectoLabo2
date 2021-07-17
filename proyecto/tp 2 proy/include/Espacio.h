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

    void setEspacioCaminos(const int *);
    const int *getEspacioCaminos();

    void setEspacioCasas(const int *);
    const int *getEspacioCasas();

protected:
    int hexagonos[4];
    int espacioCaminos[4];
    int espacioCasas[2];
    int numero;
    bool disponible;
    bool ocupado;
};
/// Espacio auxEspacio = casa.getEspacio()
   ///     if()
    ///        hexagonos[auxEspacio.getHexagonos()[] != -1 ]
#endif // ESPACIO_H
