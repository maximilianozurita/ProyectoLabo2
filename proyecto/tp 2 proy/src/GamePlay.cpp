#include "GamePlay.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <SFML/Graphics.hpp>



using namespace std;

const float TAM=0.6;
const float mapCoordX=50;
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

    //ventana.setFramerateLimit(120);
    ventana.create(sf::VideoMode(1280,720),"Colonos de Gonzales Cat�n");
    fuente.loadFromFile("fuentes/roboto/Roboto-Bold.ttf");
    textCargando.setFont(fuente);
    textCargando.setPosition(20,300);
    textCargando.setString("CARGUE SU NOMBRE POR CONSOLA");
    textCargando.setColor(sf::Color::Black);
    textCargando.setCharacterSize(72);
    ventana.clear(sf::Color::White);
    ventana.draw(textCargando);
    ventana.display();
    srand(time(NULL));
    fuenteMensaje.loadFromFile("fuentes/janda_manatee/JandaManateeSolid.ttf");

    //--
    cargarVecEspacios();
    cargarHexagonos();
    cargarVecCaminos();
    cargarCaminos();
    cargarEspacios();
    cargarBotones();

    //Cargar texturas mapa
    mapa.cargarTextura("sprites/mapas/mapa2.png");
    mapa.setScale(TAM,TAM);
    mapa.setPosition(mapCoordX,mapCoordY);




    //Cargar textura dado
    for(int i = 0; i < 2; i++)
    {
        dados[i].tirarDado();
        dados[i].setScale(TAM*0.6,TAM*0.7);
        dados[i].setPosition(550+(i*120),600);

    }



    //fuente de puntaje y espacios
    fuente.loadFromFile("fuentes/roboto/Roboto-Black.ttf");

    //Cargar texturas de cartas
    TIPO_HEX tiposCartas[5]= {HEXARBOL,HEXLADRILLO,HEXOVEJA,HEXTRIGO,HEXMINERAL};
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cartas[j][i].setTipo(tiposCartas[i]);
            cartas[j][i].cargarTextura();
            cartas[j][i].setPosition(820+(50*i),60+(150*j));
            cartas[j][i].setScale(TAM,TAM);
        }
    }

    ///cartas para intercambio
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cartasIntercambio[j][i].setTipo(tiposCartas[i]);
            cartasIntercambio[j][i].cargarTextura();
            cartasIntercambio[j][i].setPosition(50+(50*i),600+(60*j));
            //cartasIntercambio[j][i].setScale(TAM,TAM);
            cartasIntercambio[j][i].setMostrar(false);
        }
    }

    //Cargar string puntos.
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            textCartasPuntos[i][j].setFont(fuente);
            textCartasPuntos[i][j].setColor(sf::Color(40,90,30));
            textCartasPuntos[i][j].setScale(0.5,0.5);
            textCartasPuntos[i][j].setPosition(830+(50*j),100+(150*i));
            textCartasPuntos[i][j].setString(to_string(0));
        }
    }
    /*//Numero de caminos (VER SI HACE FALTA)
    for(int i = 0; i< 72; i++)
    {
        textNumCaminos[i].setFont(fuente);
        textNumCaminos[i].setColor(sf::Color::White);
        textNumCaminos[i].setScale(0.5,0.5);
        textNumCaminos[i].setPosition(espacioCaminos[i].getPosition());
        textNumCaminos[i].setString(to_string(i));
    }*/

    //setear dado inicial y cargar texturas
    estado = TIRAR_DADO;
    turno = 2;

    //Poner todos los caminos cargados en false
    for(int i = 0; i < 72; i ++)
    {
        espacioCaminos[i].setMostrar(false);
    }

    for(int i = 0; i < 54; i++)
    {
        espacioCasas[i].setMostrar(false);
    }

    contador=1;
    //PONER EN FUNCION
    bFinalizar.setMostrar(false);
    bConstruir.setMostrar(false);
    bCasa.setMostrar(false);
    bCamino.setMostrar(false);
    bEdificio.setMostrar(false);
    bIntercambiar.setMostrar(false);



    ///PRUEBA
    char jugador1 [15];
    char jugador2[15];
    cout<<"Ingrese nombre de jugador 1: ";
    cin>>jugador1;
    cout<<"Ingrese nombre de jugador 2: ";
    cin>>jugador2;

    jugadores[0].setUsuario(jugador1);
    jugadores[1].setUsuario(jugador2);

    ventana.create(sf::VideoMode(1280,720),"Colonos de Gonzales Cat�n");
    fuente.loadFromFile("fuentes/minecraft/Minecraft.ttf");
    textCargando.setFont(fuente);
    textCargando.setPosition(450,300);
    textCargando.setString("CARGANDO");
    textCargando.setColor(sf::Color::Black);
    textCargando.setCharacterSize(72);
    ventana.clear(sf::Color::White);
    ventana.draw(textCargando);
    ventana.display();
    srand(time(NULL));
    fuente.loadFromFile("fuentes/roboto/Roboto-Bold.ttf");
    fuenteMensaje.loadFromFile("fuentes/janda_manatee/JandaManateeSolid.ttf");

    cuadroInfo.cargarTextura("sprites/recursos/cuadroInfo.png");
    cuadroInfo.setPosition(802,0);

