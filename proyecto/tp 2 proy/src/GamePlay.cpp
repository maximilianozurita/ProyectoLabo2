#include "GamePlay.h"
#include <SFML/Graphics.hpp>

const float TAM=0.8;

GamePlay::GamePlay(){
    init();
}

void GamePlay::init(){
    //Matriz de coordenadas.
    const float difX=178*TAM,difY=145*TAM;

    const float coordMapaX=70,coordMapaY=40;
    const float coordX=coordMapaX+(225*TAM),coordY=coordMapaY+(50*TAM);


    float vecCoords[19][2]={
        coordX,coordY, coordX+difX,coordY, coordX+(difX*2),coordY,
        coordX-(difX/2),coordY+difY, coordX-(difX/2)+difX,coordY+difY, coordX-(difX/2)+(difX*2),coordY+difY, coordX-(difX/2)+(difX*3),coordY+difY,
        coordX-difX,coordY+(difY*2),  coordX-difX+difX,coordY+(difY*2),  coordX-difX+(difX*2),coordY+(difY*2),  coordX-difX+(difX*3),coordY+(difY*2),  coordX-difX+(difX*4),coordY+(difY*2),
        coordX-(difX/2),coordY+(difY*3), coordX-(difX/2)+difX,coordY+(difY*3), coordX-(difX/2)+(difX*2),coordY+(difY*3), coordX-(difX/2)+(difX*3),coordY+(difY*3),
        coordX,coordY+(difY*4), coordX+difX,coordY+(difY*4), coordX+(difX*2),coordY+(difY*4)
    };

    //Cargar ventana
    ventana.create(sf::VideoMode(1280,720),"Catan");
    ventana.setFramerateLimit(60);

    //Cargar texturas mapa
    mapa.getTex().loadFromFile("sprites/mapas/mapa2.png");
    mapa.getSp().setTexture(mapa.getTex());
    mapa.getSp().setScale(TAM,TAM);
    mapa.getSp().setPosition(coordMapaX,coordMapaY);
    ventana.draw(mapa.getSp());


/*
    //Cargar texturas casa roja (Prueba)
    casa.getTex().loadFromFile("sprites/estructuras/casaRoja.png");
    casa.getSp().setTexture(casa.getTex());
    casa.getSp().setScale(TAM,TAM);
    casa.getSp().setPosition(coordMapaX+(180*TAM),coordMapaY+(135*TAM));
    ventana.draw(casa.getSp());
*/
    casa.setCoord(sf::Vector2f(coordMapaX+(180*TAM),coordMapaY+(135*TAM)));

    //coordX-(405*TAM)=coordMapaX


    /*
    //Cargar textura camino
    camino.getTex().loadFromFile("sprites/estructuras/camino.png");
    camino.getSp().setTexture(camino.getTex());
    camino.getSp().setScale(TAM,TAM);
    camino.getSp().setPosition(coordX+100,coordY+90);
    ventana.draw(camino.getSp());
    */

    TIPO_HEX tiposHexagonos[19]={HEXARBOL,HEXTRIGO,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL,HEXMINERAL,HEXARBOL,HEXTRIGO,HEXLADRILLO,HEXTRIGO,HEXOVEJA,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXMINERAL,HEXDESIERTO};

    for (int i=0;i<19;i++){
        hexagonos[i].setTipo(tiposHexagonos[i]);
    }

/*
    //Cargar textura hexagonos
    for (int i=0;i<19;i++){
        hexagonos[i].cargarHexagono();
        hexagonos[i].getSp().setScale(TAM,TAM);
        hexagonos[i].getSp().setPosition(vecCoords[i][0], vecCoords[i][1]);
        ventana.draw(hexagonos[i].getSp());
        hexagonos[i].setUbicacion(sf::Vector2f(vecCoords[i][0], vecCoords[i][1]));
    }

    fuente.loadFromFile("fuentes/LEMONMILK-Bold.otf");
    texto.setFont(fuente);
    texto.setString("1");
    texto.setPosition(coordMapaX+(180*TAM), coordMapaY+(135*TAM));
*/
    //se cargan los objetos, texturas y posiciones.
}

void GamePlay::run(){
    while(ventana.isOpen()){
        sf::Event e;
        while(ventana.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                ventana.close();
            }
        }
        update();
        draw();
    }
}

void GamePlay::update(){

}

void GamePlay::draw(){
    ventana.clear(sf::Color(96, 159, 253));
    //Dibujar texturas
    ventana.draw(mapa.getSp());
    for (int i=0;i<19;i++){
        ventana.draw(hexagonos[i].getSp());
    };
    ventana.draw(casa.getSp());
    ventana.draw(camino.getSp());
    ventana.draw(texto);
    ventana.display();

}

void GamePlay::finish(){
    //se muestran cosas al finalizar el juego
}

