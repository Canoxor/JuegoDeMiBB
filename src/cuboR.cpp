#include "cuboR.h"

cuboR::cuboR()
{
    //ctor
}

cuboR::cuboR(float x, float y)
{
    posX=x;
    posY=y;

    if(!moldeCuboR.loadFromFile("imagen/Cubos/cuboR.png"))
    {
        // Si hay un error salimos
        exit(7);
    }

    cuerpoCuboR.setTexture(moldeCuboR);

    cuerpoCuboR.setPosition(x, y);

    //ctor
}

void cuboR::setPos(float x , float y) //ES LO QUE USA COMO ""CONSTRUCTOR""
{
    posX=x;
    posY=y;
     if(!moldeCuboR.loadFromFile("imagen/Cubos/cuboR.png"))
    {
        // Si hay un error salimos
        exit(6);
    }
    cuerpoCuboR.setTexture(moldeCuboR);
    cuerpoCuboR.setPosition(x, y);


}


cuboR::~cuboR()
{
    //dtor
}
