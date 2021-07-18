#include "Ficha.h"


int Ficha::getNumero()
{
    return numero;
}
void Ficha::setNumero(int _numero)
{
    numero = _numero;
}

void Ficha::cargarFicha()
{
    switch(numero)
    {
        case 2: cargarTextura("sprites/recursos/numero2.png");
                break;
        case 3: cargarTextura("sprites/recursos/numero3.png");
                break;
        case 4: cargarTextura("sprites/recursos/numero4.png");
                break;
        case 5: cargarTextura("sprites/recursos/numero5.png");
                break;
        case 6: cargarTextura("sprites/recursos/numero6.png");
                break;
        case 8: cargarTextura("sprites/recursos/numero8.png");
                break;
        case 9: cargarTextura("sprites/recursos/numero9.png");
                break;
        case 10: cargarTextura("sprites/recursos/numero10.png");
                break;
        case 11: cargarTextura("sprites/recursos/numero11.png");
                break;
        case 12: cargarTextura("sprites/recursos/numero12.png");
                break;
    }
}

void Ficha::variarFicha()
{
    switch(numero)
    {
        case 2: cargarTextura("sprites/recursos/numeroB2.png");
                break;
        case 3: cargarTextura("sprites/recursos/numeroB3.png");
                break;
        case 4: cargarTextura("sprites/recursos/numeroB4.png");
                break;
        case 5: cargarTextura("sprites/recursos/numeroB5.png");
                break;
        case 6: cargarTextura("sprites/recursos/numeroB6.png");
                break;
        case 8: cargarTextura("sprites/recursos/numeroB8.png");
                break;
        case 9: cargarTextura("sprites/recursos/numeroB9.png");
                break;
        case 10: cargarTextura("sprites/recursos/numeroB10.png");
                break;
        case 11: cargarTextura("sprites/recursos/numeroB11.png");
                break;
        case 12: cargarTextura("sprites/recursos/numeroB12.png");
                break;
    }
}
