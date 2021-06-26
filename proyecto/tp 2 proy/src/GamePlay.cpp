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

    const float caminoCoordX=hexCoordX+60;
    const float caminoCoordY=hexCoordY+85;

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



    float vecCoordCaminos[24][2] ={
    caminoCoordX-0.5*difX,caminoCoordY-difY,caminoCoordX+0.5*difX,caminoCoordY-difY,caminoCoordX+1.5*difX,caminoCoordY-difY,
    caminoCoordX-difX,caminoCoordY,caminoCoordX,caminoCoordY,caminoCoordX+difX,caminoCoordY,caminoCoordX+2*difX,caminoCoordY,
    caminoCoordX-1.5*difX,caminoCoordY+difY,caminoCoordX-0.5*difX,caminoCoordY+difY,caminoCoordX+0.5*difX,caminoCoordY+difY,caminoCoordX+1.5*difX,caminoCoordY+difY,caminoCoordX+2.5*difX,caminoCoordY+difY,
    caminoCoordX-difX,caminoCoordY+2*difY,caminoCoordX,caminoCoordY+2*difY,caminoCoordX+difX,caminoCoordY+2*difY,caminoCoordX+2*difX,caminoCoordY+2*difY,caminoCoordX+3*difX,caminoCoordY+2*difY,
    caminoCoordX-0.5*difX,caminoCoordY+3*difY,caminoCoordX+0.5*difX,caminoCoordY+3*difY,caminoCoordX+1.5*difX,caminoCoordY+3*difY,caminoCoordX+2.5*difX,caminoCoordY+3*difY,
    caminoCoordX,caminoCoordY+4*difY,caminoCoordX+difX,caminoCoordY+4*difY,caminoCoordX+2*difX,caminoCoordY+4*difY
    };

    //Cargar textura caminos
    for (int i=0; i<48; i++){
    float multiplo;
        //Dibujar caminos en 45grados
        if(i%2==0){
            caminos[i].getTex().loadFromFile("sprites/estructuras/verde28g.png");
            caminos[i].getSp().setTexture(caminos[i].getTex());
            caminos[i].getSp().setScale(TAM*0.86,TAM*0.86);
            caminos[i].getSp().setPosition(vecCoordCaminos[i/2][0],vecCoordCaminos[i/2][1]);
            ventana.draw(caminos[i].getSp());
        }
        //Dibujar caminos en -45grados
        else{
            caminos[i].getTex().loadFromFile("sprites/estructuras/caminoVerde-28G.png");
            caminos[i].getSp().setTexture(caminos[i].getTex());
            caminos[i].getSp().setScale(TAM*0.86,TAM*0.86);

            if (i==1){multiplo=2.5;}
            else if(i==7){multiplo=3.5;}
            else if(i==15){multiplo=4.5;}
            else {multiplo=-0.5;}

            caminos[i].getSp().setPosition(vecCoordCaminos[(i-1)/2][0]+multiplo*difX,vecCoordCaminos[(i-1)/2][1]);
            ventana.draw(caminos[i].getSp());
        }
    }
//Dibujar caminos en verticales
    for(int i=48; i < 74 ; i++ ){

        caminos[i].getTex().loadFromFile("sprites/estructuras/camino90G.png");
        caminos[i].getSp().setTexture(caminos[i].getTex());
        caminos[i].getSp().setScale(TAM*0.86,TAM*0.86);

        int multiplo;
        if(i>=48 && i<52 ){
            multiplo=i-48+3;
        }
        else if(i>=53 && i < 58){
            multiplo=i-48+6;
        }
        else if(i>=59 && i < 65){
            multiplo=i-48+10;
        }
        else if(i>=65 && i < 70){
            multiplo=i-48+16;
        }
        else if(i>=70 && i < 74){
            multiplo=i-48+21;
        }
        caminos[i].getSp().setPosition(espacioCoords[multiplo][0]+5,espacioCoords[multiplo][1]+5);

        ventana.draw(caminos[i].getSp());
    }

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

    for (int i=0; i<74; i++)
    {
        ventana.draw(caminos[i].getSp());
    };
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

