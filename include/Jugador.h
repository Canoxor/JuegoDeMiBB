#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>

using namespace sf;
#include "bomba.h"
#include "InterfazJug.h"

class Jugador
{


protected:

    float posX;
    float posY;
    int vida=3;
    float velocidad= 1.f;
    int DireccionX;
    int DireccionY;

    /// SOLUCION BUGG SPRITE
    Texture I_Pause_J2;

    /// Sprites Quito
    Sprite K_Quieto;

    /// Sprites Derecha
    Sprite D_Pie_Derecho_1, D_Pie_Derecho_2, D_Pie_Izquierdo_1, D_Pie_Izquierdo_2, D_Pausa;

    /// Sprites Izquierda
    Sprite I_Pie_Derecho_1, I_Pie_Derecho_2, I_Pie_Izquierdo_1, I_Pie_Izquierdo_2, I_Pausa;

    /// Sprites Arriba
    Sprite AR_Pie_Derecho_1, AR_Pie_Derecho_2, AR_Pie_Izquierdo_1, AR_Pie_Izquierdo_2, AR_Pausa;

    /// Sprites Abajo
    Sprite AB_Pie_Derecho_1, AB_Pie_Derecho_2, AB_Pie_Izquierdo_1, AB_Pie_Izquierdo_2, AB_Pausa;

    /// Orientacion tomada
    int Orientacion = 0; /// (0 = Quieto) (1 = Arriba) (2 = Derecha) (3 = Abajo) (4 = Izquierda)

    /// Estado de la animacion
    int Estado_Animacion_Arriba = 0;
    int Estado_Animacion_Derecha = 0;
    int Estado_Animacion_Abajo = 0;
    int Estado_Animacion_Izquierda = 0;

    /// Delay por animacion
    int DelaySprites_Arriba = 0;
    int DelaySprites_Derecha = 0;
    int DelaySprites_Abajo = 0;
    int DelaySprites_Izquierda = 0;

    /// Velocidad de la animacion
    int DelayMax = 25;

    Clock reloj;
    Time tiempo;

    InterfazJug screenJug;

public: ///METODOS

    Jugador(float a, float b, int c);

    virtual ~Jugador();

    void Quieto()
    {
        Orientacion = 0;
        Estado_Animacion_Abajo = 0;
        Estado_Animacion_Arriba = 0;
        Estado_Animacion_Derecha = 0;
        Estado_Animacion_Izquierda = 0;
    }

    void setSprites_Arriba(Texture &Pausa,Texture &Derecha_1,Texture &Derecha_2,Texture &Izquierda_1,Texture &Izquierda_2)
    {
        /// Se cargan los sprites para el jugador
        AR_Pausa.setTexture(Pausa);
        AR_Pie_Derecho_1.setTexture(Derecha_1);
        AR_Pie_Derecho_2.setTexture(Derecha_2);
        AR_Pie_Izquierdo_1.setTexture(Izquierda_1);
        AR_Pie_Izquierdo_2.setTexture(Izquierda_2);
    }

    void setSprites_Derecha(Texture &Pausa,Texture &Derecha_1,Texture &Derecha_2,Texture &Izquierda_1,Texture &Izquierda_2)
    {
        D_Pausa.setTexture(Pausa);
        D_Pie_Derecho_1.setTexture(Derecha_1);
        D_Pie_Derecho_2.setTexture(Derecha_2);
        D_Pie_Izquierdo_1.setTexture(Izquierda_1);
        D_Pie_Izquierdo_2.setTexture(Izquierda_2);
    }

    void setSprites_Abajo(Texture &Pausa,Texture &Derecha_1,Texture &Derecha_2,Texture &Izquierda_1,Texture &Izquierda_2)
    {
        AB_Pausa.setTexture(Pausa);
        AB_Pie_Derecho_1.setTexture(Derecha_1);
        AB_Pie_Derecho_2.setTexture(Derecha_2);
        AB_Pie_Izquierdo_1.setTexture(Izquierda_1);
        AB_Pie_Izquierdo_2.setTexture(Izquierda_2);
    }

