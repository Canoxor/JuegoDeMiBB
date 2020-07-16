#include <SFML/Graphics.hpp>
using namespace sf;
#include "bomba.h"

bomba::bomba(Texture &Bomba, Texture &Explosion_1)
{
    BombaNormal.setTexture(Bomba);

    BombaExplotando_lvl_1.setTexture(Explosion_1);

    ///TIEMPO BOMBA
    tiempo=reloj.getElapsedTime();
}

void bomba::Aparecer(float x,float y )
{
    Estado=0;
    posX=x;
    posY=y;
    BombaNormal.setPosition(posX,posY);
}


///TIEMPO
float bomba::getTiempo()
{
    tiempo= reloj.getElapsedTime();
    return tiempo.asSeconds();
}

void bomba::setTiempo()
{
    reloj.restart();
}

bomba::~bomba()
{
    //dtor
}