//Mostrar Nombre de nombre
//--------------------------------------------------->
    for(int i = 0; i < 2; i++)
    {
        nombres[i].setFont(fuente);
        nombres[i].setCharacterSize(20);
        nombres[i].setPosition(820,20+(150*i));
        nombres[i].setString(jugadores[i].getUsuario());
    }
    nombres[0].setColor(sf::Color(102,0,0));
    nombres[1].setColor(sf::Color(0,0,102));

    nombre.setFont(fuente);
    nombre.setCharacterSize(40);
    nombre.setPosition(950,380);
    nombre.setString(nombres[turno-1].getString());
    nombre.setColor(nombres[turno-1].getColor());

    textTurno.setFont(fuente);
    textTurno.setCharacterSize(40);
    textTurno.setPosition(820,380);
    textTurno.setColor(sf::Color::Black);
    textTurno.setFillColor(sf::Color::White);

    textTurno.setString("Turno: ");

///------------------figuras de jugadores

    figuras[0][0].cargarTextura("sprites/estructuras/casaRoja.png");
    figuras[0][0].setPosition(1100,45);
    figuras[0][0].setScale(TAM,TAM);
    figuras[0][1].cargarTextura("sprites/estructuras/edificioRojo.png");
    figuras[0][1].setPosition(1165,26);
    figuras[0][1].setScale(TAM,TAM);
    figuras[0][2].cargarTextura("sprites/estructuras/caminoRojo90G.png");
    figuras[0][2].setPosition(1225,26);
    figuras[0][2].setScale(TAM*0.9,TAM*0.9);

    figuras[1][0].cargarTextura("sprites/estructuras/casaAzul.png");
    figuras[1][0].setPosition(1100,45+150);
    figuras[1][0].setScale(TAM,TAM);
    figuras[1][1].cargarTextura("sprites/estructuras/edificioAzul.png");
    figuras[1][1].setPosition(1165,26+150);
    figuras[1][1].setScale(TAM,TAM);
    figuras[1][2].cargarTextura("sprites/estructuras/caminoAzul90G.png");
    figuras[1][2].setPosition(1225,26+150);
    figuras[1][2].setScale(TAM*0.9,TAM*0.9);

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
        {
            textCantEstructuras[i][j].setFont(fuente);
            textCantEstructuras[i][j].setColor(sf::Color(40,90,30));
            textCantEstructuras[i][j].setScale(0.5,0.5);
            textCantEstructuras[i][j].setPosition(1130+(50*j),100+(150*i));
            textCantEstructuras[i][j].setString(to_string(0));
        }

    cambiarTurno();


    mensaje.setFont(fuenteMensaje);
    mensaje.setPosition (830,550);
    mensaje.setCharacterSize(20);
    mensaje.setColor(sf::Color::Black);
    mensaje.setLetterSpacing(2);
    mensaje.setString("Coloca una casa!");
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
    inicioJ();
    switch(estado)
    {
    case SELECT_CASA:

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar la CASA que quiere
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);

            if(!pressA)
            {
                pressA=true;

                for (int i=0; i<54; i++)
                {
                    if(espacioCasas[i].getMostrar())
                    {
                        sf::FloatRect _espacioCasas = espacioCasas[i].getGlobalBounds();
                        if(_espacioCasas.contains(mouseCoords))
                        {
                            casas[i].setNumJugador(turno);
                            casas[i].cargarTextura();
                            casas[i].setEspacio(espacioCasas[i]);
                            espacioCasas[i].setOcupado(true);
                            ultimo = espacioCasas[i];
                            pressB = true;

                            for(int j =0; j <4; j++)///coloca la disponibilidad de sus vecinos en false
                            {
                                if(espacioCasas[i].getEspacioCaminos()[j] != -1)
                                    for(int m = 0; m < 2; m++)

                                        espacioCasas[espacioCaminos[espacioCasas[i].getEspacioCaminos()[j]].getEspacioCasas()[m]].setDisponible(false);
                            }

                            for(int j=0; j< 3; j++)///avisa a los hexagonos que tocan el espacio que hay una nueva casa
                                if(espacioCasas[i].getHexagonos()[j] != -1)
                                {
                                    hexagonos[espacioCasas[i].getHexagonos()[j]].setEstructuras(turno);
                                }
                        }


                    }
                }
            }


            ///codigo limpieza, pone los espacios mostrados en false luego de elegir
        }
        else if(pressA && pressB)
        {
            estado = SELECT_CAMINO;
            mensaje.setString("Coloca un camino!");
            pressA=false;
            pressB=false;
            contador++;

            for (int i = 0; i < 3; i ++)
            {
                if(ultimo.getEspacioCaminos()[i] != -1)
                {
                    espacioCaminos[ultimo.getEspacioCaminos()[i]].setMostrar(true);
                }
            }
        }

        else if(pressA && !pressB)
        {
            pressA = false;
        }
        break;

    case SELECT_CAMINO:
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar el CAMINO que quiere
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);


            if(!pressA)
            {
                pressA=true;

                for (int i=0; i<72; i++)
                {
                    if(espacioCaminos[i].getMostrar())
                    {
                        sf::FloatRect _espacioCaminos = espacioCaminos[i].getGlobalBounds();
                        if(_espacioCaminos.contains(mouseCoords))
                        {


                            caminos[i].setEspacio(espacioCaminos[i]);
                            caminos[i].setNumJugador(turno);
                            caminos[i].cargarTextura();
                            espacioCaminos[i].setOcupado(true);
                            pressB=true;

                            for(int i =0; i < 72; i++)
                            {
                                espacioCaminos[i].setMostrar(false);
                            }

                        }
                    }
                }
            }

        }
        else if(pressA && pressB)
        {
            estado = TIRAR_DADO;
            pressA=false;
            pressB=false;
            contador++;
        }
        else if(pressA && !pressB)
        {
            pressA = false;
        }
        break;

    case TIRAR_DADO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))

        {
            if(!pressA)
            {
                pressA=true;
                //VER SI SACAR
                if(turno == 1)
                    cout << "Turno ROJO"<<endl;
                else
                    cout << "Turno AZUL"<<endl;

                //Al presionar enter se cambia los dados y se realizan los calculos.
                dados[0].tirarDado();
                dados[1].tirarDado();

                texto.setString(to_string(dados[1].getNumero()+dados[0].getNumero()));
                Ficha auxFicha;
                TIPO_HEX aux;

                if(dados[0].getNumero() + dados[1].getNumero() == 7)
                {
                    ladron.setActivado(true);
                }


                for(int i = 0; i < 19; i++)
                {
                    auxFicha = hexagonos[i].getFicha();///recuperamos la ficha del hexagono
                    if(auxFicha.getNumero() == dados[0].getNumero() + dados[1].getNumero()) ///vemos el numero que tiene
                    {
                        Hexagono hexBloqueado = ladron.getHexagonoBloqueado();
                        hexagonos[i].variarFicha();
                        for(int j = 0; j < 3; j++)
                        {
                            if(hexagonos[i].getEstructuras()[j] > 0 && hexagonos[i].getNumero() != hexBloqueado.getNumero() )    ///Verificamos que tenga alguna estructura
                                jugadores[hexagonos[i].getEstructuras()[j]-1].addRecurso(hexagonos[i].getNivel()[j], hexagonos[i].getTipo());
                        }
                    }
                }
                cargarPuntuacion();
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

                if(ladron.isActivado())
                {
                    estado = SELECCIONAR_HEX;
                    mensaje.setString("Coloca al ladron en un\hexagono");
                    cout << "Se paso a seleccionar hexagono";
                    ladron.setActivado(false);
                }
                else
                {
                    estado = SELECCIONAR_ACCION;
                    mensaje.setString("Elije una accion");
                    cout << "Se paso a seleccionar accion"<<endl;
                }
                pressA = false;
                cout << "Se pas� a seleccionar accion"<<endl;
            }
        }

        break;

    case SELECCIONAR_HEX: ///DEBE REUBICAR AL LADRON A UN NUEVO HEXAGONO Y EL JUGADOR DEBE ROBAR UNA CARTA SI EN EL HEXAGONO
        ///SELECCIONADO HAY UNA CASA ENEMIGA
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            Hexagono hexagonoBloqueado = ladron.getHexagonoBloqueado();
            for(int i = 0; i < 19; i++)
            {
                if(hexagonos[i].getNumero() != hexagonoBloqueado.getNumero())
                {
                    sf::FloatRect _hexagono = hexagonos[i].getGlobalBounds();
                    if(_hexagono.contains(mouseCoords))
                    {
                        if(!pressA)
                        {
                            pressA = true;
                            ladron.setHexagonoBloqueado(hexagonos[i]);
                            ladron.reubicar();
                            bool hayEnemigo = false;
                            for (int j = 0; j < 3; j++)
                            {
                                if(hexagonos[i].getEstructuras()[j] != 0 && hexagonos[i].getEstructuras()[j] != turno )
                                {
                                    hayEnemigo = true;
                                }


                            }
                            if(hayEnemigo)
                                robar();
                        }

                    }
                }

            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                mensaje.setString("Elije una accion");
                pressA =false;
            }

        }
        break;


    case SELECCIONAR_ACCION:///DEBE PRESIONAR EL BOTON CONSTRUIR O FINALIZAR

        bFinalizar.setMostrar(true);
        bConstruir.setMostrar(true);
        bIntercambiar.setMostrar(true);
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
                    mensaje.setString("Que vas a construir?");
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
                    cambiarTurno();
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
                    mensaje.setString("Hora de tirar los dados!");
                    pressA=false;
                }
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bIntercambiar = bIntercambiar.getGlobalBounds();///tomando el floatRect del Boton

            if(_bIntercambiar.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {
                if(!pressA)
                {
                    pressA = true;
                    cout << "Se va a intercambiar 3 x 1!";

                    mensaje.setString("has elegido intercambiar 3 x 1.\nElige el recurso que entregas.");
                }
            }
        }
        else
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse
            sf::FloatRect _bIntercambiar = bIntercambiar.getGlobalBounds();///tomando el floatRect del Boton

            if(_bIntercambiar.contains(mouseCoords))///preguntamos si las coords que tomo el mouse son del boton
            {


                if(pressA)
                {
                    estado = INTERCAMBIAR;
                    pressA = false;
                    pressB = false;
                    for(int i = 0; i < 5; i ++)
                    {
                        cartasIntercambio[0][i].setMostrar(true);
                    }

                }
            }
        }
        break;

    case INTERCAMBIAR:
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bFinalizar.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse

            if(!pressA)
            {
                pressA=true;

                for(int i = 0; i < 5; i++)
                {
                    sf::FloatRect _carta = cartasIntercambio[0][i].getGlobalBounds();
                    if(_carta.contains(mouseCoords))
                    {
                        switch(cartasIntercambio[0][i].getTipo())
                        {
                        case HEXARBOL:
                            if(jugadores[turno-1].getMadera() >= 3)
                            {
                                intercambio=HEXARBOL;
                                pressB = true;
                            }
                            break;
                        case HEXTRIGO:
                            if(jugadores[turno-1].getTrigo() >= 3)
                            {
                                intercambio=HEXTRIGO;
                                pressB = true;
                            }
                            break;
                        case HEXLADRILLO:
                            if(jugadores[turno-1].getLadrillo() >= 3)
                            {
                                intercambio=HEXLADRILLO;
                                pressB = true;
                            }
                            break;
                        case HEXOVEJA:
                            if(jugadores[turno-1].getLana() >= 3)
                            {
                                intercambio=HEXOVEJA;
                                pressB = true;
                            }
                            break;
                        case HEXMINERAL:
                            if(jugadores[turno-1].getPiedra() >= 3)
                            {
                                intercambio=HEXMINERAL;
                                pressB = true;
                            }
                            break;
                        }
                    }
                }

                cout << "Se intercambio"<<endl;
            }
        }
        else if(pressA && !pressB)
        {
            estado = SELECCIONAR_ACCION;
            pressA = false;
            pressB = false;
            cout << "No hay recursos"<<endl;
            mensaje.setString("Elije una accion");
            for (int i = 0; i < 5 ; i++)
            {
                cartasIntercambio[0][i].setMostrar(false);
            }

        }

        else if(pressA && pressB)
        {
            estado = SELECCIONAR_RECURSO;
            pressA = false;
            pressB = false;
            cout << "hay recursos"<<endl;
            for (int i = 0; i < 5 ; i++)
            {
                cartasIntercambio[0][i].setMostrar(false);
            }
            for (int i = 0; i < 5 ; i++)
            {
                cartasIntercambio[1][i].setMostrar(true);
            }
            mensaje.setString("Seleccione recurso");
        }
        break;

    case SELECCIONAR_RECURSO:
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);/// tomando las coords del mouse

            if(!pressA)
            {
                pressA=true;

                for(int i = 0; i < 5; i++)
                {
                    sf::FloatRect _carta = cartasIntercambio[1][i].getGlobalBounds();
                    if(_carta.contains(mouseCoords))
                    {
                        switch(cartasIntercambio[1][i].getTipo())
                        {
                        case HEXARBOL:
                            jugadores[turno-1].addRecurso(-3,intercambio);
                            jugadores[turno-1].addRecurso(1,HEXARBOL);
                            pressB = true;
                            break;
                        case HEXTRIGO:
                            jugadores[turno-1].addRecurso(-3,intercambio);
                            jugadores[turno-1].addRecurso(1,HEXTRIGO);
                            pressB = true;


                            break;
                        case HEXLADRILLO:
                            jugadores[turno-1].addRecurso(-3,intercambio);
                            jugadores[turno-1].addRecurso(1,HEXLADRILLO);
                            pressB = true;
                            break;
                        case HEXOVEJA:
                            jugadores[turno-1].addRecurso(-3,intercambio);
                            jugadores[turno-1].addRecurso(1,HEXOVEJA);
                            pressB = true;
                            break;
                        case HEXMINERAL:
                            jugadores[turno-1].addRecurso(-3,intercambio);
                            jugadores[turno-1].addRecurso(1,HEXMINERAL);
                            pressB = true;
                            break;
                        }
                        cout << "hola"<<endl;
                        cargarPuntuacion();
                    }
                }

                cout << "Se intercambio"<<endl;
            }
        }
        else if(pressA && !pressB)
        {
            estado = SELECCIONAR_ACCION;
            pressA = false;
            pressB = false;
            cout << "Se cancelo"<<endl;
            mensaje.setString("Elije una accion");


        }

        else if(pressA && pressB)
        {
            estado = SELECCIONAR_ACCION;
            pressA = false;
            pressB = false;
            cout << "Se intercambio"<<endl;
            for (int i = 0; i < 5 ; i++)
            {
                cartasIntercambio[1][i].setMostrar(false);
            }
            for (int i = 0; i < 5 ; i++)

            mensaje.setString("Elija una accion");
        }


        break;

    case CONSTRUCCION:///DEBE SELECCIONAR QUE CONSTRUIR(CASA, EDIFICIO O CAMINO)

        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
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
                    mensaje.setString("Coloca una casa!");
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
                    mensaje.setString("Coloca un edificio");
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
                    mensaje.setString("Coloca un camino");
                    pressA=false;
                }
            }
        }
        break;

    case COLOCACION_CAMINO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar el CAMINO que quiere
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);


            if(!pressA)
            {
                pressA=true;

                for (int i=0; i<72; i++)
                {
                    if(espacioCaminos[i].getMostrar())
                    {
                        sf::FloatRect _espacioCaminos = espacioCaminos[i].getGlobalBounds();
                        if(_espacioCaminos.contains(mouseCoords))
                        {

                            if(jugadores[turno-1].getLadrillo()>=1 && jugadores[turno-1].getMadera()>=1)
                            {
                                caminos[i].setEspacio(espacioCaminos[i]);
                                caminos[i].setNumJugador(turno);
                                caminos[i].cargarTextura();
                                espacioCaminos[i].setOcupado(true);


                                //Consumo de recursos
                                jugadores[turno-1].setMadera(jugadores[turno-1].getMadera()-1);
                                jugadores[turno-1].setLadrillo(jugadores[turno-1].getLadrillo()-1);

                                //Se suma caminos construidos como un valor.
                                jugadores[turno-1].setCaminosConstruidos(jugadores[turno-1].getCaminosConstruidos()+1);


                                cargarPuntuacion();
                            }
                            else
                            {
                                cout<<"No hay recursos suficientes"<<endl;
                            }

                        }
                    }
                }
            }
            ///codigo limpieza, pone los espacios mostrados en false luego de elegir
            for(int i =0; i < 72; i++)
            {
                espacioCaminos[i].setMostrar(false);
            }

        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                mensaje.setString("Elige una accion");
                pressA=false;
            }
        }
        break;

    case COLOCACION_CASA:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))//para seleccionar la CASA que quiere
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);

            if(!pressA)
            {
                pressA=true;

                for (int i=0; i<54; i++)
                {
                    if(espacioCasas[i].getMostrar())
                    {
                        sf::FloatRect _espacioCasas = espacioCasas[i].getGlobalBounds();
                        if(_espacioCasas.contains(mouseCoords))
                        {
                            if(jugadores[turno-1].getLadrillo()>=1 && jugadores[turno-1].getMadera()>=1 && jugadores[turno-1].getTrigo()>=1 && jugadores[turno-1].getLana()>=1)
                            {
                                casas[i].setNumJugador(turno);
                                casas[i].cargarTextura();
                                casas[i].setEspacio(espacioCasas[i]);
                                espacioCasas[i].setOcupado(true);

                                for(int j =0; j <4; j++)//coloca la disponibilidad de sus vecinos en false
                                {
                                    if(espacioCasas[i].getEspacioCaminos()[j] != -1)
                                        for(int m = 0; m < 2; m++)

                                            espacioCasas[espacioCaminos[espacioCasas[i].getEspacioCaminos()[j]].getEspacioCasas()[m]].setDisponible(false);
                                }

                                for(int j=0; j< 3; j++)//avisa a los hexagonos que tocan el espacio que hay una nueva casa
                                {
                                    if(espacioCasas[i].getHexagonos()[j] != -1)
                                    {
                                        hexagonos[espacioCasas[i].getHexagonos()[j]].setEstructuras(turno);
                                    }
                                }

                                //Se agrega un punto de partida por colocacion de casa
                                jugadores[turno-1].setPuntosVictoria(jugadores[turno-1].getPuntosVictoria()+1);

                                //Se suma casas casas construidas como puntos
                                jugadores[turno-1].setCasasConstruidas(jugadores[turno-1].getCasasConstruidas()+1);

                                //Consumo de recursos
                                jugadores[turno-1].setMadera(jugadores[turno-1].getMadera()-1);
                                jugadores[turno-1].setLadrillo(jugadores[turno-1].getLadrillo()-1);
                                jugadores[turno-1].setTrigo(jugadores[turno-1].getTrigo()-1);
                                jugadores[turno-1].setLana(jugadores[turno-1].getLana()-1);

                                cargarPuntuacion();
                            }
                            //else
                            {
                                cout<<"No hay recursos suficientes"<<endl;
                            }
                        }
                    }
                }
            }

            //codigo limpieza, pone los espacios mostrados en false luego de elegir
            for(int i =0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                mensaje.setString("Elige una accion");
                pressA=false;
            }
        }
        break;

    case COLOCACION_EDIFICIO:
        bFinalizar.setMostrar(false);
        bConstruir.setMostrar(false);
        bIntercambiar.setMostrar(false);
        bCasa.setMostrar(false);
        bCamino.setMostrar(false);
        bEdificio.setMostrar(false);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))///para seleccionar el EDIFICIO que quiere
        {
            sf::Vector2f mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(ventana);

            if(!pressA)
            {
                pressA=true;


                for(int i=0; i<54; i++)
                {
                    if(espacioCasas[i].getMostrar())
                    {
                        sf::FloatRect _espacioCiudad = espacioCiudad[i].getGlobalBounds();
                        if(_espacioCiudad.contains(mouseCoords))
                        {
                            if(jugadores[turno-1].getLadrillo()>=3 && jugadores[turno-1].getTrigo()>=2)
                            {
                                for(int j=0; j< 3; j++)//avisa a los hexagonos que tocan el espacio que hay una nueva casa
                                {
                                    if(espacioCasas[i].getHexagonos()[j] != -1)
                                    {
                                        hexagonos[espacioCasas[i].getHexagonos()[j]].subirNivel(turno);
                                    }
                                }

                                //Se agrega un punto de partida por colocacion de casa
                                jugadores[turno-1].setPuntosVictoria(jugadores[turno-1].getPuntosVictoria()+1);

                                jugadores[turno-1].setCiudadesConstruidas(jugadores[turno-1].getCiudadesConstruidas()+1);
                                //Consumo de recursos
                                jugadores[turno-1].setLadrillo(jugadores[turno-1].getLadrillo()-3);
                                jugadores[turno-1].setTrigo(jugadores[turno-1].getTrigo()-2);
                            }
                            else
                            {
                                cout<<"No hay recursos suficientes"<<endl;
                            }
                        }
                    }
                }
            }
            //codigo limpieza, pone los espacios mostrados en false luego de elegir
            for(int i =0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
        }
        else
        {
            if(pressA)
            {
                estado = SELECCIONAR_ACCION;
                mensaje.setString("Elige una accion");
                pressA=false;
            }
        }
        break;

    }///FIN SWITCH
    if(jugadores[turno-1].getPuntosVictoria()>=10)
    {
        finish();
    }
}

