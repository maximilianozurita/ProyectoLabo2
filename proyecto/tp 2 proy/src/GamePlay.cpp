#include "GamePlay.h"
#include <SFML/Graphics.hpp>

const float coordX=50,coordY=50;
const float Xscale=0.8,Yscale=0.8;

GamePlay::GamePlay(){
    init();
}



void GamePlay::init(){

    float vecCoords[19][2]={
        coordX,coordY, coordX+difX,coordY, coordX+(difX*2),coordY,
        coordX-(difX/2),coordY+difY, coordX-(difX/2)+difX,coordY+difY, coordX-(difX/2)+(difX*2),coordY+difY, coordX-(difX/2)+(difX*3),coordY+difY,
        coordX-difX,coordY+(difY*2),  coordX-difX+difX,coordY+(difY*2),  coordX-difX+(difX*2),coordY+(difY*2),  coordX-difX+(difX*3),coordY+(difY*2),  coordX-difX+(difX*4),coordY+(difY*2),
        coordX-(difX/2),coordY+(difY*3), coordX-(difX/2)+difX,coordY+(difY*3), coordX-(difX/2)+(difX*2),coordY+(difY*3), coordX-(difX/2)+(difX*3),coordY+(difY*3),
        coordX,coordY+(difY*4), coordX+difX,coordY+(difY*4), coordX+(difX*2),coordY+(difY*4)
    }

    ventana.create(sf::VideoMode(1280,720),"Catan");
    ventana.setFramerateLimit(60);
    mapa.getTex().loadFromFile("sprites/mapas/mapa2.png");
    mapa.getSp().setTexture(mapa.getTex());
    mapa.getSp().setScale(Xscale,Yscale);
    mapa.getSp().setPosition(X,Y);
    ventana.draw(mapa.getSp());

    casa.getTex().loadFromFile("sprites/estructuras/casaRoja.png");
    casa.getSp().setTexture(casa.getTex());
    casa.getSp().setScale(Xscale,Yscale);
    casa.getSp().setPosition(X+50,Y+50);
    ventana.draw(casa.getSp());

    camino.getTex().loadFromFile("sprites/estructuras/camino.png");
    camino.getSp().setTexture(camino.getTex());
    camino.getSp().setScale(Xscale,Yscale);
    camino.getSp().setPosition(X+100,Y+90);
    ventana.draw(camino.getSp());


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
    ventana.draw(mapa.getSp());
    ventana.draw(casa.getSp());
    ventana.draw(camino.getSp());
    ventana.display();

}

void GamePlay::finish(){
    //se muestran cosas al finalizar el juego
}

