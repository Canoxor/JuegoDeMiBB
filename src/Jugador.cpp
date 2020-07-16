
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Jugador.h"



Jugador::Jugador(float x, float y, int a)
{
    //ctor
    posX=x;
    posY=y;

//    ultimatecla=Direcciones::Abajo;
//    direccion=Direcciones::Ninguna;

    if(!molde.loadFromFile("imagen/Personajes/Jugador_1/Jug1_quieto_0.png"))
    {
        // Si hay un error salimos
        exit(1);
    }

    cuerpo.setTexture(molde);
    cuerpo.setScale(1, 1);

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

void Jugador::setPos(float x, float y)
{

    posX=x;
    posY=y;
/*
    if(!molde.loadFromFile("imagen/Personajes/lobito.png"))
    {
        // Si hay un error salimos
        exit(1);
    }

    cuerpo.setTexture(molde);
    cuerpo.setPosition(x, y);
/*/
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

