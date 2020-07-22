
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Jugador.h"



Jugador::Jugador(float x, float y, int a)
{
    //ctor
    posX=x;
    posY=y;
    tiempo=reloj.getElapsedTime();

    // ultimatecla=Direcciones::Abajo;
    // direccion=Direcciones::Ninguna;

    MoverSprites();
}

void Jugador::setScreenJug(float x, float y, int cant=3)
{
    screenJug.setPos(x, y, cant); /// podria pasar como parametro la vida que tiene el jug
}

void Jugador::setPos(float x, float y)
{
    posX=x;
    posY=y;
    MoverSprites();
}

void Jugador::moverDerecha(float x, float y, float v)
{
    /// Orienta al personaje
    Orientacion = 2;

    /// Reset del delay por animacion
    DelaySprites_Arriba = 0;
    DelaySprites_Abajo = 0;
    DelaySprites_Izquierda = 0;

    /// Suma delay
    DelaySprites_Derecha++;

    if(DelaySprites_Derecha == DelayMax)
    {
        DelaySprites_Derecha = 0;

        Estado_Animacion_Derecha++;

        if(Estado_Animacion_Derecha > 5)
        {
            Estado_Animacion_Derecha = 0;
        }
    }

    x+=v;
    y+=0;
    setX(x);
    setY(y);
    MoverSprites();
}

void Jugador::moverIzquierda(float x,float y, float v)
{
    /// Orienta al personaje
    Orientacion = 4;

    /// Reset del delay por animacion
    DelaySprites_Arriba = 0;
    DelaySprites_Derecha = 0;
    DelaySprites_Abajo = 0;

    /// Suma delay
    DelaySprites_Izquierda++;

    if(DelaySprites_Izquierda == DelayMax)
    {
        DelaySprites_Izquierda = 0;

        Estado_Animacion_Izquierda++;

        if(Estado_Animacion_Izquierda > 5)
        {
            Estado_Animacion_Izquierda = 0;
        }
    }

    x-=v;
    y+=0;
    setX(x);
    setY(y);
    MoverSprites();
}

void Jugador::moverArriba(float x,float y, float v)
{
    /// Orienta al personaje
    Orientacion = 1;

    /// Reset del delay por animacion
    DelaySprites_Derecha = 0;
    DelaySprites_Abajo = 0;
    DelaySprites_Izquierda = 0;

    /// Suma delay
    DelaySprites_Arriba++;

    if(DelaySprites_Arriba == DelayMax)
    {
        DelaySprites_Arriba = 0;

        Estado_Animacion_Arriba++;

        if(Estado_Animacion_Arriba > 5)
        {
            Estado_Animacion_Arriba = 0;
        }
    }

    x+=0;
    y-=v;
    setX(x);
    setY(y);
    MoverSprites();
}

void Jugador::moverAbajo(float x,float y, float v)
{
    /// Orienta al personaje
    Orientacion = 3;

    /// Reset del delay por animacion
    DelaySprites_Arriba = 0;
    DelaySprites_Derecha = 0;
    DelaySprites_Izquierda = 0;

    /// Suma delay
    DelaySprites_Abajo++;

    if(DelaySprites_Abajo == DelayMax)
    {
        DelaySprites_Abajo = 0;

        Estado_Animacion_Abajo++;

        if(Estado_Animacion_Abajo > 5)
        {
            Estado_Animacion_Abajo = 0;
        }
    }

    x+=0;
    y+=v;
    setX(x);
    setY(y);
    MoverSprites();
}

Jugador::~Jugador()
{
    //dtor

}

