#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>

class Entidad
{
    public:
        Entidad();
        sf::Texture getTex();
        sf::Sprite  getSp();
        void  setTex(sf::Texture);
        void  setSp(sf::Sprite);

    protected:
    sf::Texture tex;
    sf::Sprite sp;

};

#endif // ENTIDAD_H
