#include <iostream>
using namespace std;
#include <cstring>
#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include "Dado.h"
#include<time.h>

void Dado::tirarDado(){
    srand(time(NULL));
    numero=rand()%6+1;

};
int Dado::getNumero(){
    return numero;
};





