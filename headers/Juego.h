#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace Collision;

void FuncionJuego()
{

    RenderWindow window(VideoMode(1260, 660), "DESTROY_IT");

    Clock relojfps;
    Time tiempo;
    int fps=60;

    /// Partida
    Partida game;
    game.setTiempo();

    /// Menu
    Texture MenuPrincipal;
    if(!MenuPrincipal.loadFromFile("imagen/Pantalla/Principal.png"))
    {
        ///Si hay un error salimos
        exit(11);
    }
    Sprite MenuPrincipal_S;
    MenuPrincipal_S.setTexture(MenuPrincipal);

    /// Victoria
    Texture Victoria;
    if(!Victoria.loadFromFile("imagen/Pantalla/Pantalla_Fin.jpg"))
    {
        ///Si hay un error salimos
        exit(12);
    }
    Sprite Victoria_S;
    Victoria_S.setTexture(Victoria);

    /// MAPA
    Texture mapita;
    if(!mapita.loadFromFile("imagen/Pantalla/mapita.png"))
    {
        ///Si hay un error salimos
        exit(13);
    }
    Sprite mapa;
    mapa.setTexture(mapita);
///JUGADORES /////////////////////////////////////////////////////////////////
    ///JUGADOR1
    Jugador Jugador_1(60, 60, 1);
    int danio;
    ///JUGADOR2
    Jugador Jugador_2(780, 540, 0);
    /// VECTOR JUGADORES
    int SpawnBombas[2][2]= {0};

/// /////BOMBA /////////////////////////////////////////////////////////////////
    ///POSICIONES DEL CENTRO BOMBAS
    float VecX[13]= {0};
    float VecY[9]= {0};
    CargarPosiciones(VecX,VecY);

    /// Sprites para las bombas
    Texture Bomba_Roja_T, Bomba_Azul_T;

    if(!Bomba_Roja_T.loadFromFile("imagen/Bombas/Bomba_Roja_SinTransp.png"))
    {
        ///Si hay un error salimos
        exit(1);
    }
    if(!Bomba_Azul_T.loadFromFile("imagen/Bombas/Bomba_Azul_SinTransp.png"))
    {
        ///Si hay un error salimos
        exit(1);
    }

    /// Sprites de las bombas explotando
    Texture Explosion_1_T, Explosion_2_T, Explosion_3_T;

    if(!Explosion_1_T.loadFromFile("imagen/Bombas/Explocion_1.png"))
    {
        ///Si hay un error salimos
        exit(1);
    }

    bomba Bomba_J1(Bomba_Roja_T,Explosion_1_T);
    bomba Bomba_J2(Bomba_Azul_T,Explosion_1_T);
    float PosicionAreaX[2]= {0};
    float PosicionAreaY[2]= {0};
    bool Danio;
    int restante=0;

    ///CUBO
    int x=0;
    int y=0;
    float xc=120;
    float yc=120;
    cubo vcubos[4][6];

    for(y=1; y<5; y++)
    {
        for(x=1; x<7; x++)
        {
            vcubos[y-1][x-1].setPos((float)xc*x, (float) yc*y);
        }
    }

    ///CUBO R

    xc=60;
    yc=60;
    cuboR vcuboR[9][13];

    for(y=1; y<10; y++)
    {
        for(x=1; x<14; x++)
        {
            vcuboR[y-1][x-1].setPos((float)xc*x, (float) yc*y);
        }
    }
    vcuboR[0][0].setPos(120, 120);  ///estos se setean aparte para que no le ocupen el spawn
    vcuboR[0][1].setPos(120, 120);
    vcuboR[1][0].setPos(120, 120);
    ///
    vcuboR[8][12].setPos(240, 240);
    vcuboR[7][12].setPos(240, 240);
    vcuboR[8][11].setPos(240, 240);


    ///fin dibujo cubos

    float variable;
    float tiempo1;

    while (window.isOpen())
    {
        tiempo=relojfps.getElapsedTime();//objetenmos tiempo transcurrido

        if(tiempo.asSeconds()>1/fps)///comparamos si el tiempo transcurrido supera 1 fps de ser así, ejecutamos un instante
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            switch(game.GetEstado())
            {
            case 0:
                /// ESTADO MENU
                //game.setTiempo();

                cout<<"TIEMPO DEL MENU"<<game.getTiempo()<<endl;
                ///Borra

                window.clear();

                window.draw(MenuPrincipal_S);

                if(game.getTiempo()>=3)
                {
                    game.SetEstado(1);
                }

                /// FIN DEL MENU
                break;

            case 1:
                /// ESTADO JUEGO

                ///TECLADO  JUGADOR 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                /// ABAJO
                if ((Keyboard::isKeyPressed(Keyboard::Down)&&(Keyboard::isKeyPressed(Keyboard::Left)) ||  (Keyboard::isKeyPressed(Keyboard::Right)) ))
                {

                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::Down)))
                    {
                        Jugador_1.moverAbajo(Jugador_1.getX(),Jugador_1.getY(), Jugador_1.getVelocidad());
                        Jugador_1.setDirY(1);
                        Jugador_1.setDirX(0);
                    }
                }
                /// ARRIBA
                if ((Keyboard::isKeyPressed(Keyboard::Up)&&(Keyboard::isKeyPressed(Keyboard::Left)) ||  (Keyboard::isKeyPressed(Keyboard::Right)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::Up)))
                    {
                        Jugador_1.moverArriba(Jugador_1.getX(),Jugador_1.getY(), Jugador_1.getVelocidad());
                        Jugador_1.setDirY(-1);
                        Jugador_1.setDirX(0);
                    }
                }
                ///IZQUIERDA
                if ((Keyboard::isKeyPressed(Keyboard::Left)&&(Keyboard::isKeyPressed(Keyboard::Up)) ||  (Keyboard::isKeyPressed(Keyboard::Down)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::Left)))
                    {

                        Jugador_1.moverIzquierda(Jugador_1.getX(),Jugador_1.getY(), Jugador_1.getVelocidad());
                        Jugador_1.setDirY(0);
                        Jugador_1.setDirX(-1);
                    }
                }
                ///DERECHA
                if ((Keyboard::isKeyPressed(Keyboard::Right)&&(Keyboard::isKeyPressed(Keyboard::Up)) ||  (Keyboard::isKeyPressed(Keyboard::Down)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::Right)))
                    {

                        Jugador_1.moverDerecha(Jugador_1.getX(),Jugador_1.getY(), Jugador_1.getVelocidad());
                        Jugador_1.setDirY(0);
                        Jugador_1.setDirX(1);
                    }
                }