    void setSprites_Izquierda(int J, Texture &Pausa,Texture &Derecha_1,Texture &Derecha_2,Texture &Izquierda_1,Texture &Izquierda_2)
    {
        if(J==1)
        {
            if(!I_Pause_J2.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pausa.png"))
            {
                exit(123123);
            }
            I_Pausa.setTexture(I_Pause_J2);
            /*
            I_Pausa.setTexture(Pausa);
            I_Pausa.setColor(Color(100,100,100));
            */
        }
        else
        {
            I_Pausa.setTexture(Pausa);
        }
        I_Pie_Derecho_1.setTexture(Derecha_1);
        I_Pie_Derecho_2.setTexture(Derecha_2);
        I_Pie_Izquierdo_1.setTexture(Izquierda_1);
        I_Pie_Izquierdo_2.setTexture(Izquierda_2);
    }

    void setSprites_Quieto(Texture &Quieto)
    {
        K_Quieto.setTexture(Quieto);
    }

    Sprite getSprite()
    {
        switch(Orientacion)
        {
        case 0: /// Quieto
            return K_Quieto;
            break;
        case 1: /// Arriba
            switch(Estado_Animacion_Arriba)
            {
            case 0:
                return AR_Pie_Derecho_1;
                break;
            case 1:
                return AR_Pie_Derecho_2;
                break;
            case 2:
                return AR_Pausa;
                break;
            case 3:
                return AR_Pie_Izquierdo_1;
                break;
            case 4:
                return AR_Pie_Izquierdo_2;
                break;
            case 5:
                return AR_Pausa;
                break;
            }
            break;
        case 2: /// Derecha
            switch(Estado_Animacion_Derecha)
            {
            case 0:
                return D_Pie_Derecho_1;
                break;
            case 1:
                return D_Pie_Derecho_2;
                break;
            case 2:
                return D_Pausa;
                break;
            case 3:
                return D_Pie_Izquierdo_1;
                break;
            case 4:
                return D_Pie_Izquierdo_2;
                break;
            case 5:
                return D_Pausa;
                break;
            }
            break;
        case 3: /// Abajo
            switch(Estado_Animacion_Abajo)
            {
            case 0:
                return AB_Pie_Derecho_1;
                break;
            case 1:
                return AB_Pie_Derecho_2;
                break;
            case 2:
                return AB_Pausa;
                break;
            case 3:
                return AB_Pie_Izquierdo_1;
                break;
            case 4:
                return AB_Pie_Izquierdo_2;
                break;
            case 5:
                return AB_Pausa;
                break;
            }
            break;
        case 4: /// Izquierda
            switch(Estado_Animacion_Izquierda)
            {
            case 0:
                return I_Pie_Derecho_1;
                break;
            case 1:
                return I_Pie_Derecho_2;
                break;
            case 2:
                return I_Pausa;
                break;
            case 3:
                return I_Pie_Izquierdo_1;
                break;
            case 4:
                return I_Pie_Izquierdo_2;
                break;
            case 5:
                return I_Pausa;
                break;
            }
            break;
        }
    }

    void MoverSprites()
    {
        K_Quieto.setPosition(posX,posY);

        AR_Pausa.setPosition(posX,posY);
        AR_Pie_Derecho_1.setPosition(posX,posY);
        AR_Pie_Derecho_2.setPosition(posX,posY);
        AR_Pie_Izquierdo_1.setPosition(posX,posY);
        AR_Pie_Izquierdo_2.setPosition(posX,posY);

        D_Pausa.setPosition(posX,posY);
        D_Pie_Derecho_1.setPosition(posX,posY);
        D_Pie_Derecho_2.setPosition(posX,posY);
        D_Pie_Izquierdo_1.setPosition(posX,posY);
        D_Pie_Izquierdo_2.setPosition(posX,posY);

        AB_Pausa.setPosition(posX,posY);
        AB_Pie_Derecho_1.setPosition(posX,posY);
        AB_Pie_Derecho_2.setPosition(posX,posY);
        AB_Pie_Izquierdo_1.setPosition(posX,posY);
        AB_Pie_Izquierdo_2.setPosition(posX,posY);

        I_Pausa.setPosition(posX,posY);
        I_Pie_Derecho_1.setPosition(posX,posY);
        I_Pie_Derecho_2.setPosition(posX,posY);
        I_Pie_Izquierdo_1.setPosition(posX,posY);
        I_Pie_Izquierdo_2.setPosition(posX,posY);
    }

    void Reset(float x,float y)
    {
        posX = x;
        posY = y;
        vida = 3;
        MoverSprites();
        velocidad = 1.f;
        reloj.restart();
    }

    void setPos(float, float);
    void moverDerecha(float,float, float);
    void moverIzquierda(float,float, float);
    void moverArriba(float, float, float);
    void moverAbajo(float, float, float);

    float getTiempo()
    {
        tiempo= reloj.getElapsedTime();
        return tiempo.asSeconds();
    }

    void setTiempo()
    {
        reloj.restart();
    }

    void Daniar()
    {
        vida = vida - 1;
    }
    //void agarrarItem();


    ///GET
    float getX()
    {
        return posX;
    }
    float getY()
    {
        return posY;
    }
    float getVelocidad()
    {
        return velocidad;
    }
    int GetVida()
    {
        return vida;
    }
    int getDirX()
    {
        return DireccionX;
    }
    int getDirY()
    {
        return DireccionY;
    }

    InterfazJug getScreenJug()
    {
        return screenJug;
    }


    ///SET
    void setX(float valorX)
    {
        posX=valorX;   // CREO QUE NO SE USA
    }
    void setY(float valorY)
    {
        posY=valorY;   // CREO QUE NO SE USA
    }
    void setVelocidad(float valorV)
    {
        velocidad=valorV;
    }
    void setVida(int vidaNueva)
    {
        vida=vidaNueva;
    }

    void setDirX(int dirX)
    {
        DireccionX=dirX;
    }
    void setDirY(int dirY)
    {
        DireccionY=dirY;
    }

    void setScreenJug(float, float, int);
};

#endif // JUGADOR_H
