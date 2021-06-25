#include "GamePlay.h"
#include <SFML/Graphics.hpp>

const float TAM=0.7;

GamePlay::GamePlay()
{
    init();
}

void GamePlay::init()
{
    //Matriz de coordenadas.


    const float mapCoordX=100;
    const float mapCoordY=60;

    const float hexCoordX=mapCoordX+(225*TAM);
    const float hexCoordY=mapCoordY+(50*TAM);
    const float difX=178*TAM;
    const float difY=145*TAM;

    const float estructCoordX=mapCoordX+(295*TAM);
    const float estructCoordY=mapCoordY+(20*TAM);

    const float estruct2CoordX=mapCoordX+(205*TAM);
    const float estruct2CoordY=mapCoordY+(68*TAM);

    const float estructDifX=178*TAM;
    const float estructDifY=145*TAM;


    float vecCoords[19][2]=
    {
        hexCoordX,hexCoordY, hexCoordX+difX,hexCoordY, hexCoordX+(difX*2),hexCoordY,
        hexCoordX-(difX/2),hexCoordY+difY, hexCoordX-(difX/2)+difX,hexCoordY+difY, hexCoordX-(difX/2)+(difX*2),hexCoordY+difY, hexCoordX-(difX/2)+(difX*3),hexCoordY+difY,
        hexCoordX-difX,hexCoordY+(difY*2),  hexCoordX-difX+difX,hexCoordY+(difY*2),  hexCoordX-difX+(difX*2),hexCoordY+(difY*2),  hexCoordX-difX+(difX*3),hexCoordY+(difY*2),  hexCoordX-difX+(difX*4),hexCoordY+(difY*2),
        hexCoordX-(difX/2),hexCoordY+(difY*3), hexCoordX-(difX/2)+difX,hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*2),hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*3),hexCoordY+(difY*3),
        hexCoordX,hexCoordY+(difY*4), hexCoordX+difX,hexCoordY+(difY*4), hexCoordX+(difX*2),hexCoordY+(difY*4)
    };

    float espacioCoords[54][2]=
    {
        estructCoordX,estructCoordY, estructCoordX+estructDifX,estructCoordY, estructCoordX+(estructDifX*2),estructCoordY ,
        estruct2CoordX,estruct2CoordY, estruct2CoordX+estructDifX,estruct2CoordY , estruct2CoordX+(estructDifX*2),estruct2CoordY , estruct2CoordX+(estructDifX*3),estruct2CoordY ,
        estructCoordX-(estructDifX*0.5),estructCoordY+estructDifY , estructCoordX+(estructDifX*0.5),estructCoordY+estructDifY , estructCoordX+(estructDifX*1.5),estructCoordY+estructDifY , estructCoordX+(estructDifX*2.5),estructCoordY+estructDifY ,
        estruct2CoordX-(estructDifX*0.5),estruct2CoordY+estructDifY , estruct2CoordX+(estructDifX*0.5),estruct2CoordY+estructDifY , estruct2CoordX+(estructDifX*1.5),estruct2CoordY+estructDifY , estruct2CoordX+(estructDifX*2.5),estruct2CoordY+estructDifY , estruct2CoordX+(estructDifX*3.5),estruct2CoordY+estructDifY ,
        estructCoordX-estructDifX,estructCoordY+(estructDifY*2) , estructCoordX,estructCoordY+(estructDifY*2) , estructCoordX+estructDifX,estructCoordY+(estructDifY*2) , estructCoordX+(estructDifX*2),estructCoordY+(estructDifY*2) , estructCoordX+(estructDifX*3),estructCoordY+(estructDifY*2) ,
        estruct2CoordX-estructDifX,estruct2CoordY+(estructDifY*2) , estruct2CoordX,estruct2CoordY+(estructDifY*2) ,estruct2CoordX+estructDifX,estruct2CoordY+(estructDifY*2) , estruct2CoordX+(estructDifX*2),estruct2CoordY+(estructDifY*2) , estruct2CoordX+(estructDifX*3),estruct2CoordY+(estructDifY*2) , estruct2CoordX+(estructDifX*4),estruct2CoordY+(estructDifY*2) ,
        estructCoordX-(estructDifX*1.5),estructCoordY+(estructDifY*3) , estructCoordX-(estructDifX*0.5),estructCoordY+(estructDifY*3) , estructCoordX+(estructDifX*0.5),estructCoordY+(estructDifY*3) , estructCoordX+(estructDifX*1.5),estructCoordY+(estructDifY*3) , estructCoordX+(estructDifX*2.5),estructCoordY+(estructDifY*3) , estructCoordX+(estructDifX*3.5),estructCoordY+(estructDifY*3) ,
        estruct2CoordX-(estructDifX*0.5),estruct2CoordY+(estructDifY*3) , estruct2CoordX+(estructDifX*0.5),estruct2CoordY+(estructDifY*3) , estruct2CoordX+(estructDifX*1.5),estruct2CoordY+(estructDifY*3) , estruct2CoordX+(estructDifX*2.5),estruct2CoordY+(estructDifY*3) , estruct2CoordX+(estructDifX*3.5),estruct2CoordY+(estructDifY*3) ,
        estructCoordX-estructDifX,estructCoordY+(estructDifY*4) , estructCoordX,estructCoordY+(estructDifY*4) , estructCoordX+estructDifX,estructCoordY+(estructDifY*4) , estructCoordX+(estructDifX*2),estructCoordY+(estructDifY*4) , estructCoordX+(estructDifX*3),estructCoordY+(estructDifY*4) ,
        estruct2CoordX,estruct2CoordY+(estructDifY*4) , estruct2CoordX+estructDifX,estruct2CoordY+(estructDifY*4) , estruct2CoordX+(estructDifX*2),estruct2CoordY+(estructDifY*4) , estruct2CoordX+(estructDifX*3),estruct2CoordY+(estructDifY*4) ,
        estructCoordX-(estructDifX*0.5),estructCoordY+(estructDifY*5) , estructCoordX+(estructDifX*0.5),estructCoordY+(estructDifY*5) , estructCoordX+(estructDifX*1.5),estructCoordY+(estructDifY*5) , estructCoordX+(estructDifX*2.5),estructCoordY+(estructDifY*5) ,
        estruct2CoordX+(estructDifX*0.5),estruct2CoordY+(estructDifY*5) , estruct2CoordX+(estructDifX*1.5),estruct2CoordY+(estructDifY*5) , estruct2CoordX+(estructDifX*2.5),estruct2CoordY+(estructDifY*5)
    };

    for(int i=0; i < 54 ; i++ )
    {
        espacioCasas[i].getTex().loadFromFile("sprites/recursos/seleccionador.png");
        espacioCasas[i].getSp().setTexture(espacioCasas[0].getTex());
        espacioCasas[i].getSp().setScale(TAM*1.8,TAM*1.8);
        espacioCasas[i].getSp().setPosition(espacioCoords[i][0],espacioCoords[i][1]);
    }
    float vecCoordCaminos[72][2] =
    {

    };
    //Cargar ventana
    ventana.create(sf::VideoMode(1280,720),"Catan");
    ventana.setFramerateLimit(60);

    //Cargar texturas mapa
    mapa.getTex().loadFromFile("sprites/mapas/mapa2.png");
    mapa.getSp().setTexture(mapa.getTex());
    mapa.getSp().setScale(TAM,TAM);
    mapa.getSp().setPosition(mapCoordX,mapCoordY);
    ventana.draw(mapa.getSp());


    /*
        //Cargar texturas casa roja (Prueba)
        casa.getTex().loadFromFile("sprites/estructuras/casaRoja.png");
        casa.getSp().setTexture(casa.getTex());
        casa.getSp().setScale(TAM,TAM);
        casa.getSp().setPosition(mapCoordX+(180*TAM),mapCoordY+(135*TAM));
        ventana.draw(casa.getSp());
    */
    //casa.setCoord(sf::Vector2f(mapCoordX+(180*TAM),mapCoordY+(135*TAM)));

    //hexCoordX-(405*TAM)=mapCoordX


    //Cargar textura camino
    camino.getTex().loadFromFile("sprites/estructuras/verde28G.png");
    camino.getSp().setTexture(camino.getTex());
    camino.getSp().setScale(TAM,TAM);
    camino.getSp().setPosition(hexCoordX+100,hexCoordY+90);
    ///ventana.draw(camino.getSp());


    TIPO_HEX tiposHexagonos[19]= {HEXARBOL,HEXTRIGO,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL,HEXMINERAL,HEXARBOL,HEXTRIGO,HEXLADRILLO,HEXTRIGO,HEXOVEJA,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXMINERAL,HEXDESIERTO};
    bool asignados[19] {};
    for (int i=0; i<19; i++)
    {
        hexagonos[i].setTipo(tiposHexagonos[i]);
    }


    //Cargar textura hexagonos
    for (int i=0; i<19; i++)
    {
        hexagonos[i].cargarHexagono();
        hexagonos[i].getSp().setScale(TAM,TAM);
        hexagonos[i].getSp().setPosition(vecCoords[i][0], vecCoords[i][1]);
        ventana.draw(hexagonos[i].getSp());
        hexagonos[i].setUbicacion(sf::Vector2f(vecCoords[i][0], vecCoords[i][1]));
    }

    /*fuente.loadFromFile("fuentes/LEMONMILK-Bold.otf");
    texto.setFont(fuente);
    texto.setString("1");
    texto.setPosition(mapCoordX+(180*TAM), mapCoordY+(135*TAM));*/

    //se cargan los objetos, texturas y posiciones.

    dados[1].tirarDado();
    dados[0].tirarDado();

    for(int i=0; i < 54; i++)
    {
        ventana.draw(espacioCasas[i]);
    }
}

