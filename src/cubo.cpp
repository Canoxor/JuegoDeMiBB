#include "cubo.h"
#include <SFML/Graphics.hpp>

using namespace sf;

cubo::cubo(){



}

cubo::cubo(float x, float y)
{
    posX=x;
    posY=y;

    if(!moldeCubo.loadFromFile("imagen/cubo.png"))
    {
        // Si hay un error salimos
        exit(6);
    }

    cuerpoCubo.setTexture(moldeCubo);

    cuerpoCubo.setPosition(x, y);

    //ctor
}

void cubo::setPos(float x , float y)
{
    posX=x;
    posY=y;
     if(!moldeCubo.loadFromFile("imagen/cubo.png"))
    {
        // Si hay un error salimos
        exit(6);
    }
    cuerpoCubo.setTexture(moldeCubo);
    cuerpoCubo.setPosition(x, y);
}


cubo::~cubo()
{
    //dtor
}


float cubo::cargarPosX(){

for(int x=0;x<13;x++){

    vecX[0]+=72;
}
}

float cubo::cargarPosY(){

for(int x=0;x<8;x++){

    vecY[0]+=72;
}
}














