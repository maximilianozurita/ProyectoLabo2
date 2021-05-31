#include <iostream>
using namespace std;
#include <cstring>
#include <SFML/Graphics.hpp>
#include "Espacio.h"


void Espacio::setEstado(bool _estado){
    estado=_estado;
};
bool Espacio::getEstado(){
    return estado;
};
