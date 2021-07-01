#include "GamePlay.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const float TAM=0.6;
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

const float caminoCoordX=hexCoordX+(85*TAM);
const float caminoCoordY=hexCoordY+(125*TAM);
GamePlay::GamePlay()
{
    init();
}

void GamePlay::init()
{
    //Constantes para coordenadas


    srand(time(NULL));
    //matriz de Coordenadas de hexagonos
    float vecCoords[19][2]=
    {
        hexCoordX,hexCoordY, hexCoordX+difX,hexCoordY, hexCoordX+(difX*2),hexCoordY,
        hexCoordX-(difX/2),hexCoordY+difY, hexCoordX-(difX/2)+difX,hexCoordY+difY, hexCoordX-(difX/2)+(difX*2),hexCoordY+difY, hexCoordX-(difX/2)+(difX*3),hexCoordY+difY,
        hexCoordX-difX,hexCoordY+(difY*2),  hexCoordX-difX+difX,hexCoordY+(difY*2),  hexCoordX-difX+(difX*2),hexCoordY+(difY*2),  hexCoordX-difX+(difX*3),hexCoordY+(difY*2),  hexCoordX-difX+(difX*4),hexCoordY+(difY*2),
        hexCoordX-(difX/2),hexCoordY+(difY*3), hexCoordX-(difX/2)+difX,hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*2),hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*3),hexCoordY+(difY*3),
        hexCoordX,hexCoordY+(difY*4), hexCoordX+difX,hexCoordY+(difY*4), hexCoordX+(difX*2),hexCoordY+(difY*4)
    };
    //Matriz de coordenadas de espacios para estructuras
    float espacioCoords[54][2]=
    {
        estructCoordX,estructCoordY, estructCoordX+difX,estructCoordY, estructCoordX+(difX*2),estructCoordY,
        estruct2CoordX,estruct2CoordY, estruct2CoordX+difX,estruct2CoordY, estruct2CoordX+(difX*2),estruct2CoordY, estruct2CoordX+(difX*3),estruct2CoordY,
        estructCoordX-(difX*0.5),estructCoordY+difY, estructCoordX+(difX*0.5),estructCoordY+difY, estructCoordX+(difX*1.5),estructCoordY+difY, estructCoordX+(difX*2.5),estructCoordY+difY,
        estruct2CoordX-(difX*0.5),estruct2CoordY+difY, estruct2CoordX+(difX*0.5),estruct2CoordY+difY, estruct2CoordX+(difX*1.5),estruct2CoordY+difY, estruct2CoordX+(difX*2.5),estruct2CoordY+difY, estruct2CoordX+(difX*3.5),estruct2CoordY+difY,
        estructCoordX-difX,estructCoordY+(difY*2), estructCoordX,estructCoordY+(difY*2), estructCoordX+difX,estructCoordY+(difY*2), estructCoordX+(difX*2),estructCoordY+(difY*2), estructCoordX+(difX*3),estructCoordY+(difY*2),
        estruct2CoordX-difX,estruct2CoordY+(difY*2), estruct2CoordX,estruct2CoordY+(difY*2),estruct2CoordX+difX,estruct2CoordY+(difY*2), estruct2CoordX+(difX*2),estruct2CoordY+(difY*2), estruct2CoordX+(difX*3),estruct2CoordY+(difY*2), estruct2CoordX+(difX*4),estruct2CoordY+(difY*2),
        estructCoordX-(difX*1.5),estructCoordY+(difY*3), estructCoordX-(difX*0.5),estructCoordY+(difY*3), estructCoordX+(difX*0.5),estructCoordY+(difY*3), estructCoordX+(difX*1.5),estructCoordY+(difY*3), estructCoordX+(difX*2.5),estructCoordY+(difY*3), estructCoordX+(difX*3.5),estructCoordY+(difY*3),
        estruct2CoordX-(difX*0.5),estruct2CoordY+(difY*3), estruct2CoordX+(difX*0.5),estruct2CoordY+(difY*3), estruct2CoordX+(difX*1.5),estruct2CoordY+(difY*3), estruct2CoordX+(difX*2.5),estruct2CoordY+(difY*3), estruct2CoordX+(difX*3.5),estruct2CoordY+(difY*3),
        estructCoordX-difX,estructCoordY+(difY*4), estructCoordX,estructCoordY+(difY*4), estructCoordX+difX,estructCoordY+(difY*4), estructCoordX+(difX*2),estructCoordY+(difY*4), estructCoordX+(difX*3),estructCoordY+(difY*4),
        estruct2CoordX,estruct2CoordY+(difY*4), estruct2CoordX+difX,estruct2CoordY+(difY*4), estruct2CoordX+(difX*2),estruct2CoordY+(difY*4), estruct2CoordX+(difX*3),estruct2CoordY+(difY*4),
        estructCoordX-(difX*0.5),estructCoordY+(difY*5), estructCoordX+(difX*0.5),estructCoordY+(difY*5), estructCoordX+(difX*1.5),estructCoordY+(difY*5), estructCoordX+(difX*2.5),estructCoordY+(difY*5),
        estruct2CoordX+(difX*0.5),estruct2CoordY+(difY*5), estruct2CoordX+(difX*1.5),estruct2CoordY+(difY*5), estruct2CoordX+(difX*2.5),estruct2CoordY+(difY*5)
    };
    //Matriz de coordenadas para caminos
    float vecCoordCaminos[24][2] =
    {
        caminoCoordX-0.5*difX,caminoCoordY-difY,caminoCoordX+0.5*difX,caminoCoordY-difY,caminoCoordX+1.5*difX,caminoCoordY-difY,
        caminoCoordX-difX,caminoCoordY,caminoCoordX,caminoCoordY,caminoCoordX+difX,caminoCoordY,caminoCoordX+2*difX,caminoCoordY,
        caminoCoordX-1.5*difX,caminoCoordY+difY,caminoCoordX-0.5*difX,caminoCoordY+difY,caminoCoordX+0.5*difX,caminoCoordY+difY,caminoCoordX+1.5*difX,caminoCoordY+difY,caminoCoordX+2.5*difX,caminoCoordY+difY,
        caminoCoordX-difX,caminoCoordY+2*difY,caminoCoordX,caminoCoordY+2*difY,caminoCoordX+difX,caminoCoordY+2*difY,caminoCoordX+2*difX,caminoCoordY+2*difY,caminoCoordX+3*difX,caminoCoordY+2*difY,
        caminoCoordX-0.5*difX,caminoCoordY+3*difY,caminoCoordX+0.5*difX,caminoCoordY+3*difY,caminoCoordX+1.5*difX,caminoCoordY+3*difY,caminoCoordX+2.5*difX,caminoCoordY+3*difY,
        caminoCoordX,caminoCoordY+4*difY,caminoCoordX+difX,caminoCoordY+4*difY,caminoCoordX+2*difX,caminoCoordY+4*difY
    };
    //Cargar ventana
    ventana.create(sf::VideoMode(1280,720),"Catan");


    //Cargar textura para espacio de estructuras


    for(int i=0; i < 54 ; i++ )
    {
        espacioCasas[i].cargarTextura("sprites/recursos/seleccionador.png");
        espacioCasas[i].setScale(TAM*1.8,TAM*1.8);
        espacioCasas[i].setPosition(espacioCoords[i][0],espacioCoords[i][1]);
        espacioCasas[i].setNumero(i);
    }


    //Cargar textura para una casa para jugador 1
    casa.cargarTextura("sprites/estructuras/casaRoja.png");
    casa.setScale(TAM,TAM);
    casa.setPosition(espacioCoords[8][0]*0.96,espacioCoords[8][1]*0.86);
    casa.setNumJugador(2);
    casa.setEspacio(espacioCasas[8]);
    /*
    //Asignar a los hexagonos que colisionen la casa
    sf::FloatRect FCasa=casa.getGlobalBounds();
    sf::FloatRect Fhexagono;
    for(int i=0;i<19;i++){
        Fhexagono=hexagonos[i].getGlobalBounds();
        if (Fhexagono.intersects(FCasa)){
            hexagonos[i].setEstructuras(casa.getNumJugador());
        }
    }*/

    Espacio auxEspacioCasa=casa.getEspacio();

    for(int i=0; i<4;i++){
        int aux;
        //cout<<auxEspacioCasa.getHexagonos()[i]<<endl;
        if(auxEspacioCasa.getHexagonos()[i]!=-1){
            aux=auxEspacioCasa.getHexagonos()[i];
            //cout<<aux<<endl;
            hexagonos[aux].setEstructuras(casa.getNumJugador());
        }
    };


    //verificar cuales hexagonos estan tocando casa
    for(int i=0;i<19;i++){
        for(int j=0;j<3;j++){
            if (hexagonos[i].getEstructuras()[j]!=0){
                cout<<i<<endl;
            }
        }
    }


