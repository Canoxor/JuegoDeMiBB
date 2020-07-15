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
    bomba aux1; /// ESTA BOMBA sirve para el j1
    bomba aux2;/// ESTA BOMBA sirve para el j2
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
                jug1.setDirY(1);
                jug1.setDirX(0);
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
                jug1.setDirY(-1);
                jug1.setDirX(0);
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
                jug1.setDirY(0);
                jug1.setDirX(-1);
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
                jug1.setDirY(0);
                jug1.setDirX(1);
            }
        }
/// ////////////////// BOMBA JUGADOR 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
        {
            if(aux1.getmostrar()==false)
            {
                VerificarPosicion(SpawnBombas,jug1.getX(),jug1.getY(),VecX,VecY);
                aux1.Aparecer(VecX[SpawnBombas[0][0]]-29.5,VecY[SpawnBombas[1][0]]-29.5);
                aux1.setmostrar(true);
                aux1.setTiempo1();
            }
        }
        if(aux1.getTiempo1()>=2)
        {
            aux1.setmostrar(false);
            aux1.setTiempo1();
        }

/// ///////////////////COLISION JUGADOR 1 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///COLISION ABAJO
        if(jug1.getSprite().getPosition().y+59 > 600)
        {
            jug1.setY(540);
        }

        ///COLISION ARRIBA
        if(jug1.getSprite().getPosition().y < 60)
        {
            jug1.setY(60);
        }


        ///COLISION ANCHO DERECHA
        if(jug1.getSprite().getPosition().x+60 > 840)
        {
            jug1.setX(780);
        }

        ///COLISION ANCHO IZQUIERDA
        if(jug1.getSprite().getPosition().x < 60)
        {
            jug1.setX(60);
        }


        /// COLISION CON CUBOS POR PIXELES


        for( y=0; y<4; y++){
            for( x=0; x<6; x++){


        if(Collision::PixelPerfectTest(jug1.getSprite(), vcubos[y][x].getSprite())){



                            switch(jug1.getDirX()){

                            case 1:
                                jug1.setX(jug1.getSprite().getPosition().x-1);
                                jug1.setY(jug1.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug1.setX(jug1.getSprite().getPosition().x+1);
                                jug1.setY(jug1.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;
                            }

                            switch(jug1.getDirY()){

                            case 1:
                                jug1.setX(jug1.getSprite().getPosition().x);
                                jug1.setY(jug1.getSprite().getPosition().y-1);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug1.setX(jug1.getSprite().getPosition().x);
                                jug1.setY(jug1.getSprite().getPosition().y+1);
                                cout<< "colision" <<endl;
                                break;
                            }

            }
        else{
                cout<< "No colision"<< endl;
            }

        }
 }


                /// COLISION CON CUBOS POR HITBOX CUADRADA (NO BORRAR POR LAS DUDAS)


 /*

        for( y=0; y<4; y++){
            for( x=0; x<6; x++){


        if(jug1.getSprite().getGlobalBounds().intersects(vcubos[y][x].getSprite().getGlobalBounds())){



                            switch(jug1.getDirX()){

                            case 1:
                                jug1.setX(jug1.getSprite().getPosition().x-1);
                                jug1.setY(jug1.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug1.setX(jug1.getSprite().getPosition().x+1);
                                jug1.setY(jug1.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;
                            }

                            switch(jug1.getDirY()){

                            case 1:
                                jug1.setX(jug1.getSprite().getPosition().x);
                                jug1.setY(jug1.getSprite().getPosition().y-1);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug1.setX(jug1.getSprite().getPosition().x);
                                jug1.setY(jug1.getSprite().getPosition().y+1);
                                cout<< "colision" <<endl;
                                break;
                            }

            }
        else{
                cout<< "No colision"<< endl;
            }

        }
 }


 */




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
                jug2.setDirY(1);
                jug2.setDirX(0);
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
                jug2.setDirY(-1);
                jug2.setDirX(0);
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
                jug2.setDirY(0);
                jug2.setDirX(-1);
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
                jug2.setDirY(0);
                jug2.setDirX(1);
            }
        }

/// ////////////////// BOMBA JUGADOR 2 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
        {
            if(aux2.getmostrar2()==false)
            {
                VerificarPosicion(SpawnBombas,jug2.getX(),jug2.getY(),VecX,VecY);
                aux2.Aparecer(VecX[SpawnBombas[0][1]]-29.5,VecY[SpawnBombas[1][1]]-29.5);
                aux2.setmostrar2(true);
                aux2.setTiempo2();
            }
        }
        if(aux2.getTiempo2()>=2)
        {
            aux2.setmostrar2(false);
            aux2.setTiempo2();
        }

/// ///////////////////COLISION JUGADOR 2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///COLISION ABAJO
        if(jug2.getSprite().getPosition().y+59 > 600)
        {
            jug2.setY(540);
        }

        ///COLISION ARRIBA
        if(jug2.getSprite().getPosition().y < 60)
        {
            jug2.setY(60);
        }



        ///COLISION ANCHO DERECHA
        if(jug2.getSprite().getPosition().x+59 > 840)
        {
            jug2.setX(780);
        }


        ///COLISION ANCHO IZQUIERDA
        if(jug2.getSprite().getPosition().x < 60)
        {
            jug2.setX(60);
        }



        // COLISIONES BLOQUES

        for( y=0; y<4; y++){
            for( x=0; x<6; x++){


        if(Collision::PixelPerfectTest(jug2.getSprite(), vcubos[y][x].getSprite())){



                            switch(jug2.getDirX()){

                            case 1:
                                jug2.setX(jug2.getSprite().getPosition().x-1);
                                jug2.setY(jug2.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug2.setX(jug2.getSprite().getPosition().x+1);
                                jug2.setY(jug2.getSprite().getPosition().y);
                                cout<< "colision" <<endl;
                                break;
                            }

                            switch(jug2.getDirY()){

                            case 1:
                                jug2.setX(jug2.getSprite().getPosition().x);
                                jug2.setY(jug2.getSprite().getPosition().y-1);
                                cout<< "colision" <<endl;
                                break;

                            case -1:
                                jug2.setX(jug2.getSprite().getPosition().x);
                                jug2.setY(jug2.getSprite().getPosition().y+1);
                                cout<< "colision" <<endl;
                                break;
                            }

            }
        else{
                cout<< "No colision"<< endl;
            }

        }
 }


/// /////////////////////////////////// PROBANDO COSAS /////////////////////////////////////////////////////////////////////////////////////////////

        ///INTENTO DE COLISIONES
/*
        if(jug1.getSprite().getGlobalBounds().intersects(jug2.getSprite().getGlobalBounds()))
        {
            jug1.setX(72);
            jug1.setY(72);
        }
*/

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///muestran el tiempo
        tiempo1=aux1.getTiempo1();
        cout<<tiempo1<<endl;
        cout<<endl;

        variable=aux2.getTiempo2();


/// /////////////////////////////////////////////////////////////////////


        ///Borra

        window.clear();
        ///Dibuja

        window.draw(mapa);
        if(aux2.getmostrar2()==true)
        {
            window.draw(aux2.getSpriteBomba());
        }
        if(aux1.getmostrar()==true)
        {
            window.draw(aux1.getSpriteBomba());
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
