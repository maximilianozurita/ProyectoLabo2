#include <iostream>
using namespace std;
#include <cstring>
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Dado.h"
#include "GamePlay.h"

int main(){

    GamePlay game;

    game.run();

/*
//Prueba dado
Dado dado1;
int option;
cout<<"option: ";cin>>option;
cout<<endl;
while(option!=3){
    switch (option){
    case 1:
    dado1.tirarDado();
    cout<<dado1.getNumero()<<endl;
    break;
    }
    cout<<"option: ";cin>>option;
    cout<<endl;
}
*/
    return 0;

}