/*
    //Cargar textura para una casa para jugador 2
    casa2.cargarTextura("sprites/estructuras/casaVerde.png");
    casa2.setScale(TAM*1,TAM*1);
    casa2.setPosition(espacioCoords[9][0]*0.95,espacioCoords[9][1]*0.88);
    casa2.setNumJugador(3);
*/


    //Cargar texturas mapa
    mapa.cargarTextura("sprites/mapas/mapa2.png");
    mapa.setScale(TAM,TAM);
    mapa.setPosition(mapCoordX,mapCoordY);
    ventana.draw(mapa);

    //Cargar textura caminos
    for (int i=0; i<48; i++)
    {
        float multiplo;
        //Dibujar caminos en 45grados
        if(i%2==0)
        {
            caminos[i].cargarTextura("sprites/estructuras/verde28g.png");
            caminos[i].setScale(TAM*0.86,TAM*0.86);
            caminos[i].setPosition(vecCoordCaminos[i/2][0],vecCoordCaminos[i/2][1]);
            ventana.draw(caminos[i]);
        }
        //Dibujar caminos en -45grados
        else
        {
            caminos[i].cargarTextura("sprites/estructuras/caminoVerde-28G.png");
            caminos[i].setScale(TAM*0.86,TAM*0.86);

            if (i==1)
            {
                multiplo=2.5;
            }
            else if(i==7)
            {
                multiplo=3.5;
            }
            else if(i==15)
            {
                multiplo=4.5;
            }
            else
            {
                multiplo=-0.5;
            }

            caminos[i].setPosition(vecCoordCaminos[(i-1)/2][0]+multiplo*difX,vecCoordCaminos[(i-1)/2][1]);
            ventana.draw(caminos[i]);
        }
    }
