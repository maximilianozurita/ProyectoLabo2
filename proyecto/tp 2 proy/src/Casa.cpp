#include <iostream>
using namespace std;
#include <cstring>
#include "Casa.h"
#include "Espacio.h"
#include <SFML/Graphics.hpp>

void Casa::setCoord(sf::Vector2f _coord){
    coord=_coord;
};
sf::Vector2f Casa::getCoord(){
    return coord;
};