/// ////////////////// BOMBA JUGADOR 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                if((Keyboard::isKeyPressed(Keyboard::Enter)))
                {
                    if(Bomba_J1.getmostrar()==false)
                    {
                        VerificarPosicion(SpawnBombas,Jugador_1.getX(),Jugador_1.getY(),VecX,VecY);
                        Bomba_J1.Aparecer(VecX[SpawnBombas[0][0]]-29.5,VecY[SpawnBombas[1][0]]-29.5);
                        Bomba_J1.setmostrar(true);
                        Bomba_J1.setTiempo();
                    }
                }
                if(Bomba_J1.getTiempo()>=2)
                {
                    Bomba_J1.setEstado(1);
                }
                if(Bomba_J1.getTiempo()>=4)
                {
                    Bomba_J1.setmostrar(false);
                    Bomba_J1.setTiempo();
                }

/// /////////////////// COLISION JUGADOR 1 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

                ///COLISION ABAJO
                if(Jugador_1.getSprite().getPosition().y+49 > 600)
                {
                    Jugador_1.setY(600-49);
                }

                ///COLISION ARRIBA
                if(Jugador_1.getSprite().getPosition().y < 60)
                {
                    Jugador_1.setY(60);
                }


                ///COLISION ANCHO DERECHA
                if(Jugador_1.getSprite().getPosition().x+39 > 840)
                {
                    Jugador_1.setX(840-39);
                }

                ///COLISION ANCHO IZQUIERDA
                if(Jugador_1.getSprite().getPosition().x < 60)
                {
                    Jugador_1.setX(60);
                }


                /// COLISION CON CUBOS POR PIXELES


                for( y=0; y<4; y++)
                {
                    for( x=0; x<6; x++)
                    {

                        if(PixelPerfectTest(Jugador_1.getSprite(), vcubos[y][x].getSprite()))
                        {



                            switch(Jugador_1.getDirX())
                            {

                            case 1:
                                Jugador_1.setX(Jugador_1.getSprite().getPosition().x-1);
                                Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                //cout<< "colision" <<endl;
                                break;

                            case -1:
                                Jugador_1.setX(Jugador_1.getSprite().getPosition().x+1);
                                Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                //cout<< "colision" <<endl;
                                break;
                            }

                            switch(Jugador_1.getDirY())
                            {
                            case 1:
                                Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                Jugador_1.setY(Jugador_1.getSprite().getPosition().y-1);
                                //cout<< "colision" <<endl;
                                break;

                            case -1:
                                Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                Jugador_1.setY(Jugador_1.getSprite().getPosition().y+1);
                                //cout<< "colision" <<endl;
                                break;
                            }

                        }
                        else
                        {
                            //cout<< "No colision"<< endl;
                        }

                    }
                }

                /// COLISION CON CUBOS POR HITBOX CUADRADA (NO BORRAR POR LAS DUDAS)


                /*

                       for( y=0; y<4; y++){
                           for( x=0; x<6; x++){


                       if(Jugador_1.getSprite().getGlobalBounds().intersects(vcubos[y][x].getSprite().getGlobalBounds())){



                                           switch(Jugador_1.getDirX()){

                                           case 1:
                                               Jugador_1.setX(Jugador_1.getSprite().getPosition().x-1);
                                               Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                               cout<< "colision" <<endl;
                                               break;

                                           case -1:
                                               Jugador_1.setX(Jugador_1.getSprite().getPosition().x+1);
                                               Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                               cout<< "colision" <<endl;
                                               break;
                                           }

                                           switch(Jugador_1.getDirY()){

                                           case 1:
                                               Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                               Jugador_1.setY(Jugador_1.getSprite().getPosition().y-1);
                                               cout<< "colision" <<endl;
                                               break;

                                           case -1:
                                               Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                               Jugador_1.setY(Jugador_1.getSprite().getPosition().y+1);
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


///=////////////////////////////////////////////////////// ROMPIBLES /////////////////////////////////////////////////////////////////////////


                for( y=0; y<9; y++)
                {
                    for( x=0; x<13; x++)
                    {

                        if(vcuboR[y][x].getEstado()==true)
                        {

                            if(Collision::PixelPerfectTest(Jugador_1.getSprite(), vcuboR[y][x].getSprite()))
                            {

                                switch(Jugador_1.getDirX())
                                {

                                case 1:
                                    Jugador_1.setX(Jugador_1.getSprite().getPosition().x-1);
                                    Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                    //            cout<< "colision" <<endl;
                                    break;

                                case -1:
                                    Jugador_1.setX(Jugador_1.getSprite().getPosition().x+1);
                                    Jugador_1.setY(Jugador_1.getSprite().getPosition().y);
                                    //              cout<< "colision" <<endl;
                                    break;
                                }

                                switch(Jugador_1.getDirY())
                                {

                                case 1:
                                    Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                    Jugador_1.setY(Jugador_1.getSprite().getPosition().y-1);
                                    //                cout<< "colision" <<endl;
                                    break;

                                case -1:
                                    Jugador_1.setX(Jugador_1.getSprite().getPosition().x);
                                    Jugador_1.setY(Jugador_1.getSprite().getPosition().y+1);
                                    //                  cout<< "colision" <<endl;
                                    break;
                                }

                            }
                            //else{
                            //      cout<< "No colision"<< endl;
                            //}

                        }
                    }
                }
///=////////////////////////////////////////////////////// Cubo se destruye /////////////////////////////////////////////////////////////////////////

                for( y=0; y<9; y++)
                {
                    for( x=0; x<13; x++)
                    {
                        if(vcuboR[y][x].getEstado()==true)
                        {
                            if(Bomba_J1.getEstado()!=0)
                            {
                                if(Collision::PixelPerfectTest(Bomba_J1.getSpriteBomba(), vcuboR[y][x].getSprite()))
                                {
                                    vcuboR[y][x].Destruir();
                                }
                            }

                            if(Bomba_J2.getEstado()!=0)
                            {
                                if(Collision::PixelPerfectTest(Bomba_J2.getSpriteBomba(), vcuboR[y][x].getSprite()))
                                {
                                    vcuboR[y][x].Destruir();
                                }
                            }
                        }
                    }
                }

///=////////////////////////////////////////////////////// Jugador pierde vida /////////////////////////////////////////////////////////////////////////

                //cout<<endl<<endl<<" VIDA JUGADOR 1 ="<<Jugador_1.GetVida()<<endl<<endl;
                /// Jugador 1 dañado por las 2 bombas
                if(Bomba_J1.getEstado()!=0 && Bomba_J1.getmostrar()==true)
                {
                    if(Collision::PixelPerfectTest(Bomba_J1.getSpriteBomba(), Jugador_1.getSprite()))
                    {
                        if(Jugador_1.getTiempo()>=3 )
                        {
                            Jugador_1.Daniar();
                            //cout<<endl<<endl<<" VIDA JUGADOR 1 ="<<Jugador_1.GetVida()<<endl<<endl;
                            Jugador_1.setTiempo();

                            if(Jugador_1.GetVida()==0)
                            {
                                /// Gana el jugador 2
                                game.SetGanador(2);
                                game.SetEstado(2);
                                game.setTiempo();
                                break;
                            }
                        }
                    }
                }
                /*
                if(Bomba_J2.getEstado()!=0)
                {
                    if(Collision::PixelPerfectTest(Bomba_J2.getSpriteBomba(), Jugador_1.getSprite()))
                    {
                        Jugador_1.Daniar();
                    }
                }



                /// Jugador 2 dañado por las 2 bombas
                if(Bomba_J1.getEstado()!=0)
                {
                    if(Collision::PixelPerfectTest(Bomba_J1.getSpriteBomba(), Jugador_2.getSprite()))
                    {
                        Jugador_2.Daniar();
                    }
                }

                if(Bomba_J2.getEstado()!=0)
                {
                    if(Collision::PixelPerfectTest(Bomba_J2.getSpriteBomba(), Jugador_2.getSprite()))
                    {
                        Jugador_2.Daniar();
                    }
                }

                if(Jugador_2.GetVida()==0)
                {
                    /// Gana el jugador 1
                    game.SetGanador(1);
                    game.SetEstado(2);
                }
                */
