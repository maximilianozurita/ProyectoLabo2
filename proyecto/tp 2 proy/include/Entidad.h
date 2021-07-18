#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>

class Entidad: public sf::Sprite
{
public:
    Entidad();
    sf::Texture getTex();
    void cargarTextura(char *);

    void setMostrar(bool);
    bool getMostrar();

protected:
    bool mostrar=true;
    sf::Texture tex;


};

#endif // ENTIDAD_H