//Dibujar caminos en verticales
    for(int i=48; i < 74 ; i++ )
    {

        caminos[i].cargarTextura("sprites/estructuras/camino90G.png");
        caminos[i].setScale(TAM*0.86,TAM*0.86);

        int multiplo;
        if(i>=48 && i<52 )
        {
            multiplo=i-48+3;
        }
        else if(i>=53 && i < 58)
        {
            multiplo=i-48+6;
        }
        else if(i>=59 && i < 65)
        {
            multiplo=i-48+10;
        }
        else if(i>=65 && i < 70)
        {
            multiplo=i-48+16;
        }
        else if(i>=70 && i < 74)
        {
            multiplo=i-48+21;
        }
        caminos[i].setPosition(espacioCoords[multiplo][0]+5,espacioCoords[multiplo][1]+5);

        /*  ventana.draw(caminos[i]);*/
    }

    TIPO_HEX tiposHexagonos[19]= {HEXARBOL,HEXTRIGO,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL,HEXMINERAL,HEXARBOL,HEXTRIGO,HEXLADRILLO,HEXTRIGO,HEXOVEJA,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXMINERAL,HEXDESIERTO};

    {
        // asignamos tipo
        bool asignados[19] {};
        int numero;

        for (int i=0; i<19; i++)
        {
            do
            {
                numero=rand()%19;
                if(!asignados[numero])
                {
                    hexagonos[i].setTipo(tiposHexagonos[numero]);
                }
            }
            while(asignados[numero]);
            asignados[numero] = true;
        }
    }

    //Cargar textura hexagonos
    for (int i=0; i<19; i++)
    {
        hexagonos[i].cargarHexagono();
        hexagonos[i].setScale(TAM,TAM);
        hexagonos[i].setPosition(vecCoords[i][0], vecCoords[i][1]);
        ventana.draw(hexagonos[i]);
    }


    {
        ///Asignacion de fichas
        int numeros[18]= {2,3,3,4,4,5,5,6,6,8,8,9,9,10,10,11,11,12};
        bool asignados[18] {};
        Ficha fichas[18];
        int numero;

        for(int i = 0; i < 18 ; i++)
        {
            do
            {
                numero=rand()%18;
                if(!asignados[numero])
                {
                    fichas[i].setNumero(numeros[numero]);
                }

            }
            while(asignados[numero]);
            asignados[numero] = true;
        }



        int cont=0;
        for(int i = 0; i < 19; i++)
        {
            if(hexagonos[i].getTipo() != HEXDESIERTO)
            {
                hexagonos[i].setFicha(fichas[cont]);
                hexagonos[i].cargarFicha();
                hexagonos[i].fichaSetPosition(TAM,TAM);
                hexagonos[i].fichaSetScale(TAM,TAM);
                cont++;
            }
        }
    }


    /*fuente.loadFromFile("fuentes/LEMONMILK-Bold.otf");
    texto.setFont(fuente);
    texto.setString("12");
    texto.setColor(sf::Color(0,0,0));
    texto.setPosition(mapCoordX+(662*TAM), mapCoordY+(132*TAM));*/

    //se cargan los objetos, texturas y posiciones.

    //Se cargan los dados
    for(int i = 0; i < 2; i++)
    {
        dados[i].tirarDado();
        dados[i].setScale(TAM*0.6,TAM*0.7);
        dados[i].setPosition(700+(i*120),600);
    }


    for(int i=0; i < 54; i++)
    {
        ventana.draw(espacioCasas[i]);
    }

    for(int i = 0; i < 19; i++)
    {
        if(hexagonos[i].getTipo() != HEXDESIERTO)
            ventana.draw(hexagonos[i].getFicha());
    }

    ventana.draw(dados[0]);
    ventana.draw(dados[1]);
    cargarEspacios();
    cout<<endl;
    cargarCaminos();
    ventana.setFramerateLimit(60);


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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {///al presionar enter se cambia los dados y se realizan los calculos. corregir porque si se queda uno presionando enter toma el valor mas de una vez.
        dados[0].tirarDado();
        dados[1].tirarDado();

        Ficha auxFicha;
        TIPO_HEX aux;

        for(int i = 0; i < 19; i++)
        {
            auxFicha = hexagonos[i].getFicha();///recuperamos la ficha del hexagono
            if(auxFicha.getNumero() == dados[0].getNumero() + dados[1].getNumero()) ///vemos el numero que tiene


                for(int j = 0; j < 3; j++)
                {
                    if(hexagonos[i].getEstructuras()[j] > 0)    ///Verificamos que tenga alguna estructura
                        jugadores[hexagonos[i].getEstructuras()[j]-1].addRecurso(hexagonos[i].getNivel()[j], hexagonos[i].getTipo());

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
        ventana.draw(hexagonos[i]);
    };
    //ventana.draw(texto);


    for (int i=0; i<74; i++)
    {
        ventana.draw(caminos[i]);
    };

    for(int i=0; i < 54; i++)
    {
        ventana.draw(espacioCasas[i]);
    }
    for(int i = 0; i < 19; i++)
    {
        if(hexagonos[i].getTipo() != HEXDESIERTO)
            ventana.draw(hexagonos[i].getFicha());
    }
    ventana.draw(casa);
    ventana.draw(casa2);
    ventana.draw(dados[0]);
    ventana.draw(dados[1]);

    ventana.display();



}

void GamePlay::finish()
{
    //se muestran cosas al finalizar el juego
}

void GamePlay::cargarEspacios()
{
    sf::FloatRect _espacio;
    int *v;
    int pos;

    sf::FloatRect _hexagono;
    for(int i =0; i < 54; i++)
    {
        v = new int[4] {-1,-1,-1,-1};
        pos = 0;
        _espacio = espacioCasas[i].getGlobalBounds();
        for(int j = 0; j < 19 ; j++)
        {
            _hexagono = hexagonos[j].getGlobalBounds();
            if(_espacio.intersects(_hexagono))
            {
                v[pos] = j;
                pos++;
            }

        }
        espacioCasas[i].setHexagonos(v);
        delete v;
    }

    for(int i = 0; i <54 ; i ++)
    {
        cout << "Punto "<<i+1<<": ";
        for(int j = 0; j < 4; j++)
        {
            if(espacioCasas[i].getHexagonos()[j]!= -1)
                cout<<espacioCasas[i].getHexagonos()[j]<<", ";
        }
        cout<<endl;
    }
}
void GamePlay::cargarCaminos()
{
    sf::FloatRect _espacio, _hexagono;
    int *v;
    int pos;

    for(int i =0; i < 74; i++)
    {
        v = new int[4] {-1,-1,-1,-1};
        pos = 0;
        _espacio = caminos[i].getGlobalBounds();
        for(int j = 0; j < 19 ; j++)
        {
            _hexagono = hexagonos[j].getGlobalBounds();
            if(_espacio.intersects(_hexagono))
            {
                v[pos] = j;
                pos++;
            }

        }
        caminos[i].setHexagonos(v);
        delete v;
    }

    for(int i = 0; i <74 ; i ++)
    {
        cout << "Camino "<<i+1<<": ";
        for(int j = 0; j < 4; j++)
        {
            if(caminos[i].getHexagonos()[j]!= -1)
                cout<<caminos[i].getHexagonos()[j]<<", ";
        }
        cout<<endl;
    }


}
