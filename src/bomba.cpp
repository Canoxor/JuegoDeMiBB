#include <SFML/Graphics.hpp>
using namespace sf;
#include "bomba.h"

bomba::bomba()
{
    if(!moldebomba.loadFromFile("imagen/bomba.png"))
    {
        // Si hay un error salimos
        exit(5);
    }
   //moldebomba.setSmooth(true);
    cuerpobomba.setTexture(moldebomba);

       if(!MoldeBombaExplota.loadFromFile("imagen/explocion_1.png"))
    {
        // Si hay un error salimos
        exit(5);
    }
   // moldebomba.setSmooth(true);
    cuerpobomba.setTexture(mold);




    ///TIEMPO BOMBA
    tiempo1=reloj1.getElapsedTime();

    ///pj2
    tiempo2=reloj2.getElapsedTime();

}

void bomba::Aparecer(float x,float y )
{
    posX=x;
    posY=y;
    cuerpobomba.setPosition(posX,posY);
}

void bomba::Explota(){

    explotar=true;



    cuerpobomba.setPosition(posX,posY);
   // system("pause");
}

void bomba::ExplotaFin(){

     explotar=false;

    if(!moldebomba.loadFromFile("imagen/bomba.png"))
    {
        // Si hay un error salimos
        exit(8);
    }

    cuerpobomba.setTexture(moldebomba);


}


///TIEMPO
float bomba::getTiempo1()
{
    tiempo1= reloj1.getElapsedTime();
    return tiempo1.asSeconds();
}

float bomba::getTiempo2()
{
    tiempo2= reloj2.getElapsedTime();
    return tiempo2.asSeconds();
}

void bomba::setTiempo2()
{
    reloj2.restart();
}

void bomba::setTiempo1()
{
    reloj1.restart();
}

bomba::~bomba()
{
    //dtor
}
