#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED


class Partida
{
private:

    int Ganador;
    int Estado = 0;
    Clock reloj;
    Time tiempo;

public:
    Partida()
    {
        tiempo=reloj.getElapsedTime();
    }
    /// SETTERS
    void SetGanador(int Winner)
    {
        Ganador = Winner;
    }
    void SetEstado(int E)
    {
        Estado = E;
    }
    void setTiempo()
    {
        reloj.restart();
    }

    /// GETTERS
    int GetGanador()
    {
        return Ganador;
    }
    int GetEstado()
    {
        return Estado;
    }
    float getTiempo()
    {
        tiempo= reloj.getElapsedTime();
        return tiempo.asSeconds();
    }
};

#endif // PARTIDA_H_INCLUDED
