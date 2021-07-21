#include "Saludo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Saludo::Saludo()
{
    init();
}

void Saludo::run()
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

void Saludo::init()
{
    ventana.setFramerateLimit(60);
    ventana.create(sf::VideoMode(1280,720),"Saludo");

    fuente.loadFromFile("fuentes/big_star/BigStar-Regular.ttf");


    for(int i =0; i < 5; i++)
    {
        entidades[i].setMostrar(false);
    }

    for(int i= 0; i < 5; i++)
    {
        textDialogos[i].setCharacterSize(0);
        textDialogos[i].setFont(fuente);
    }

    entidades[RECTANGULO1].cargarTextura("sprites/inicio/rectangulo1.png");
    entidades[RECTANGULO1].setPosition(879,252);
    entidades[RECTANGULO1].setMostrar(true);

    textDialogos[TITULO].setPosition(5,0);
    textDialogos[TITULO].setString("COLONOS\nDE\nCATAN");
    textDialogos[TITULO].setCharacterSize(200);

    textDialogos[JUGAR].setPosition(1009,289);
    textDialogos[JUGAR].setString("Jugar");
    textDialogos[JUGAR].setCharacterSize(40);

    textDialogos[PUNTOS].setPosition(940,378);
    textDialogos[PUNTOS].setString("Ver Puntuacion");
    textDialogos[PUNTOS].setCharacterSize(40);

    entidades[RECTANGULO2].cargarTextura("sprites/inicio/rectangulo2.png");
    entidades[LINEA_NAME].cargarTextura("sprites/inicio/linea.png");

    estado = S_INICIO;
}
void Saludo::update()
{
    switch(estado)
    {
    case S_INICIO:
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouseCoords =(sf::Vector2f) sf::Mouse::getPosition(ventana);
            sf::FloatRect _text = textDialogos[JUGAR].getGlobalBounds();

            if(_text.contains(mouseCoords))
            {
                if(!bPress)
                {
                    bPress=true;
                    cout << "Se presiono jugar"<<endl;


                }
            }
        }
        else
        {
            textDialogos[JUGAR].setColor(sf::Color::White);
            sf::Vector2f mouseCoords =(sf::Vector2f) sf::Mouse::getPosition(ventana);
            sf::FloatRect _text = textDialogos[JUGAR].getGlobalBounds();

            if(_text.contains(mouseCoords))
            {
                textDialogos[JUGAR].setColor(sf::Color::Red);
                if(bPress)
                {
                    bPress=false;
                    estado=S_JUGAR;
                    textDialogos[JUGADOR].setPosition(990, 194);
                    textDialogos[JUGADOR].setString("JUGADOR 1");
                    textDialogos[JUGADOR].setCharacterSize(40);

                    textDialogos[PUNTOS].setCharacterSize(0);
                    textDialogos[JUGAR].setCharacterSize(0);

                    entidades[RECT_NAME1].cargarTextura("sprites/inicio/rectNombreRojo.png");
                    entidades[RECT_NAME1].setPosition(934,194);
                    entidades[RECT_NAME1].setMostrar(true);

                    entidades[RECTANGULO2].setPosition(879,158);
                    entidades[RECTANGULO2].setMostrar(true);

                    textDialogos[MSN1].setPosition(945, 289);
                    textDialogos[MSN1].setString("Ingrese Nombre");
                    textDialogos[MSN1].setCharacterSize(40);

                    entidades[LINEA_NAME].setPosition(935,420);
                    entidades[LINEA_NAME].setMostrar(true);



            }
        }
        }
        break;

    case S_JUGAR:
        break;
    }

}
void Saludo::draw()
{
    ventana.clear(sf::Color::Black/*(96, 159, 253)*/);


    for(int i =0; i < 5; i++)
    {
        if(entidades[i].getMostrar())
            ventana.draw(entidades[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        if(textDialogos[i].getCharacterSize() != 0)
        {
            ventana.draw(textDialogos[i]);
        }
    }
    ventana.display();
}
void Saludo::finish()
{

}