/// ///////////////////  TECLADO  JUGADOR 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                /// ABAJO
                if ((Keyboard::isKeyPressed(Keyboard::S)&&(Keyboard::isKeyPressed(Keyboard::A)) ||  (Keyboard::isKeyPressed(Keyboard::D)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::S)))
                    {
                        Jugador_2.moverAbajo(Jugador_2.getX(),Jugador_2.getY(), Jugador_2.getVelocidad());
                        Jugador_2.setDirY(1);
                        Jugador_2.setDirX(0);
                    }
                }
                /// ARRIBA
                if ((Keyboard::isKeyPressed(Keyboard::W)&&(Keyboard::isKeyPressed(Keyboard::A)) ||  (Keyboard::isKeyPressed(Keyboard::D)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::W)))
                    {
                        Jugador_2.moverArriba(Jugador_2.getX(),Jugador_2.getY(), Jugador_2.getVelocidad());
                        Jugador_2.setDirY(-1);
                        Jugador_2.setDirX(0);
                    }
                }
                ///IZQUIERDA
                if ((Keyboard::isKeyPressed(Keyboard::A)&&(Keyboard::isKeyPressed(Keyboard::W)) ||  (Keyboard::isKeyPressed(Keyboard::S)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::A)))
                    {

                        Jugador_2.moverIzquierda(Jugador_2.getX(),Jugador_2.getY(), Jugador_2.getVelocidad());
                        Jugador_2.setDirY(0);
                        Jugador_2.setDirX(-1);
                    }
                }
                ///DERECHA
                if ((Keyboard::isKeyPressed(Keyboard::D)&&(Keyboard::isKeyPressed(Keyboard::W)) ||  (Keyboard::isKeyPressed(Keyboard::S)) ))
                {
                }
                else
                {
                    if((Keyboard::isKeyPressed(Keyboard::D)))
                    {
                        Jugador_2.moverDerecha(Jugador_2.getX(),Jugador_2.getY(), Jugador_2.getVelocidad());
                        Jugador_2.setDirY(0);
                        Jugador_2.setDirX(1);
                    }
                }

