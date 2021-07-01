#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>

class Entidad: public sf::Sprite
{
public:
    Entidad();
    sf::Texture getTex();
    virtual void cargarTextura(char *);

protected:
    sf::Texture tex;


};

#endif // ENTIDAD_H
