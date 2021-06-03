#include <iostream>
using namespace std;
#include <cstring>
#include "Entidad.h"
#include <SFML/Graphics.hpp>

Entidad::Entidad(){

}
sf::Texture& Entidad::getTex(){
    return tex;
}

sf::Sprite& Entidad::getSp(){
    return sp;
}
void  Entidad::setTex(sf::Texture _tex){
    tex = _tex;
}
void  Entidad::setSp(sf::Sprite _sp){
    sp = _sp;
}
