#ifndef BOMBA_H
#define BOMBA_H

#include <SFML/Graphics.hpp>

using namespace sf;

class bomba
{
private:

protected:
    int danio=1;
    float posX;
    float posY;
    Texture moldebomba;
    Sprite cuerpobomba;
    ///personaje1
    Clock reloj1;
    Time tiempo1;

    ///personaje 2
    Clock reloj2;
    Time tiempo2;

    bool mostrar=false;
    bool mostrar2=false;

public:
    ///METODOS
    bomba();
    virtual ~bomba();

    ///DANIO
    bool hacerDanio();
    void AreaDelDanio( );

    ///APARECER BOMBA
    void Aparecer(float,float);
    void despawn();

    ///GETS
    Sprite getSpriteBomba(){return cuerpobomba;}
    float getTiempo1();
    bool getmostrar(){return mostrar;}
    bool getmostrar2(){return mostrar2;}
    float getTiempo2();
    int getDanio(){return danio;}


    ///SETS
    void setTiempo1();
    void setTiempo2();
    void setDanio(int d){danio=d;}
    void setmostrar(bool mos){mostrar=mos;}
    void setmostrar2(bool mos){mostrar2=mos;}




};

#endif // BOMBA_H
