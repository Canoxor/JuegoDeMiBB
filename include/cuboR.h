#ifndef CUBOR_H
#define CUBOR_H

#include <SFML/Graphics.hpp>
using namespace sf;

class cuboR
{

    private:

    float posX;
    float posY;
    Texture moldeCuboR;
    Sprite cuerpoCuboR;
    bool estado=false;


    public:
        cuboR();
        cuboR(float,float);


        Sprite getSprite()
    {
        return cuerpoCuboR;
    }


        virtual ~cuboR();


        void setPos(float x , float y);
        void setEstado(bool newState){estado=newState;}
        float getPosX(){return posX;}
        float getPosY(){return posY;}
        bool getEstado(){return estado;}


};


#endif // CUBOR_H
