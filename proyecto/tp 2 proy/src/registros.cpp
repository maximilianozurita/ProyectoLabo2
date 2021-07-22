#include <iostream>
using namespace std;
#include <cstring>
#include "registros.h"



const char* registros::getPlayer1()
{
    return player1;
}
const char* registros::getPlayer2()
{
    return player2;

}

const char* registros::getGanador()
{
    return ganador;

}

//gets jugador 1
int registros::getCasas1()
{
    return casas1;
}
int registros::getCiudades1()
{

    return ciudades1;
}
int registros::getCaminos1()
{

    return caminos1;
}

//--gets jugador 2
int registros::getCasas2()
{
    return casas2;
}
int registros::getCiudades2()
{

    return ciudades2;
}
int registros::getCaminos2()
{

    return caminos2;
}

//------sets

void registros::setPlayer1(const char* car)
{
    strcpy(player1,car);
}
void registros::setPlayer2(const char* car)
{
    strcpy(player2,car);

}
void registros::setGanador(const char* car)
{

    strcpy(ganador,car);
}
//set jugador 1
void registros::setCasas1(int val)
{

    casas1=val;

}
void registros::setCiudades1(int val)
{
    ciudades1=val;
}
void registros::setCaminos1(int val)
{
    caminos1=val;
}
//sets jugador 2
void registros::setCasas2(int val)
{

    casas2=val;

}
void registros::setCiudades2(int val)
{
    ciudades2=val;
}
void registros::setCaminos2(int val)
{
    caminos2=val;
}

//----------

//LEER EN DISCO
bool registros::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("registro.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, sizeof(registros) * pos , 0);
    ok = fread(this, sizeof(registros), 1, p);
    fclose(p);
    return ok;
}


//GRABAR EN DISCO
bool registros::grabarEnDisco()
{
    FILE *p;
    p = fopen("registro.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(registros), 1, p);
    fclose(p);
    return ok;
}

//MODIFICAR EN DISCO
bool registros::ModificarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("registro.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, sizeof(registros)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(registros), 1, p);
    fclose(p);
    return guardo;
}