void GamePlay::draw()
{
    ventana.clear(sf::Color(96, 159, 253));

    //Dibujar texturas
    ventana.draw(mapa);
    ventana.draw(cuadroInfo);

    for (int i=0; i<19; i++)
    {
        ventana.draw(hexagonos[i]);
    };

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
            if(cartasIntercambio[j][i].getMostrar())
                ventana.draw(cartasIntercambio[j][i]);

    for(int i=0; i < 5; i++)
        for(int j=0; j < 2; j++)
            ventana.draw(textCartasPuntos[j][i]);

    for(int i=0; i < 2; i++)
        for(int j=0; j < 3; j++)
            ventana.draw(textCantEstructuras[i][j]);

    ventana.draw(textTurno);
    ventana.draw(nombre);

    /*for(int i = 0; i < 72; i++)
    {
        ventana.draw(textNumCaminos[i]);
    }*/
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
    if(bIntercambiar.getMostrar())
        ventana.draw(bIntercambiar);

    for(int i = 0; i < 2; i++)
    {
        ventana.draw(nombres[i]);
    }

    ventana.draw(mensaje);
    for(int i =0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            ventana.draw(figuras[i][j]);

    ventana.draw(ladron);


    ventana.display();


}

void GamePlay::finish()
{
    cout<<"GANO EL JUGADOR: "<<turno<<endl;
    jugadores[turno-1].setResultadoPartida(1);

    for(int i=0; i<2; i++)
    {
        jugadores[i].grabarEnDisco();
    }

    Jugador player;
    int pos;
    while(player.leerDeDisco(pos++))
    {

        cout<<player.getResultadoPartida()<<endl;
    }

    ventana.close();
}

//--------------//
void GamePlay::inicioJ()
{
    if(contador <= 9 )
    {
        switch(contador)
        {
        case 1:
            estado = SELECT_CASA;
            mensaje.setString("Coloca una casa!");
            turno = 1;
            nombre.setString(nombres[turno-1].getString());
            nombre.setColor(nombres[turno-1].getColor());
            for(int i = 0; i < 54; i++)
            {
                if(espacioCasas[i].isDisponible())
                    espacioCasas[i].setMostrar(true);
            }
            break;

        case 2:
            estado = SELECT_CAMINO;
            mensaje.setString("Coloca un camino");
            turno = 1;
            for(int i = 0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
            break;

        case 3:
            estado = SELECT_CASA;
            mensaje.setString("Coloca una casa!");
            turno = 2;
            nombre.setString(nombres[turno-1].getString());
            nombre.setColor(nombres[turno-1].getColor());
            for(int i = 0; i < 54; i++)
            {
                if(espacioCasas[i].isDisponible())
                    espacioCasas[i].setMostrar(true);
            }

            break;

        case 4:
            estado = SELECT_CAMINO;
            mensaje.setString("Coloca un camino");
            turno = 2;
            for(int i = 0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
            break;

        case 5:
            estado = SELECT_CASA;
            mensaje.setString("Coloca una casa!");
            turno = 2;
            for(int i = 0; i < 54; i++)
            {
                if(espacioCasas[i].isDisponible())
                    espacioCasas[i].setMostrar(true);
            }
            break;

        case 6:
            estado = SELECT_CAMINO;
            mensaje.setString("Coloca un camino");
            turno = 2;
            for(int i = 0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
            break;

        case 7:
            estado = SELECT_CASA;
            mensaje.setString("Coloca una casa!");
            turno = 1;
            nombre.setString(nombres[turno-1].getString());
            nombre.setColor(nombres[turno-1].getColor());
            for(int i = 0; i < 54; i++)
            {
                if(espacioCasas[i].isDisponible())
                    espacioCasas[i].setMostrar(true);
            }
            break;

        case 8:
            estado = SELECT_CAMINO;
            mensaje.setString("Coloca un camino");
            turno = 1;
            for(int i = 0; i < 54; i++)
            {
                espacioCasas[i].setMostrar(false);
            }
            break;

        case 9:
            estado = TIRAR_DADO;
            mensaje.setString("Hora de tirar los dados!");
            contador++;
            break;

        }

    }

}

void GamePlay::cargarPuntuacion()
{
    for(int j=0; j < 2; j++)
    {
        textCartasPuntos[j][0].setString(to_string(jugadores[j].getMadera()));
        textCartasPuntos[j][1].setString(to_string(jugadores[j].getLadrillo()));
        textCartasPuntos[j][2].setString(to_string(jugadores[j].getLana()));
        textCartasPuntos[j][3].setString(to_string(jugadores[j].getTrigo()));
        textCartasPuntos[j][4].setString(to_string(jugadores[j].getPiedra()));
    }
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

        //
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

    //
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

void GamePlay::cargarHexagonos()//Carga el hexagono y les asigna el tipo
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
        hexagonos[i].setNumero(i);
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

    ladron.cargarTextura("sprites/recursos/ladron.png");
    ladron.setScale(TAM,TAM);

    for(int i = 0; i < 19; i++)
    {
        if(hexagonos[i].getTipo() == HEXDESIERTO)
            ladron.setHexagonoBloqueado(hexagonos[i]);
        ladron.reubicar();


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

    bIntercambiar.cargarTextura("sprites/recursos/botonIntercambiar.png");
    bIntercambiar.setScale(TAM*0.7,TAM*0.7);
    bIntercambiar.setPosition(350,600);

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

sf::FloatRect GamePlay::achicarFloatRect(sf::FloatRect _frect,float _tam)
{
    _frect.height *_tam;
    _frect.width *_tam;
    _frect.top*_tam;
    _frect.left *_tam;

    return _frect;
}

void GamePlay::cambiarTurno()
{
    if(turno == 1)
        turno = 2;
    else if(turno == 2)
        turno = 1;
    nombre.setString(nombres[turno-1].getString());
    nombre.setColor(nombres[turno-1].getColor());

}
void GamePlay::robar()
{
    int random, n, TotRecursos=0;
    random = rand()%5;
    bool seRobo=true;
    if(turno==1)
        n = 2;
    else
        n = 1;

    TotRecursos = jugadores[n-1].getLadrillo()+jugadores[n-1].getLana()+jugadores[n-1].getMadera()+jugadores[n-1].getPiedra()+jugadores[n-1].getTrigo();

    if(TotRecursos != 0)
    {
        while(seRobo)
        {
            switch(random)
            {
            case 0:
                if(jugadores[n-1].getLadrillo() != 0)
                {
                    jugadores[n-1].addRecurso(-1,HEXLADRILLO);
                    jugadores[turno-1].addRecurso(1,HEXLADRILLO);
                    seRobo = false;
                    cout << "se descontó"<<random<<endl;
                }
                break;
            case 1:
                if(jugadores[n-1].getLana() != 0)
                {
                    jugadores[n-1].addRecurso(-1,HEXOVEJA);
                    jugadores[turno-1].addRecurso(1,HEXOVEJA);
                    seRobo = false;
                    cout << "se descontó"<<random<<endl;
                }
                break;
            case 2:
                if(jugadores[n-1].getMadera() != 0)
                {
                    jugadores[n-1].addRecurso(-1,HEXARBOL);
                    jugadores[turno-1].addRecurso(1,HEXARBOL);
                    seRobo = false;
                    cout << "se descontó"<<random<<endl;
                }
                break;
            case 3:
                if(jugadores[n-1].getPiedra() != 0)
                {
                    jugadores[n-1].addRecurso(-1,HEXMINERAL);
                    jugadores[turno-1].addRecurso(1,HEXMINERAL);
                    seRobo = false;
                    cout << "se descontó"<<random<<endl;
                }
                break;
            case 4:
                if(jugadores[n-1].getTrigo() != 0)
                {
                    jugadores[n-1].addRecurso(-1,HEXTRIGO);
                    jugadores[turno-1].addRecurso(1,HEXTRIGO);
                    seRobo = false;
                    cout << "se descontó"<<random<<endl;
                }
                break;
            }
            random = rand()%5;

        }
    }
    cout << TotRecursos<<endl;
    cargarPuntuacion();
}
