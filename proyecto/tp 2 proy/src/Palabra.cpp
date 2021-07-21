#include "Palabra.h"
#include <cstring>
#include <iostream>

using namespace std;
Palabra::Palabra()
{
    cout << "hola"<<endl;
    tam = 1;

}

int Palabra::getTamanio()
{
    return tam;
}
const char* Palabra::getPalabra()
{
    return v;
}
void Palabra::addChar(char letra)
{
    char* aux;
    tam++;
    strcpy(aux,v);
    delete v;
    v = new char[tam];
    strcpy(v,aux);
    v[tam-2] = letra;
    v[tam-1] = '\0';
}
void Palabra::backsp()
{
    v[tam-2] = '\0';
    tam--;
}

Palabra::~Palabra()
{
    delete v;
}
