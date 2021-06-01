#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
//faltan incluir las demás clases que se usan como atributos

class GamePlay
{
    public:
        GamePlay();
        void run();
    private:
        sf::RendeWindow ventana;

        void init();
        void update();
        void draw();
        void finish();
};

#endif // GAMEPLAY_H
