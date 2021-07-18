#include "GamePlay.h"
#include <iostream>
#include <string>
#include <windows.h>
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

    ventana.setFramerateLimit(60);
    ventana.create(sf::VideoMode(1280,720),"Catan");


    cargarVecEspacios();
    cargarHexagonos();
    cargarVecCaminos();
    cargarCaminos();
    cargarEspacios();
    cargarBotones();





    //Matriz de coordenadas de espacios para estructuras

    //Matriz de coordenadas para caminos

    //Cargar ventana



    //Cargar textura para espacio de estructuras





    //Cargar texturas mapa
    mapa.cargarTextura("sprites/mapas/mapa2.png");
    mapa.setScale(TAM,TAM);
    mapa.setPosition(mapCoordX,mapCoordY);
    ventana.draw(mapa);

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

    fuente.loadFromFile("fuentes/roboto/Roboto-Black.ttf");

    TIPO_HEX tiposCartas[5]= {HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL};

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cartas[j][i].setTipo(tiposCartas[i]);
            cartas[j][i].cargarTextura();
            cartas[j][i].setPosition(800+(60*i),300+(100*j));
            cartas[j][i].setScale(TAM,TAM);
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            textCartasPuntos[i][j].setFont(fuente);
            textCartasPuntos[i][j].setColor(sf::Color(40,90,30));
            textCartasPuntos[i][j].setScale(0.5,0.5);
            textCartasPuntos[i][j].setPosition(810+(60*j),350+(100*i));
            textCartasPuntos[i][j].setString(to_string(0));
            ventana.draw(textCartasPuntos[i][j]);
        }
    }

    for(int i = 0; i< 72; i++)
    {
        textNumCaminos[i].setFont(fuente);
        textNumCaminos[i].setColor(sf::Color::White);
        textNumCaminos[i].setScale(0.5,0.5);
        textNumCaminos[i].setPosition(espacioCaminos[i].getPosition());
        textNumCaminos[i].setString(to_string(i));
        ventana.draw(textNumCaminos[i]);
    }

    for(int i=0; i < 5; i++)
        for(int j=0; j < 2; j++)
            ventana.draw(cartas[j][i]);

    ventana.display();
    estado = TIRAR_DADO;
    turno = 1;

    for(int i = 0; i < 72; i ++)
    {
        espacioCaminos[i].setMostrar(false);
    }

    for(int i = 0; i < 54; i++)
    {
        espacioCasas[i].setMostrar(false);
    }
    prueba();
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
    switch(estado)
    {
    case TIRAR_DADO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))

        {
            if(!pressA)
            {
                pressA=true;
                ///al presionar enter se cambia los dados y se realizan los calculos. corregir porque si se queda uno presionando enter toma el valor mas de una vez.
                dados[0].tirarDado();
                dados[1].tirarDado();

                texto.setString(to_string(dados[1].getNumero()+dados[0].getNumero()));
                Ficha auxFicha;
                TIPO_HEX aux;


                for(int i = 0; i < 19; i++)
                {
                    auxFicha = hexagonos[i].getFicha();///recuperamos la ficha del hexagono
                    if(auxFicha.getNumero() == dados[0].getNumero() + dados[1].getNumero()) ///vemos el numero que tiene
                    {
                        hexagonos[i].variarFicha();
                        for(int j = 0; j < 3; j++)
                        {
                            if(hexagonos[i].getEstructuras()[j] > 0)    ///Verificamos que tenga alguna estructura
                                jugadores[hexagonos[i].getEstructuras()[j]-1].addRecurso(hexagonos[i].getNivel()[j], hexagonos[i].getTipo());
                        }
                    }
                }
                for(int j=0; j < 2; j++)
                {
                    textCartasPuntos[j][0].setString(to_string(jugadores[j].getMadera()));
                    textCartasPuntos[j][1].setString(to_string(jugadores[j].getLadrillo()));
                    textCartasPuntos[j][2].setString(to_string(jugadores[j].getLana()));
                    textCartasPuntos[j][3].setString(to_string(jugadores[j].getTrigo()));
                    textCartasPuntos[j][4].setString(to_string(jugadores[j].getPiedra()));
                }
                /*for(int i = 0; i < 3; i ++)
                cout << hexagonos[2].getEstructuras()[i]<<endl;
                cout <<endl;*/
            }
        }
        else
        {
            if(pressA)
            {
                //Sleep(5);
                for(int i= 0; i < 19; i++)
                {
                    hexagonos[i].cargarFicha();
                }
                estado = SELECCIONAR_ACCION;
                pressA = false;
                cout << "Se pasó a seleccionar accion"<<endl;
            }
        }

        break;

    /*case CONSTRUCCION: cout << "Ahora te toca construir";
                            estado = SELECCION;
                            break;*/

    case SELECCIONAR_ACCION:///DEBE PRESIONAR EL BOTON CONSTRUIR O FINALIZAR

        bFinalizar.setMostrar(true);
        bConstruir.setMostrar(true);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para boton construir
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bConstruir = bConstruir.getGlobalBounds();///tomando el floatRect del Boton

            if(_bConstruir.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {
                if(!pressA)
                {
                    pressA=true;
                    cout << "Se presiono boton construir"<<endl;
                }
            }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bConstruir = bConstruir.getGlobalBounds();///tomando el floatRect del Boton

            if(_bConstruir.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {


                if(pressA)
                {

                    estado = CONSTRUCCION;
                    pressA =false;
                }
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para boton FINALIZAR
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bFinalizar = bFinalizar.getGlobalBounds();///tomando el floatRect del Boton

            if(_bFinalizar.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {
                if(!pressA)
                {
                    pressA=true;
                    cout <<"se presiono finalizar"<<endl;
                    if(turno == 1)
                        turno = 2;
                    else if(turno == 2)
                        turno = 1;
                }
            }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bFinalizar = bFinalizar.getGlobalBounds();///tomando el floatRect del Boton

            if(_bFinalizar.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {


                if(pressA)
                {
                    cout << "se FINALIZO"<<endl;
                    cout << "se debe TIRAR DADO"<<endl;
                    estado = TIRAR_DADO;
                    pressA=false;
                }
            }
        }
        break;

    case CONSTRUCCION:///DEBE SELECCIONAR QUE CONSTRUIR(CASA, EDIFICIO O CAMINO)

        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bCasa.setMostrar(true);
        bCamino.setMostrar(true);
        bEdificio.setMostrar(true);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para boton CASA
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bCasa = bCasa.getGlobalBounds();///tomando el floatRect del Boton

            if(_bCasa.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {
                if(!pressA)
                {
                    pressA=true;
                    cout << "Se eligio construir CASA"<<endl;

                    for(int i = 0; i < 72; i ++)
                    {
                        if(caminos[i].getNumJugador() == turno)
                        {

                            for(int j=0; j < 2; j++)
                            {
                                if(espacioCasas[espacioCaminos[i].getEspacioCasas()[j]].isDisponible())
                                    espacioCasas[espacioCaminos[i].getEspacioCasas()[j]].setMostrar(true);
                            }

                        }
                    }

                }


            }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bCasa = bCasa.getGlobalBounds();///tomando el floatRect del Boton

            if(_bCasa.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {
                if(pressA)
                {
                    estado = COLOCACION_CASA;
                    pressA=false;
                }
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para boton EDIFICIO
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bEdificio = bEdificio.getGlobalBounds();///tomando el floatRect del Boton

            if(_bEdificio.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
                if(!pressA)
                {
                    pressA=true;
                    cout << "Se eligio construir Edificio"<<endl;
                    for(int i=0; i < 54; i ++)
                    {
                        if(espacioCasas[i].isOcupado() && casas[i].getNumJugador() == turno)
                        {
                            espacioCasas[i].setMostrar(true);
                        }
                    }
                }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bEdificio = bEdificio.getGlobalBounds();///tomando el floatRect del Boton

            if(_bEdificio.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {

                if(pressA)
                {
                    estado = COLOCACION_EDIFICIO;
                    pressA=false;
                }
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para boton CAMINO
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bCamino = bCamino.getGlobalBounds();///tomando el floatRect del Boton

            if(_bCamino.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {

                if(!pressA)
                {
                    pressA=true;
                    cout << "Se eligio construir CAMINO"<<endl;

                    for(int i = 0; i < 54; i ++)
                    {
                        if(espacioCasas[i].isOcupado() && casas[i].getNumJugador() == turno)
                            for(int j = 0; j < 4; j++)
                            {
                                if(espacioCasas[i].getEspacioCaminos()[j] != -1 && espacioCaminos[espacioCasas[i].getEspacioCaminos()[j]].isDisponible())
                                {
                                    espacioCaminos[espacioCasas[i].getEspacioCaminos()[j]].setMostrar(true);
                                }
                            }
                    }

                    for(int i =0; i < 72; i++)
                    {
                        if(espacioCaminos[i].isOcupado() && caminos[i].getNumJugador() == turno)
                            for(int j = 0; j < 4; j++)
                            {
                                if(espacioCaminos[i].getEspacioCaminos()[j] != -1 && espacioCaminos[espacioCaminos[i].getEspacioCaminos()[j]].isDisponible())
                                {
                                    espacioCaminos[espacioCaminos[i].getEspacioCaminos()[j]].setMostrar(true);
                                }
                            }

                    }

                    for(int i =0; i < 72; i++)
                    {
                        if(espacioCaminos[i].isOcupado() && caminos[i].getNumJugador() == turno)
                            for(int j = 0; j < 2; j++)
                                if(casas[espacioCaminos[i].getEspacioCasas()[j]].getNumJugador() != turno && espacioCasas[espacioCaminos[i].getEspacioCasas()[j]].isOcupado())
                                {
                                    for(int k = 0; k < 4; k++)
                                        if(espacioCasas[espacioCaminos[i].getEspacioCasas()[j]].getEspacioCaminos()[k] != -1)
                                        espacioCaminos[espacioCasas[espacioCaminos[i].getEspacioCasas()[j]].getEspacioCaminos()[k]].setMostrar(false);
                                }
                    }

                }
            }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bCamino = bCamino.getGlobalBounds();///tomando el floatRect del Boton

            if(_bCamino.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {

                if(pressA)
                {
                    estado = COLOCACION_CAMINO;
                    pressA=false;
                }
            }
        }
        break;

    case COLOCACION_CAMINO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar el CAMINO que quiere
        {

            if(!pressA)
            {
                pressA=true;
                cout << "Se coloco estructura"<<endl;


                ///código limpieza, pone los espacios mostrados en false luego de elegir
                for(int i =0; i < 72; i++)
                {
                    espacioCaminos[i].setMostrar(false);
                }
            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                pressA=false;
            }
        }
        break;

    case COLOCACION_CASA:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar la CASA que quiere
        {

            if(!pressA)
            {
                pressA=true;
                cout << "Se coloco estructura"<<endl;


                ///código limpieza, pone los espacios mostrados en false luego de elegir
                for(int i =0; i < 54; i++)
                {
                    espacioCasas[i].setMostrar(false);
                }
            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                pressA=false;
            }
        }
        break;

    case COLOCACION_EDIFICIO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar el EDIFICIO que quiere
        {

            if(!pressA)
            {
                pressA=true;
                cout << "Se coloco estructura"<<endl;


                 ///código limpieza, pone los espacios mostrados en false luego de elegir
                for(int i =0; i < 54; i++)
                {
                    espacioCasas[i].setMostrar(false);
                }
            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                pressA=false;
            }
        }
        break;

    }///FIN SWITCH
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

    for(int i=0; i < 72; i++)
    {
        if(caminos[i].getMostrar())
            ventana.draw(caminos[i]);
    }

    for (int i=0; i<72; i++)
    {
        if(espacioCaminos[i].getMostrar())
            ventana.draw(espacioCaminos[i]);
    };


    for(int i = 0; i < 19; i++)
    {
        if(hexagonos[i].getTipo() != HEXDESIERTO)
            ventana.draw(hexagonos[i].getFicha());
    }

    for(int i=0; i < 54; i++)
    {
        if(casas[i].getMostrar())
            ventana.draw(casas[i]);
    }
    for(int i=0; i < 54; i++)
    {
        if(espacioCasas[i].getMostrar())
            ventana.draw(espacioCasas[i]);
    }

    ventana.draw(dados[0]);
    ventana.draw(dados[1]);

    for(int i=0; i < 5; i++)
        for(int j=0; j < 2; j++)
            ventana.draw(cartas[j][i]);

    for(int i=0; i < 5; i++)
        for(int j=0; j < 2; j++)
            ventana.draw(textCartasPuntos[j][i]);

    for(int i = 0; i < 72; i++)
    {
        ventana.draw(textNumCaminos[i]);
    }
    if(bConstruir.getMostrar())
        ventana.draw(bConstruir);
    if(bFinalizar.getMostrar())
        ventana.draw(bFinalizar);
    if(bCasa.getMostrar())
        ventana.draw(bCasa);
    if(bEdificio.getMostrar())
        ventana.draw(bEdificio);
    if(bCamino.getMostrar())
        ventana.draw(bCamino);


    ventana.display();





}

void GamePlay::finish()
{
    //se muestran cosas al finalizar el juego
}

void GamePlay::cargarEspacios()
{
    sf::FloatRect _espacio;
    sf::FloatRect _hexagono;
    sf::FloatRect _camino;
    int *v;
    int pos;

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

    for(int i = 0; i < 54; i++)
    {
        v = new int[4] {-1,-1,-1,-1};
        pos = 0;
        _espacio = espacioCasas[i].getGlobalBounds();
        for (int j = 0; j < 72; j ++)
        {
            _camino = espacioCaminos[j].getGlobalBounds();
            if(_espacio.intersects(_camino))
            {
                v[pos] = j;
                pos++;
            }
        }
        espacioCasas[i].setEspacioCaminos(v);
        delete v;
    }

    for(int i = 0; i <54 ; i ++)
    {
        cout << "Punto(C) "<<i+1<<": ";
        for(int j = 0; j < 4; j++)
        {
            if(espacioCasas[i].getEspacioCaminos()[j]!= -1)
                cout<<espacioCasas[i].getEspacioCaminos()[j]<<", ";
        }
        cout<<endl;
    }

}
void GamePlay::cargarCaminos()///
{
    sf::FloatRect _espacio, _hexagono, _camino, _espacioCasa;
    int *v;
    int pos;

    for(int i =0; i < 72; i++)
    {
        v = new int[4] {-1,-1,-1,-1};
        pos = 0;
        _espacio = espacioCaminos[i].getGlobalBounds();
        for(int j = 0; j < 19 ; j++)
        {
            _hexagono = hexagonos[j].getGlobalBounds();
            if(_espacio.intersects(_hexagono))
            {
                v[pos] = j;
                pos++;
            }

        }
        espacioCaminos[i].setHexagonos(v);
        delete v;
    }

    for(int i = 0; i <72 ; i ++)
    {
        cout << "Camino "<<i<<": ";
        for(int j = 0; j < 4; j++)
        {
            if(espacioCaminos[i].getHexagonos()[j]!= -1)
                cout<<espacioCaminos[i].getHexagonos()[j]<<", ";
        }
        cout<<endl;
    }

    for(int i = 0; i < 72; i++)
    {
        v = new int[4] {-1,-1,-1,-1};
        pos = 0;
        _espacio = espacioCaminos[i].getGlobalBounds();
        for(int j = 0; j < 72; j++)
        {
            if(j != i)
            {
                _camino = espacioCaminos[j].getGlobalBounds();
                if(_espacio.intersects(_camino))
                {
                    v[pos] = j;
                    pos++;
                }
            }
        }
        espacioCaminos[i].setEspacioCaminos(v);
        delete v;
    }

    for(int i = 0; i <72 ; i ++)
    {
        cout << "Camino(s) "<<i<<": ";
        for(int j = 0; j < 4; j++)
        {
            if(espacioCaminos[i].getEspacioCaminos()[j]!= -1)
                cout<<espacioCaminos[i].getEspacioCaminos()[j]<<", ";
        }
        cout<<endl;
    }

    for(int i = 0; i < 72; i++)
    {

        v = new int[2] {-1,-1};
        pos = 0;
        _camino = espacioCaminos[i].getGlobalBounds();
        for(int j = 0; j < 54; j++)
        {

            {
                _espacioCasa = espacioCasas[j].getGlobalBounds();
                if(_camino.intersects(_espacioCasa))
                {
                    v[pos] = j;
                    pos++;
                }
            }
        }
        espacioCaminos[i].setEspacioCasas(v);
        delete v;
    }

    for(int i = 0; i <72 ; i ++)
    {
        cout << "Camino(EspacioCasa q toca) "<<i<<": ";
        for(int j = 0; j < 2; j++)
        {
            if(espacioCaminos[i].getEspacioCasas()[j]!= -1)
                cout<<espacioCaminos[i].getEspacioCasas()[j]<<", ";
        }
        cout<<endl;
    }
}

void GamePlay::cargarHexagonos()///Carga el hexágono y les asigna el tipo
{

    float vecCoords[19][2]=
    {
        hexCoordX,hexCoordY, hexCoordX+difX,hexCoordY, hexCoordX+(difX*2),hexCoordY,
        hexCoordX-(difX/2),hexCoordY+difY, hexCoordX-(difX/2)+difX,hexCoordY+difY, hexCoordX-(difX/2)+(difX*2),hexCoordY+difY, hexCoordX-(difX/2)+(difX*3),hexCoordY+difY,
        hexCoordX-difX,hexCoordY+(difY*2),  hexCoordX-difX+difX,hexCoordY+(difY*2),  hexCoordX-difX+(difX*2),hexCoordY+(difY*2),  hexCoordX-difX+(difX*3),hexCoordY+(difY*2),  hexCoordX-difX+(difX*4),hexCoordY+(difY*2),
        hexCoordX-(difX/2),hexCoordY+(difY*3), hexCoordX-(difX/2)+difX,hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*2),hexCoordY+(difY*3), hexCoordX-(difX/2)+(difX*3),hexCoordY+(difY*3),
        hexCoordX,hexCoordY+(difY*4), hexCoordX+difX,hexCoordY+(difY*4), hexCoordX+(difX*2),hexCoordY+(difY*4)
    };

    TIPO_HEX tiposHexagonos[19]= {HEXARBOL,HEXTRIGO,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL,HEXMINERAL,HEXARBOL,HEXTRIGO,HEXLADRILLO,HEXTRIGO,HEXOVEJA,HEXOVEJA,HEXARBOL,HEXLADRILLO,HEXMINERAL,HEXDESIERTO};


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
        bool asignadosFichas[18] {};
        Ficha fichas[18];

        for(int i = 0; i < 18 ; i++)
        {
            do
            {
                numero=rand()%18;
                if(!asignadosFichas[numero])
                {
                    fichas[i].setNumero(numeros[numero]);
                }

            }
            while(asignadosFichas[numero]);
            asignadosFichas[numero] = true;
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
}

void GamePlay::cargarVecEspacios()
{
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

    for(int i=0; i < 54 ; i++ )
    {
        espacioCasas[i].cargarTextura("sprites/recursos/seleccionador.png");
        espacioCasas[i].setScale(TAM*1.8,TAM*1.8);
        espacioCasas[i].setPosition(espacioCoords[i][0],espacioCoords[i][1]);
        espacioCasas[i].setNumero(i);
    }
}

void GamePlay::cargarVecCaminos()
{
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

    float vecCoordCaminos[24][2] =
    {
        caminoCoordX-0.5*difX,caminoCoordY-difY,caminoCoordX+0.5*difX,caminoCoordY-difY,caminoCoordX+1.5*difX,caminoCoordY-difY,
        caminoCoordX-difX,caminoCoordY,caminoCoordX,caminoCoordY,caminoCoordX+difX,caminoCoordY,caminoCoordX+2*difX,caminoCoordY,
        caminoCoordX-1.5*difX,caminoCoordY+difY,caminoCoordX-0.5*difX,caminoCoordY+difY,caminoCoordX+0.5*difX,caminoCoordY+difY,caminoCoordX+1.5*difX,caminoCoordY+difY,caminoCoordX+2.5*difX,caminoCoordY+difY,
        caminoCoordX-difX,caminoCoordY+2*difY,caminoCoordX,caminoCoordY+2*difY,caminoCoordX+difX,caminoCoordY+2*difY,caminoCoordX+2*difX,caminoCoordY+2*difY,caminoCoordX+3*difX,caminoCoordY+2*difY,
        caminoCoordX-0.5*difX,caminoCoordY+3*difY,caminoCoordX+0.5*difX,caminoCoordY+3*difY,caminoCoordX+1.5*difX,caminoCoordY+3*difY,caminoCoordX+2.5*difX,caminoCoordY+3*difY,
        caminoCoordX,caminoCoordY+4*difY,caminoCoordX+difX,caminoCoordY+4*difY,caminoCoordX+2*difX,caminoCoordY+4*difY
    };

    for (int i=0; i<48; i++)
    {
        float multiplo;
        //Dibujar caminos en 45grados
        if(i%2==0)
        {
            espacioCaminos[i].cargarTextura("sprites/estructuras/camino28g.png");
            espacioCaminos[i].setScale(TAM*0.86,TAM*0.86);
            espacioCaminos[i].setPosition(vecCoordCaminos[i/2][0],vecCoordCaminos[i/2][1]);
        }
        //Dibujar caminos en -45grados
        else
        {
            espacioCaminos[i].cargarTextura("sprites/estructuras/camino-28G.png");
            espacioCaminos[i].setScale(TAM*0.86,TAM*0.86);

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

            espacioCaminos[i].setPosition(vecCoordCaminos[(i-1)/2][0]+multiplo*difX,vecCoordCaminos[(i-1)/2][1]);
        }
    }
//Dibujar caminos en verticales
    for(int i=48; i < 72 ; i++ )
    {

        espacioCaminos[i].cargarTextura("sprites/estructuras/camino90G.png");
        espacioCaminos[i].setScale(TAM*0.86,TAM*0.86);

        int multiplo;
        if(i>=48 && i<52 )
        {
            multiplo=i-48+3;
        }
        else if(i>=52 && i < 57)
        {
            multiplo=i-48+7;
        }
        else if(i>=57 && i < 63)
        {
            multiplo=i-48+12;
        }
        else if(i>=63 && i < 68)
        {
            multiplo=i-48+18;
        }
        else if(i>=68 && i < 72)
        {
            multiplo=i-48+23;
        }
        espacioCaminos[i].setPosition(espacioCoords[multiplo][0]+5,espacioCoords[multiplo][1]+11);

        /*  ventana.draw(caminos[i]);*/
    }

    for(int i = 0; i < 72; i ++)
        espacioCaminos[i].setNumero(i);
}

void GamePlay::cargarBotones()
{
    bConstruir.cargarTextura("sprites/recursos/botonConstruir.png");
    bConstruir.setScale(TAM*0.7,TAM*0.7);
    bConstruir.setPosition(50,600);

    bFinalizar.cargarTextura("sprites/recursos/botonFinalizar.png");
    bFinalizar.setScale(TAM*0.7,TAM*0.7);
    bFinalizar.setPosition(200,600);

    bCasa.cargarTextura("sprites/recursos/botonCasa.png");
    bCasa.setScale(TAM*0.5,TAM*0.5);
    bCasa.setPosition(30,650);

    bEdificio.cargarTextura("sprites/recursos/botonEdificio.png");
    bEdificio.setScale(TAM*0.5,TAM*0.5);
    bEdificio.setPosition(140,650);

    bCamino.cargarTextura("sprites/recursos/botonCamino.png");
    bCamino.setScale(TAM*0.5,TAM*0.5);
    bCamino.setPosition(250,650);

    //bCamino.setMostrar(false);
}

void GamePlay::prueba()
{

    //Cargar textura para una casa para jugador 2
    casas[9].setNumJugador(1);
    casas[9].cargarTextura();
    casas[9].setEspacio(espacioCasas[9]);
    espacioCasas[9].setOcupado(true);

    for(int i =0; i <4; i++)///coloca la disponibilidad de sus vecinos en false
    {
        if(espacioCasas[9].getEspacioCaminos()[i] != -1)
            for(int j = 0; j < 2; j++)
                espacioCasas[espacioCaminos[espacioCasas[9].getEspacioCaminos()[i]].getEspacioCasas()[j]].setDisponible(false);
    }

    for(int i=0; i< 3; i++)///avisa a los hexagonos que tocan el espacio que hay una nueva casa
        if(espacioCasas[9].getHexagonos()[i] != -1)
        {
            hexagonos[espacioCasas[9].getHexagonos()[i]].setEstructuras(1);
        }

    casas[18].setNumJugador(2);
    casas[18].cargarTextura();
    casas[18].setEspacio(espacioCasas[18]);
    espacioCasas[18].setOcupado(true);

    for(int i =0; i <4; i++)
    {
        if(espacioCasas[18].getEspacioCaminos()[i] != -1)
            for(int j = 0; j < 2; j++)
                espacioCasas[espacioCaminos[espacioCasas[18].getEspacioCaminos()[i]].getEspacioCasas()[j]].setDisponible(false);
    }

    for(int i=0; i< 3; i++)
        if(espacioCasas[18].getHexagonos()[i] != -1)
        {
            hexagonos[espacioCasas[18].getHexagonos()[i]].setEstructuras(2);
        }
    casas[8].setNumJugador(2);
    casas[8].cargarTextura();
    casas[8].setEspacio(espacioCasas[8]);
    espacioCasas[8].setOcupado(true);


    for(int i =0; i <4; i++)
    {
        if(espacioCasas[8].getEspacioCaminos()[i] != -1)
            for(int j = 0; j < 2; j++)
                espacioCasas[espacioCaminos[espacioCasas[8].getEspacioCaminos()[i]].getEspacioCasas()[j]].setDisponible(false);
    }

    for(int i=0; i< 3; i++)
        if(espacioCasas[8].getHexagonos()[i] != -1)
        {
            hexagonos[espacioCasas[8].getHexagonos()[i]].setEstructuras(2);
        }

    caminos[50].setEspacio(espacioCaminos[50]);
    caminos[50].setNumJugador(1);
    caminos[50].cargarTextura();
    espacioCaminos[50].setOcupado(true);

    caminos[11].setEspacio(espacioCaminos[11]);
    caminos[11].setNumJugador(1);
    caminos[11].cargarTextura();
    espacioCaminos[11].setOcupado(true);

    caminos[10].setEspacio(espacioCaminos[10]);
    caminos[10].setNumJugador(1);
    caminos[10].cargarTextura();
    espacioCaminos[10].setOcupado(true);

    caminos[5].setEspacio(espacioCaminos[5]);
    caminos[5].setNumJugador(1);
    caminos[5].cargarTextura();
    espacioCaminos[5].setOcupado(true);

    caminos[18].setEspacio(espacioCaminos[18]);
    caminos[18].setNumJugador(2);
    caminos[18].cargarTextura();
    espacioCaminos[18].setOcupado(true);

    caminos[19].setEspacio(espacioCaminos[19]);
    caminos[19].setNumJugador(2);
    caminos[19].cargarTextura();
    espacioCaminos[19].setOcupado(true);

    caminos[59].setEspacio(espacioCaminos[59]);
    caminos[59].setNumJugador(2);
    caminos[59].cargarTextura();
    espacioCaminos[59].setOcupado(true);
}
