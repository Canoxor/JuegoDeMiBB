#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>

using namespace sf;
#include "bomba.h"


class Jugador
{
     private:

    protected:

        float posX;
        float posY;
        int vida=3;
        float velocidad= 1.f;
        Texture molde;
        Sprite cuerpo;


    public: ///METODOS

        Jugador(float a, float b, int c);

        virtual ~Jugador();

        Sprite getSprite(){return cuerpo;}

        void moverDerecha(float,float, float);
        void moverIzquierda(float,float, float);
        void moverArriba(float , float, float);
        void moverAbajo(float, float, float);
        //void agarrarItem();


        ///GET
        float getX(){return posX;}
        float getY(){return posY;}
        float getVelocidad(){return velocidad;}
        int GetVida(){return vida;}


        ///SET
        void setX(float valorX){posX=valorX;}
        void setY(float valorY){posY=valorY;}
        void setVelocidad(float valorV){velocidad=valorV;}
        void setVida(int vidaNueva){vida=vidaNueva;}

};








#endif // JUGADOR_H
