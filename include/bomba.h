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
    Sprite BombaNormal, BombaExplotando_lvl_1;
    Clock reloj;
    Time tiempo;

    int Estado=0; /// (0 = Normal) - (1 = Explotando lvl 1) - (2 = Explotando lvl 2) - (3 = Explotando lvl 3)

    bool mostrar=false;

public:
    ///METODOS
    bomba(Texture&,Texture&);
    virtual ~bomba();

    ///APARECER BOMBA
    void Aparecer(float,float);
    void despawn();

    ///GETS
    int getEstado()
    {
        return Estado;
    }

    Sprite getSpriteBomba()
    {
        switch(Estado)
        {
        case 0:
            return BombaNormal;
            break;
        case 1:
            BombaExplotando_lvl_1.setPosition(posX-60,posY-60);
            return BombaExplotando_lvl_1;
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }

    float getTiempo();

    bool getmostrar()
    {
        return mostrar;
    }

    int getDanio()
    {
        return danio;
    }

    ///SETS
    void setEstado(int Numero)
    {
        Estado = Numero;
    }

    void setTiempo();

    void setDanio(int d)
    {
        danio=d;
    }

    void setmostrar(bool mos)
    {
        mostrar=mos;
    }
};

#endif // BOMBA_H
