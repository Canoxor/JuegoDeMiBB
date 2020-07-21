#ifndef INTERFAZJUG_H
#define INTERFAZJUG_H


#include <SFML/Graphics.hpp>
using namespace sf;

#include "Jugador.h"

class InterfazJug
{

        private:
            float posX;
            float posY;
            /// corazones
            Texture moldeVida;
            Sprite cuerpoVida;
            ///personajes(decoracion)
            Texture moldePj;
            Sprite cuerpoPj;

    public:
        InterfazJug();
        virtual ~InterfazJug();

          Sprite getSprite()
    {
        return cuerpoVida;
    }

        void setPos(float , float , int );

//        void InterfazJug::cambioVida(int);

        float getPosX(){return posX;}
        float getPosY(){return posY;}


};

#endif // INTERFAZJUG_H
