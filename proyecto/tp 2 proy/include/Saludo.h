#ifndef SALUDO_H
#define SALUDO_H
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Palabra.h"

enum ENTIDADES{RECTANGULO1,RECTANGULO2,RECT_NAME1,RECT_NAME2,LINEA_NAME};
enum DIALOGOS{TITULO,JUGAR,PUNTOS,JUGADOR,MSN1};
enum ESTADOS{S_INICIO,S_JUGAR};
class Saludo
{
public:
    Saludo();
    void run();

private:
    sf::RenderWindow ventana;;
    Entidad entidades[5];
    sf::Font fuente;
    sf::Text textDialogos[5];
    ESTADOS estado;
   // Palabra nombres[2];
    //sf::Text textNombres[2];


    bool bPress;

    void init();
    void update();
    void draw();
    void finish();
};

#endif // SALUDO_H
