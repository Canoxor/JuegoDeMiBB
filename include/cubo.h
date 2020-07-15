#ifndef CUBO_H
#define CUBO_H
#include <SFML/Graphics.hpp>
using namespace sf;
class cubo
{

private:
    float posX;
    float posY;
    Texture moldeCubo;
    Sprite cuerpoCubo;
    float vecX[13]={0}; //NO SE USA?
    float vecY[8]={0};  //NO SE USA?



public: ///METODOS

    cubo();
    cubo(float,float);

    Sprite getSprite()
    {
        return cuerpoCubo;
    }
    virtual ~cubo();

    float cargarPosX();
    float cargarPosY();
    void setPos(float x , float y);
    float getPosX(){return posX;}
    float getPosY(){return posY;}



};









#endif // CUBO_H