/// ////////////////// BOMBA JUGADOR 2 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// ///////////////////COLISION JUGADOR 2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////



                ///COLISION ABAJO
                if(Jugador_2.getSprite().getPosition().y+49 > 600)
                {
                    Jugador_2.setY(600-49);
                }

                ///COLISION ARRIBA
                if(Jugador_2.getSprite().getPosition().y < 60)
                {
                    Jugador_2.setY(60);
                }


                ///COLISION ANCHO DERECHA
                if(Jugador_2.getSprite().getPosition().x+39 > 840)
                {
                    Jugador_2.setX(840-39);
                }

                ///COLISION ANCHO IZQUIERDA
                if(Jugador_2.getSprite().getPosition().x < 60)
                {
                    Jugador_2.setX(60);
                }

                /// COLISIONES BLOQUES

                for( y=0; y<4; y++)
                {
                    for( x=0; x<6; x++)
                    {

                        if(PixelPerfectTest(Jugador_2.getSprite(), vcubos[y][x].getSprite()))
                        {
                            switch(Jugador_2.getDirX())
                            {

                            case 1:
                                Jugador_2.setX(Jugador_2.getSprite().getPosition().x-1);
                                Jugador_2.setY(Jugador_2.getSprite().getPosition().y);
                                //cout<< "colision" <<endl;
                                break;

                            case -1:
                                Jugador_2.setX(Jugador_2.getSprite().getPosition().x+1);
                                Jugador_2.setY(Jugador_2.getSprite().getPosition().y);
                                //cout<< "colision" <<endl;
                                break;
                            }

                            switch(Jugador_2.getDirY())
                            {

                            case 1:
                                Jugador_2.setX(Jugador_2.getSprite().getPosition().x);
                                Jugador_2.setY(Jugador_2.getSprite().getPosition().y-1);
                                //cout<< "colision" <<endl;
                                break;

                            case -1:
                                Jugador_2.setX(Jugador_2.getSprite().getPosition().x);
                                Jugador_2.setY(Jugador_2.getSprite().getPosition().y+1);
                                //cout<< "colision" <<endl;
                                break;
                            }

                        }
                        else
                        {
                            //cout<< "No colision"<< endl;
                        }

                    }
                }


                ///=////////////////////////////////////////////////////// ROMPIBLES /////////////////////////////////////////////////////////////////////////


                for( y=0; y<9; y++)
                {
                    for( x=0; x<13; x++)
                    {

                        if(vcuboR[y][x].getEstado()==true)
                        {

                            if(Collision::PixelPerfectTest(Jugador_2.getSprite(), vcuboR[y][x].getSprite()))
                            {

                                switch(Jugador_2.getDirX())
                                {

                                case 1:
                                    Jugador_2.setX(Jugador_2.getSprite().getPosition().x-1);
                                    Jugador_2.setY(Jugador_2.getSprite().getPosition().y);
                                    //            cout<< "colision" <<endl;
                                    break;

                                case -1:
                                    Jugador_2.setX(Jugador_2.getSprite().getPosition().x+1);
                                    Jugador_2.setY(Jugador_2.getSprite().getPosition().y);
                                    //              cout<< "colision" <<endl;
                                    break;
                                }

                                switch(Jugador_2.getDirY())
                                {

                                case 1:
                                    Jugador_2.setX(Jugador_2.getSprite().getPosition().x);
                                    Jugador_2.setY(Jugador_2.getSprite().getPosition().y-1);
                                    //                cout<< "colision" <<endl;
                                    break;

                                case -1:
                                    Jugador_2.setX(Jugador_2.getSprite().getPosition().x);
                                    Jugador_2.setY(Jugador_2.getSprite().getPosition().y+1);
                                    //                  cout<< "colision" <<endl;
                                    break;
                                }

                            }
                            //else{
                            //      cout<< "No colision"<< endl;
                            //}

                        }
                    }
                }



