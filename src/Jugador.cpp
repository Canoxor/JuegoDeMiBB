
#include <SFML/Graphics.hpp>


using namespace sf;

#include "Jugador.h"

Jugador::Jugador(float x, float y, int a)
{
    //ctor
    posX=x;
    posY=y;

    if(!molde.loadFromFile("imagen/lobito.png"))
    {
        // Si hay un error salimos
        exit(1);
    }

    cuerpo.setTexture(molde);
    if(a==0)
    {
        ///cuerpo.setColor(Color(255, 0, 0));
    }
    else
    {
        ///cuerpo.setColor(Color(255, 0, 255, 200));
    }

    cuerpo.setPosition(x, y);




}



void Jugador::moverDerecha(float x, float y, float v)
{
    x+=v;
    y+=0;
    setX(x);
    setY(y);
    cuerpo.setPosition(x,y);
}

void Jugador::moverIzquierda(float x,float y, float v)
{
    x-=v;
    y+=0;
    setX(x);
    setY(y);
    cuerpo.setPosition(x,y);

}

void Jugador::moverArriba(float x,float y, float v)
{
    x+=0;
    y-=v;


    setX(x);
    setY(y);
    cuerpo.setPosition(x,y);

}

void Jugador::moverAbajo(float x,float y, float v)
{
    x+=0;
    y+=v;
    setX(x);
    setY(y);
    cuerpo.setPosition(x,y);
}

Jugador::~Jugador()
{
    //dtor

}