void GamePlay::run()
{
    while(ventana.isOpen())
    {
        sf::Event e;
        while(ventana.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                ventana.close();
            }
        }
        update();
        draw();
    }
}

void GamePlay::update()
{
    Ficha auxFicha;
    TIPO_HEX aux;

    for(int i = 0; i < 19; i++)
    {
        auxFicha = hexagonos[i].getFicha();
        if(auxFicha.getNumero() == dados[0].getNumero() + dados[1].getNumero())


            for(int j = 0; j < 3; j++)
            {
                hexagonos[i].getTipo();


                switch(aux)
                {

                case HEXARBOL:
                    jugadores[hexagonos[i].getCasas(j).getNumJugador()].setMadera(jugadores[hexagonos[i].getCasas(j).getNumJugador()].getMadera()+1);
                    break;

                case HEXLADRILLO:
                    jugadores[hexagonos[i].getCasas(j).getNumJugador()].setLadrillo(jugadores[hexagonos[i].getCasas(j).getNumJugador()].getLadrillo()+1);
                    break;

                case HEXOVEJA:
                    jugadores[hexagonos[i].getCasas(j).getNumJugador()].setLana(jugadores[hexagonos[i].getCasas(j).getNumJugador()].getLana()+1);
                    break;

                case HEXMINERAL:
                    jugadores[hexagonos[i].getCasas(j).getNumJugador()].setPiedra(jugadores[hexagonos[i].getCasas(j).getNumJugador()].getPiedra()+1);
                    break;

                case HEXTRIGO:
                    jugadores[hexagonos[i].getCasas(j).getNumJugador()].setTrigo(jugadores[hexagonos[i].getCasas(j).getNumJugador()].getTrigo()+1);
                    break;

                }
            }
    }

}

void GamePlay::draw()
{
    ventana.clear(sf::Color(96, 159, 253));
    //Dibujar texturas
    ventana.draw(mapa);
    for (int i=0; i<19; i++)
    {
        ventana.draw(hexagonos[i].getSp());
    };
    ventana.draw(casa.getSp());
    ///ventana.draw(camino.getSp());
    ventana.draw(texto);
    for(int i=0; i < 54; i++)
    {
        ventana.draw(espacioCasas[i]);
    }
    ventana.display();

}

void GamePlay::finish()
{
    //se muestran cosas al finalizar el juego
}

