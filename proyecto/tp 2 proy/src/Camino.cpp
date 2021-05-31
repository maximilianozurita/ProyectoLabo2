#include <iostream>
using namespace std;
#include <cstring>
#include "Camino.h"
#include <SFML/Graphics.hpp>

void Camino::setCoord(sf::Vector2f _coord){
    coord=_coord;
};
sf::Vector2f Camino::getCoord(){
    return coord;
};
