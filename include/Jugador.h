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
        int DireccionX;
        int DireccionY;
        Texture molde;
        Sprite cuerpo;



    public: ///METODOS
        Jugador();
        Jugador(float a, float b, int c);

        virtual ~Jugador();

        Sprite getSprite(){return cuerpo;}

        void setPos(float, float);
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
        int getDirX(){return DireccionX;}
        int getDirY(){return DireccionY;}


        ///SET
        void setX(float valorX){posX=valorX;} // CREO QUE NO SE USA
        void setY(float valorY){posY=valorY;} // CREO QUE NO SE USA
        void setVelocidad(float valorV){velocidad=valorV;}
        void setVida(int vidaNueva){vida=vidaNueva;}

        void setDirX(int dirX){DireccionX=dirX;}
        void setDirY(int dirY){DireccionY=dirY;}

};








#endif // JUGADOR_H
