#ifndef SONIDO_H_INCLUDED
#define SONIDO_H_INCLUDED

class Musica
{
private:
    Music musica;
    int v_defecto,volume;
    bool Encendida;
public:
    Musica();

    Musica(const string & ruta)
    {
        if (!musica.openFromFile(ruta))
            exit(689);

        v_defecto=100;
        musica.setVolume(v_defecto);
        volume=v_defecto;
    }

    void setMusica(string ruta)
    {
        if (!musica.openFromFile(ruta))
            exit(689);

        v_defecto=10;
        musica.setVolume(v_defecto);
        volume=v_defecto;
    }

    Music & getMusica()
    {
        return musica;
    }
    int getVolumen()
    {
        return volume;
    }
    void volumen (float v)
    {
        if (v>=0&&v<=100)
        {
            musica.setVolume(v);
            volume=v;
        }
    }
    void volumen()
    {
        musica.setVolume(v_defecto);
    }
    void repeticion(bool eleccion)
    {
        musica.setLoop(eleccion);
    }
    void reproducir()
    {
        musica.play();
        Encendida = true;
    }
    void pausar ()
    {
        musica.pause();
    }
    void parar()
    {
        musica.stop();
        Encendida = false;
    }

    bool getEncendida()
    {
        return Encendida;
    }
};


class FX
{
private:
    SoundBuffer buffer;
    Sound sonido;
    int tiempo_delay,volumen;
    bool mute;
public:
    FX (const string &ruta_buffer,int tiempo_d=0)
    {
        buffer.loadFromFile(ruta_buffer);
        sonido.setBuffer(buffer);
        tiempo_delay=tiempo_d;
        volumen=15;
        sonido.setVolume(volumen);
    }
    void cambiar_buffer(const string &ruta_buffer)
    {
        buffer.loadFromFile(ruta_buffer);
        sonido.setBuffer(buffer);
    }
    void cambiar_volumen(int v_volumen)
    {
        volumen=v_volumen;
        sonido.setVolume(volumen);
    }
    void cambiar_delay(int tiempo_d)
    {
        tiempo_delay=tiempo_d;
    }
    void mutear(bool valor)
    {
        mute=valor;
    }
    void encender()
    {
        if (!mute)
        {
            if (tiempo_delay==0)
                sonido.play();
            else if (sonido.getPlayingOffset().asMilliseconds()>tiempo_delay||sonido.getPlayingOffset().asSeconds()==0)
                sonido.play();
        }
    }
};

#endif // SONIDO_H_INCLUDED
