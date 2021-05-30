#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>

class Entidad
{
    public:
        Entidad();
        sf::Texture getTex(){return tex;};
        sf::Sprite getSp(){return sp;};
        void setTex(sf::Texture _tex);
        void setSp(sf::Sprite _sp);
    protected:
        sf::Texture tex;
        sf::Sprite sp;
};

#endif // ENTIDAD_H
