#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#include "Jugador.h"
#include "InterfazJug.h"


InterfazJug::InterfazJug()
{
    //ctor
}


void InterfazJug::setPos(float x , float y, int cant) //ES LO QUE USA COMO ""CONSTRUCTOR""
{
    posX=x;
    posY=y;

switch(cant){

    case 1:

            if(!moldeVida.loadFromFile("imagen/Personajes/corazones.png", IntRect(0, 0, 96, 21)))
            {
            // Si hay un error salimos
            exit(3);
            }
        break;

     case 2:

            if(!moldeVida.loadFromFile("imagen/Personajes/corazones.png", IntRect(0, 22, 96, 21)))
            {
            // Si hay un error salimos
            exit(3);
            }
        break;

     case 3:

            if(!moldeVida.loadFromFile("imagen/Personajes/corazones.png", IntRect(0, 47, 96, 21)))
            {
            // Si hay un error salimos
            exit(3);
            }
        break;

}

    cuerpoVida.setTexture(moldeVida);
    cuerpoVida.setPosition(x, y);
    cuerpoVida.setScale(2, 2);

}

/*
void InterfazJug::cambioVida(int cant){

switch(cant){

case 1:

    if(!moldeVida.loadFromFile("imagen/corazones1.png"))
            {
            // Si hay un error salimos
            exit(3);
            }
    break;


case 2:

    if(!moldeVida.loadFromFile("imagen/corazones2.png"))
            {
            // Si hay un error salimos
            exit(3);
            }

    break;


case 3:

    if(!moldeVida.loadFromFile("imagen/corazones3.png"))
            {
            // Si hay un error salimos
            exit(3);
            }


    break;





}

}
*/


InterfazJug::~InterfazJug()
{
    //dtor
}


