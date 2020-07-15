#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;

void FuncionJuego(){

 sf::RenderWindow window(sf::VideoMode(1260, 660), "DESTROY_IT");


    sf::Texture mapita;

    if(!mapita.loadFromFile("imagen/mapita.png"))
    {
        ///Si hay un error salimos
        exit(1);
    }
    ///MAPA
    sf::Sprite mapa;
    mapa.setTexture(mapita);

    ///POSICIONES DEL CENTRO
    float VecX[13]={0};
    float VecY[9]={0};
    CargarPosiciones(VecX,VecY);

    ///JUGADOR1
    Jugador jug1(60, 60, 1);
    int danio;
    ///JUGADOR2
    Jugador jug2(780, 540, 0);
    /// VECTOR JUGADORES
    int SpawnBombas[2][2]={0};

    /// ///BOMBA
    bomba bomba_j1; /// ESTA BOMBA sirve para el j1
    bomba bomba_j2;/// ESTA BOMBA sirve para el j2
    float PosicionAreaX[2]={0};
    float PosicionAreaY[2]={0};
    bool Danio;
    int restante=0;


    ///CUBO
    int x=0;
    int y=0;
    float xc=120;
    float yc=120;
    cubo vcubos[4][6];

    for(y=1; y<5; y++){
        for(x=1; x<7; x++){
        vcubos[y-1][x-1].setPos((float)xc*x, (float) yc*y);
        }
    }

    ///fin dibujo cubos

    float variable;
    float tiempo1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

/// ///////////////////  TECLADO  JUGADOR 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /// ABAJO
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
            {
                jug1.moverAbajo(jug1.getX(),jug1.getY(), jug1.getVelocidad());
            }
        }
        /// ARRIBA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
            {
                jug1.moverArriba(jug1.getX(),jug1.getY(), jug1.getVelocidad());
            }
        }
        ///IZQUIERDA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
            {

                jug1.moverIzquierda(jug1.getX(),jug1.getY(), jug1.getVelocidad());
            }
        }
        ///DERECHA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
            {

                jug1.moverDerecha(jug1.getX(),jug1.getY(), jug1.getVelocidad());
            }
        }
/// ////////////////// BOMBA JUGADOR 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
        {
            if(bomba_j1.getmostrar()==false)
            {
                VerificarPosicion(SpawnBombas,jug1.getX(),jug1.getY(),VecX,VecY);
                bomba_j1.Aparecer(VecX[SpawnBombas[0][0]]-29.5,VecY[SpawnBombas[1][0]]-29.5);
                bomba_j1.setmostrar(true);
                bomba_j1.setTiempo1();

            }
        }

        if(bomba_j1.getTiempo1()>=2)
        {
           // bomba_j1.Explota();


        }

        if(bomba_j1.getTiempo1()>=4){
        bomba_j1.setmostrar(false);
      //  bomba_j1.ExplotaFin();
        bomba_j1.setTiempo1();
        }

/// ///////////////////COLISION JUGADOR 1 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///COLISION ABAJO
        if(jug1.getSprite().getPosition().y+60 > 600)
        {
            jug1.setY(540);
        }
        ///COLISION ARRIBA
        if(jug1.getSprite().getPosition().y+60 <(60+61)+1)
        {
            jug1.setY(60+1);
        }

        ///COLISION ANCHO DERECHA
        if(jug1.getSprite().getPosition().x+60 > 840)
        {
            jug1.setX(780);
        }
        ///COLISION ANCHO IZQUIERDA
        if(jug1.getSprite().getPosition().x+60 < 121)
        {
            jug1.setX(61);
        }


        // COLISION CON CUBOS




/// ///////////////////  TECLADO  JUGADOR 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        /// ABAJO
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
            {
                jug2.moverAbajo(jug2.getX(),jug2.getY(), jug2.getVelocidad());
            }
        }
        /// ARRIBA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
            {
                jug2.moverArriba(jug2.getX(),jug2.getY(), jug2.getVelocidad());
            }
        }
        ///IZQUIERDA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
            {

                jug2.moverIzquierda(jug2.getX(),jug2.getY(), jug2.getVelocidad());
            }
        }
        ///DERECHA
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ||  (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ))
        {
        }
        else
        {
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
            {
                jug2.moverDerecha(jug2.getX(),jug2.getY(), jug2.getVelocidad());
            }
        }

/// ////////////////// BOMBA JUGADOR 2 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
        {
            if(bomba_j2.getmostrar2()==false)
            {
                VerificarPosicion(SpawnBombas,jug2.getX(),jug2.getY(),VecX,VecY);
                bomba_j2.Aparecer(VecX[SpawnBombas[0][1]]-29.5,VecY[SpawnBombas[1][1]]-29.5);
                bomba_j2.setmostrar2(true);
                bomba_j2.setTiempo2();
            }
        }
        if(bomba_j2.getTiempo2()>=2)
        {
            bomba_j2.setmostrar2(false);
            bomba_j2.setTiempo2();
        }

/// ///////////////////COLISION JUGADOR 2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///COLISION ABAJO
        if(jug2.getSprite().getPosition().y+60 > 600)
        {
            jug2.setY(540);
        }
        ///COLISION ARRIBA
        if(jug2.getSprite().getPosition().y+60 <(60+61)+1)
        {
            jug2.setY(60+1);
        }

        ///COLISION ANCHO DERECHA
        if(jug2.getSprite().getPosition().x+60 > 840)
        {
            jug2.setX(780);
        }
        ///COLISION ANCHO IZQUIERDA
        if(jug2.getSprite().getPosition().x+60 < 121)
        {
            jug2.setX(61);
        }

/// /////////////////////////////////// PROBANDO COSAS /////////////////////////////////////////////////////////////////////////////////////////////

        ///INTENTO DE COLISIONES

        if(jug1.getSprite().getGlobalBounds().intersects(jug2.getSprite().getGlobalBounds()))
        {
            jug1.setX(60);
            jug1.setY(60);
        }


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///muestran el tiempo
        tiempo1=bomba_j1.getTiempo1();
        cout<<tiempo1<<endl;
        cout<<endl;

        variable=bomba_j2.getTiempo2();


/// /////////////////////////////////////////////////////////////////////


        ///Borra

        window.clear();
        ///Dibuja

        window.draw(mapa);
        ///jugador 2
        if(bomba_j2.getmostrar2()==true)
        {
            window.draw(bomba_j2.getSpriteBomba());
        }
        ///jugador 1
        if(bomba_j1.getmostrar()==true)
        {
            window.draw(bomba_j1.getSpriteBomba());

        }




        ///dibuja los 24 cubos
        for( y=1; y<5; y++){
        for( x=1; x<7; x++){
            window.draw(vcubos[y-1][x-1].getSprite());
        }
        }
        window.draw(jug1.getSprite());
        window.draw(jug2.getSprite());
        window.display();
    }


}


#endif // JUEGO_H_INCLUDED
