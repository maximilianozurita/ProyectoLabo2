#include <iostream>
using namespace std;
#include <cstring>
#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include "Dado.h"
#include<time.h>

void Dado::tirarDado(){

    numero=rand()%6+1;

    switch(numero)
    {
        case 1: cargarTextura("sprites/recursos/dado1.png");
                break;
        case 2: cargarTextura("sprites/recursos/dado2.png");
                break;
        case 3: cargarTextura("sprites/recursos/dado3.png");
                break;
        case 4: cargarTextura("sprites/recursos/dado4.png");
                break;
        case 5: cargarTextura("sprites/recursos/dado5.png");
                break;
        case 6: cargarTextura("sprites/recursos/dado6.png");
                break;
    }
};

int Dado::getNumero(){
    return numero;
};