/// /////////////////////////////////// PROBANDO COSAS /////////////////////////////////////////////////////////////////////////////////////////////

                ///INTENTO DE COLISIONES
                /*
                        if(Jugador_1.getSprite().getGlobalBounds().intersects(Jugador_2.getSprite().getGlobalBounds()))
                        {
                            Jugador_1.setX(72);
                            Jugador_1.setY(72);
                        }
                */

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                ///muestran el tiempo
                tiempo1=Bomba_J1.getTiempo();
                cout<<tiempo1<<endl;
                cout<<endl;

                variable=Bomba_J2.getTiempo();


/// /////////////////////////////////////////////////////////////////////


                ///Borra

                window.clear();
                ///Dibuja

                window.draw(mapa);

                ///dibuja los rompibles
                for( y=1; y<10; y++)
                {
                    for( x=1; x<14; x++)
                    {
                        if(vcuboR[y-1][x-1].getEstado()==true)
                        {
                            window.draw(vcuboR[y-1][x-1].getSprite());
                        }
                    }
                }


                if(Bomba_J2.getmostrar()==true)
                {
                    window.draw(Bomba_J2.getSpriteBomba());
                }

                if(Bomba_J1.getmostrar()==true)
                {
                    window.draw(Bomba_J1.getSpriteBomba());
                }

                ///dibuja los 24 cubos
                for( y=1; y<5; y++)
                {
                    for( x=1; x<7; x++)
                    {
                        window.draw(vcubos[y-1][x-1].getSprite());
                    }
                }
                window.draw(Jugador_1.getSprite());
                window.draw(Jugador_2.getSprite());

                /// FIN DEL JUEGO
                break;

            case 2:
                /// ESTADO VICTORIA
                //cout<<"ENTRE A LA VICTORIA"<<endl;
                //game.setTiempo();
                ///Borra

                window.clear();

                switch(game.GetGanador())
                {
                case 1:
                    /// Victoria del jugador 1
                    window.draw(Victoria_S);
                    break;

                case 2:
                    /// Victoria del jugador 2
                    window.draw(Victoria_S);
                    break;

                default:
                    /// Bugaso bro
                    game.SetEstado(0);
                    break;
                }
                if(game.getTiempo()>=3)
                {
                    game.SetEstado(0);
                    game.setTiempo();
                }

                /// FIN DE VICTORIA
                break;
            }
            window.display();
            relojfps.restart();///reincio el reloj
        }
    }

}


#endif // JUEGO_H_INCLUDED
