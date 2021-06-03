#include "GamePlay.h"
#include <SFML/Graphics.hpp>
GamePlay::GamePlay(){
    init();
}

void GamePlay::init(){

    ventana.create(sf::VideoMode(840,800),"Catan");
    ventana.setFramerateLimit(60);


    //se cargan los objetos, texturas y posiciones.
}

void GamePlay::run(){

    while(ventana.isOpen())
    {

        sf::Event e;
        while(ventana.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                ventana.close();
        }

        update();

        draw();
    }
}

void GamePlay::update(){

}

void GamePlay::draw(){
    ventana.clear(sf::Color(96, 159, 253));
    ventana.display();
}

void GamePlay::finish(){
    //se muestran cosas al finalizar el juego
}

