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

    Texture MoldeBombaExplota;








    ///personaje1
    Clock reloj1;
    Time tiempo1;

    ///personaje 2
    Clock reloj2;
    Time tiempo2;

    bool mostrar=false;
    bool mostrar2=false;


    bool explotar=false;


public:
    ///METODOS
    bomba();
    virtual ~bomba();

    ///DANIO
    void hacerDanio(float,float,float*,float*);
    void AreaDelDanio( );

    ///APARECER BOMBA
    void Aparecer(float,float);
    void despawn();


    /// EXPLOTAR
    void Explota();
    void ExplotaFin();



    ///GETS
    Sprite getSpriteBomba(){return cuerpobomba;}

    float getTiempo1();
    bool getmostrar(){return mostrar;}
    bool getmostrar2(){return mostrar2;}
    float getTiempo2();
    int getDanio(){return danio;}

    bool getExplotar(){return explotar;}


    ///SETS
    void setTiempo1();
    void setTiempo2();
    void setDanio(int d){danio=d;}
    void setmostrar(bool mos){mostrar=mos;}
    void setmostrar2(bool mos){mostrar2=mos;}
    void setPosiciones(float*,float*);





};

#endif // BOMBA_H
