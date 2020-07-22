#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace Collision;

void FuncionJuego()
{

    RenderWindow window(VideoMode(1260, 660), "DESTROY_IT");
    bool Mouse_Habilitado = true;
    bool BuggEnter = true;

    /// SONIDO

    // Musica del menu
    Musica Musica_Menu("musica/Musica_menu.ogg");
    Musica_Menu.repeticion(true);
    Musica_Menu.volumen(10);

    // Musica del juego
    Musica Musica_Juego("musica/Musica_juego.ogg");
    Musica_Juego.repeticion(true);
    Musica_Juego.volumen(30);

    // Musica al ganar
    Musica Musica_Victoria("musica/Musica_victoria.ogg");
    Musica_Victoria.repeticion(true);
    Musica_Victoria.volumen(30);

    // Sonido menu
    FX Sonido_MenuPrincipal("musica/FX/select_menu.wav");
    Sonido_MenuPrincipal.cambiar_volumen(100);

    // Sonido bomba colocar
    /*
    FX Sonido_ColocarBomba("musica/FX/building.wav");
    Sonido_ColocarBomba.cambiar_volumen(100);
    */

    Clock relojfps;
    Time tiempo;
    int fps=60;

    /// Partida
    Partida game;
    game.setTiempo();

    /// Menu
    //Textures
    Texture MenuPrincipal, Seleccionar;
    int valorSeleccionar = 1;
    if(!MenuPrincipal.loadFromFile("imagen/Pantalla/Menu_Principal.jpg"))
    {
        ///Si hay un error salimos
        exit(11);
    }
    if(!Seleccionar.loadFromFile("imagen/Pantalla/Seleccionar.png"))
    {
        ///Si hay un error salimos
        exit(11);
    }
    //Sprites
    Sprite MenuPrincipal_S, Seleccionar_S;
    MenuPrincipal_S.setTexture(MenuPrincipal);
    Seleccionar_S.setTexture(Seleccionar);

    /// Victoria
    //Textures
    Texture Victoria_J1_T, Victoria_J2_T;
    if(!Victoria_J1_T.loadFromFile("imagen/Pantalla/Ganador_1.jpg"))
    {
        ///Si hay un error salimos
        exit(13);
    }
    Victoria_J1_T.setSmooth(true);
    if(!Victoria_J2_T.loadFromFile("imagen/Pantalla/Ganador_2.jpg"))
    {
        ///Si hay un error salimos
        exit(13);
    }
    Victoria_J2_T.setSmooth(true);
    //Sprites
    Sprite Victoria_J1_S, Victoria_J2_S;

    Victoria_J1_S.setTexture(Victoria_J1_T);
    Victoria_J2_S.setTexture(Victoria_J2_T);

    /// MAPA
    Texture mapita;
    if(!mapita.loadFromFile("imagen/Pantalla/mapita.png"))
    {
        ///Si hay un error salimos
        exit(13);
    }
    Sprite mapa;
    mapa.setTexture(mapita);

    bool mapaCargado = false;

///JUGADORES /////////////////////////////////////////////////////////////////

    // Sprites para el JUGADOR 1

    /// Texture Quito
    Texture J1_K_Quieto;

    if(!J1_K_Quieto.loadFromFile("imagen/Personajes/Jugador_1/Jug1_Pausa.png"))
    {
        exit(200);
    }

    /// Texture Derecha
    Texture J1_D_Pie_Derecho_1, J1_D_Pie_Derecho_2, J1_D_Pie_Izquierdo_1, J1_D_Pie_Izquierdo_2, J1_D_Pausa;

    if(!J1_D_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_1/Derecha/Jug1_Pie_Derecho_1.png"))
    {
        exit(201);
    }
    if(!J1_D_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_1/Derecha/Jug1_Pie_Derecho_2.png"))
    {
        exit(202);
    }
    if(!J1_D_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_1/Derecha/Jug1_Pie_Izquierdo_1.png"))
    {
        exit(203);
    }
    if(!J1_D_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_1/Derecha/Jug1_Pie_Izquierdo_2.png"))
    {
        exit(204);
    }
    if(!J1_D_Pausa.loadFromFile("imagen/Personajes/Jugador_1/Derecha/Jug1_Pausa.png"))
    {
        exit(205);
    }

    /// Texture Izquierda
    Texture J1_I_Pie_Derecho_1, J1_I_Pie_Derecho_2, J1_I_Pie_Izquierdo_1, J1_I_Pie_Izquierdo_2, J1_I_Pausa;

    if(!J1_I_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_1/Izquierda/Jug1_Pie_Derecho_1.png"))
    {
        exit(206);
    }
    if(!J1_I_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_1/Izquierda/Jug1_Pie_Derecho_2.png"))
    {
        exit(207);
    }
    if(!J1_I_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_1/Izquierda/Jug1_Pie_Izquierdo_1.png"))
    {
        exit(208);
    }
    if(!J1_I_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_1/Izquierda/Jug1_Pie_Izquierdo_2.png"))
    {
        exit(209);
    }
    if(!J1_I_Pausa.loadFromFile("imagen/Personajes/Jugador_1/Izquierda/Jug1_Pausa.png"))
    {
        exit(210);
    }

    /// Texture Arriba
    Texture J1_AR_Pie_Derecho_1, J1_AR_Pie_Derecho_2, J1_AR_Pie_Izquierdo_1, J1_AR_Pie_Izquierdo_2, J1_AR_Pausa;

    if(!J1_AR_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_1/Arriba/Jug1_Pie_Derecho_1.png"))
    {
        exit(211);
    }
    if(!J1_AR_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_1/Arriba/Jug1_Pie_Derecho_2.png"))
    {
        exit(212);
    }
    if(!J1_AR_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_1/Arriba/Jug1_Pie_Izquierdo_1.png"))
    {
        exit(213);
    }
    if(!J1_AR_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_1/Arriba/Jug1_Pie_Izquierdo_2.png"))
    {
        exit(214);
    }
    if(!J1_AR_Pausa.loadFromFile("imagen/Personajes/Jugador_1/Arriba/Jug1_Pausa.png"))
    {
        exit(215);
    }

    /// Texture Abajo
    Texture J1_AB_Pie_Derecho_1, J1_AB_Pie_Derecho_2, J1_AB_Pie_Izquierdo_1, J1_AB_Pie_Izquierdo_2, J1_AB_Pausa;

    if(!J1_AB_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_1/Abajo/Jug1_Pie_Derecho_1.png"))
    {
        exit(217);
    }
    if(!J1_AB_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_1/Abajo/Jug1_Pie_Derecho_2.png"))
    {
        exit(218);
    }
    if(!J1_AB_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_1/Abajo/Jug1_Pie_Izquierdo_1.png"))
    {
        exit(219);
    }
    if(!J1_AB_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_1/Abajo/Jug1_Pie_Izquierdo_2.png"))
    {
        exit(220);
    }
    if(!J1_AB_Pausa.loadFromFile("imagen/Personajes/Jugador_1/Abajo/Jug1_Pausa.png"))
    {
        exit(221);
    }

    // Sprites para el JUGADOR 2

    /// Texture Quito
    Texture J2_K_Quieto;

    if(!J2_K_Quieto.loadFromFile("imagen/Personajes/Jugador_2/Jug2_Pausa.png"))
    {
        exit(200);
    }

    /// Texture Derecha
    Texture J2_D_Pie_Derecho_1, J2_D_Pie_Derecho_2, J2_D_Pie_Izquierdo_1, J2_D_Pie_Izquierdo_2, J2_D_Pausa;

    if(!J2_D_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_2/Derecha/Jug2_Pie_Derecho_1.png"))
    {
        exit(201);
    }
    if(!J2_D_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_2/Derecha/Jug2_Pie_Derecho_2.png"))
    {
        exit(202);
    }
    if(!J2_D_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_2/Derecha/Jug2_Pie_Izquierdo_1.png"))
    {
        exit(203);
    }
    if(!J2_D_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_2/Derecha/Jug2_Pie_Izquierdo_2.png"))
    {
        exit(204);
    }
    if(!J2_D_Pausa.loadFromFile("imagen/Personajes/Jugador_2/Derecha/Jug2_Pausa.png"))
    {
        exit(205);
    }

    /// Texture Izquierda
    Texture J2_I_Pie_Derecho_1, J2_I_Pie_Derecho_2, J2_I_Pie_Izquierdo_1, J2_I_Pie_Izquierdo_2;

    if(!J2_I_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pie_Derecho_1.png"))
    {
        exit(206);
    }
    if(!J2_I_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pie_Derecho_2.png"))
    {
        exit(207);
    }
    if(!J2_I_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pie_Izquierdo_1.png"))
    {
        exit(208);
    }
    if(!J2_I_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pie_Izquierdo_2.png"))
    {
        exit(209);
    }
    /// ERROR NO ENTIENDO POR QUE
    Texture J2_I_Pausa;
    if(!J2_I_Pausa.loadFromFile("imagen/Personajes/Jugador_2/Izquierda/Jug2_Pie_Izquierdo_2.png"))
    {
        exit(210);
    }

    /// Texture Arriba
    Texture J2_AR_Pie_Derecho_1, J2_AR_Pie_Derecho_2, J2_AR_Pie_Izquierdo_1, J2_AR_Pie_Izquierdo_2, J2_AR_Pausa;

    if(!J2_AR_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_2/Arriba/Jug2_Pie_Derecho_1.png"))
    {
        exit(211);
    }
    if(!J2_AR_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_2/Arriba/Jug2_Pie_Derecho_2.png"))
    {
        exit(212);
    }
    if(!J2_AR_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_2/Arriba/Jug2_Pie_Izquierdo_2.png"))
    {
        exit(213);
    }
    if(!J2_AR_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_2/Arriba/Jug2_Pie_Izquierdo_1.png"))
    {
        exit(214);
    }
    if(!J2_AR_Pausa.loadFromFile("imagen/Personajes/Jugador_2/Arriba/Jug2_Pausa.png"))
    {
        exit(215);
    }

    /// Texture Abajo
    Texture J2_AB_Pie_Derecho_1, J2_AB_Pie_Derecho_2, J2_AB_Pie_Izquierdo_1, J2_AB_Pie_Izquierdo_2, J2_AB_Pausa;

    if(!J2_AB_Pie_Derecho_1.loadFromFile("imagen/Personajes/Jugador_2/Abajo/Jug2_Pie_Derecho_1.png"))
    {
        exit(217);
    }
    if(!J2_AB_Pie_Derecho_2.loadFromFile("imagen/Personajes/Jugador_2/Abajo/Jug2_Pie_Derecho_2.png"))
    {
        exit(218);
    }
    if(!J2_AB_Pie_Izquierdo_1.loadFromFile("imagen/Personajes/Jugador_2/Abajo/Jug2_Pie_Izquierdo_2.png"))
    {
        exit(219);
    }
    if(!J2_AB_Pie_Izquierdo_2.loadFromFile("imagen/Personajes/Jugador_2/Abajo/Jug2_Pie_Izquierdo_1.png"))
    {
        exit(220);
    }
    if(!J2_AB_Pausa.loadFromFile("imagen/Personajes/Jugador_2/Abajo/Jug2_Pausa.png"))
    {
        exit(221);
    }

    ///JUGADOR1
    Jugador Jugador_1(60, 60, 0);
    Jugador_1.setScreenJug(960,60,3);

    /// Carga los sprites al jugador 1
    Jugador_1.setSprites_Quieto(J1_K_Quieto);

    Jugador_1.setSprites_Arriba(J1_AR_Pausa, J1_AR_Pie_Derecho_1, J1_AR_Pie_Derecho_2, J1_AR_Pie_Izquierdo_1, J1_AR_Pie_Izquierdo_2);

    Jugador_1.setSprites_Derecha(J1_D_Pausa, J1_D_Pie_Derecho_1, J1_D_Pie_Derecho_2, J1_D_Pie_Izquierdo_1, J1_D_Pie_Izquierdo_2);

    Jugador_1.setSprites_Abajo(J1_AB_Pausa, J1_AB_Pie_Derecho_1, J1_AB_Pie_Derecho_2, J1_AB_Pie_Izquierdo_1, J1_AB_Pie_Izquierdo_2);

    Jugador_1.setSprites_Izquierda(0, J1_I_Pausa, J1_I_Pie_Derecho_1, J1_I_Pie_Derecho_2, J1_I_Pie_Izquierdo_1, J1_I_Pie_Izquierdo_2);

    ///JUGADOR2
    Jugador Jugador_2(780, 540, 1);
    Jugador_2.setScreenJug(960, 300, 3);

    /// Carga los sprites al jugador 2
    Jugador_2.setSprites_Quieto(J2_K_Quieto);

    Jugador_2.setSprites_Arriba(J2_AR_Pausa, J2_AR_Pie_Derecho_1, J2_AR_Pie_Derecho_2, J2_AR_Pie_Izquierdo_1, J2_AR_Pie_Izquierdo_2);

    Jugador_2.setSprites_Derecha(J2_D_Pausa, J2_D_Pie_Derecho_1, J2_D_Pie_Derecho_2, J2_D_Pie_Izquierdo_1, J2_D_Pie_Izquierdo_2);

    Jugador_2.setSprites_Abajo(J2_AB_Pausa, J2_AB_Pie_Derecho_1, J2_AB_Pie_Derecho_2, J2_AB_Pie_Izquierdo_1, J2_AB_Pie_Izquierdo_2);

    Jugador_2.setSprites_Izquierda(1, J1_I_Pausa, J2_I_Pie_Derecho_1, J2_I_Pie_Derecho_2, J2_I_Pie_Izquierdo_1, J2_I_Pie_Izquierdo_2);

    /// VECTOR JUGADORES
    int SpawnBombas[2][2]= {0};

/// /////BOMBA /////////////////////////////////////////////////////////////////

    ///POSICIONES DEL CENTRO BOMBAS
    float VecX[13]= {0};
    float VecY[9]= {0};
    CargarPosiciones(VecX,VecY);

    /// Sprites para las bombas
    Texture Bomba_Roja_T, Bomba_Azul_T;

    if(!Bomba_Roja_T.loadFromFile("imagen/Bombas/Bomba_Roja.png"))
    {
        ///Si hay un error salimos
        exit(1);
    }
    if(!Bomba_Azul_T.loadFromFile("imagen/Bombas/Bomba_Roja.png"))
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

    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///
    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///
    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///


    cuboR vcuboR[9][13];
    int randomNumber;

    srand((unsigned) time(0));

    switch(randomNumber)
    {
    ///archivo MAPA 1
    case 1:
        crearMapa1();
        break;

    ///archivo MAPA 2
    case 2:
        crearMapa2();
        break;

    ///archivo MAPA 3
    case 3:
        crearMapa3();
        break;
    }


    /*
    xc=60;
    yc=60;

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
    */


    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///
    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///
    /// ===================================CUBO R NUMERO RAND CON ARCHIVO =============================================================== ///

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
                /// ESTADO MENU PRINCIPAL
                // Enciende la musica del menu
                if(!Musica_Menu.getEncendida())
                {
                    Musica_Menu.reproducir();
                }

                //cout<<"TIEMPO DEL MENU"<<game.getTiempo()<<endl;

                if (event.type == Event::KeyPressed)
                {
                    if(Mouse_Habilitado)
                    {
                        if((Keyboard::isKeyPressed(Keyboard::Down)))
                        {
                            if(Mouse_Habilitado)
                            {
                                Sonido_MenuPrincipal.encender();

                                if(valorSeleccionar == 3)
                                {
                                    valorSeleccionar = 1;
                                }
                                else
                                {
                                    valorSeleccionar++;
                                }
                            }
                        }

                        if((Keyboard::isKeyPressed(Keyboard::Up)))
                        {
                            Sonido_MenuPrincipal.encender();

                            if(valorSeleccionar == 1)
                            {
                                valorSeleccionar = 3;
                            }
                            else
                            {
                                valorSeleccionar--;
                            }
                        }
                        Mouse_Habilitado = false;
                    }
                }
                else
                {
                    Mouse_Habilitado = true;
                }

                ///Borra
                window.clear();

                window.draw(MenuPrincipal_S);

                switch(valorSeleccionar)
                {
                case 1:
                    Seleccionar_S.setPosition(630,60);
                    window.draw(Seleccionar_S);
                    break;
                case 2:
                    Seleccionar_S.setPosition(630,200);
                    window.draw(Seleccionar_S);
                    break;
                case 3:
                    Seleccionar_S.setPosition(20,145);
                    window.draw(Seleccionar_S);
                    break;
                default:
                    break;
                }

                if((Keyboard::isKeyPressed(Keyboard::Enter)))
                {
                    // Apaga la musica del menu
                    Musica_Menu.parar();

                    switch(valorSeleccionar)
                    {
                    case 1:
                        /// NUEVA PARTIDA
                        randomNumber =  (rand() % 3) +1;;
                        CargarMapa(vcuboR, randomNumber);

                        Jugador_1.Reset(60,60);
                        Jugador_1.setScreenJug(960,60,3);
                        BuggEnter = true;

                        Jugador_2.Reset(780, 540);
                        Jugador_2.setScreenJug(960, 300, 3);

                        tiempo1 = 0;

                        game.SetEstado(1);
                        break;
                    case 2:
                        /// CARGAR PARTIDA
                        break;
                    case 3:
                        /// SALIR
                        exit(777);
                        break;
                    }
                }

                /// FIN DEL MENU
                break;

            case 1:
                /// ESTADO JUEGO
                // Enciende la musica del juego
                if(!Musica_Juego.getEncendida())
                {
                    Musica_Juego.reproducir();
                }

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

                // Margen de inicio
                if(Jugador_1.getTiempo() > 2)
                {
                    BuggEnter = false;
                }

                if((Keyboard::isKeyPressed(Keyboard::Enter)))
                {
                    if(Mouse_Habilitado)
                    {
                        Mouse_Habilitado = false;

                        if(BuggEnter == false)
                        {
                            if(Bomba_J1.getmostrar()==false)
                            {
                                //Sonido_ColocarBomba.encender();

                                VerificarPosicion(SpawnBombas,Jugador_1.getX(),Jugador_1.getY(),VecX,VecY);
                                Bomba_J1.Aparecer(VecX[SpawnBombas[0][0]]-29.5,VecY[SpawnBombas[1][0]]-29.5);
                                Bomba_J1.setmostrar(true);
                                Bomba_J1.setTiempo();
                            }
                            else
                            {
                                Mouse_Habilitado = true;
                            }
                        }
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

                /// Jugador 1 dañado por las 2 bombas
                if(Bomba_J1.getEstado()!=0 && Bomba_J1.getmostrar()==true)
                {
                    if(Collision::PixelPerfectTest(Bomba_J1.getSpriteBomba(), Jugador_1.getSprite()))
                    {
                        if(Jugador_1.getTiempo()>=3 )
                        {
                            Jugador_1.Daniar();
                            Jugador_1.setTiempo();
                            Jugador_1.setScreenJug(960, 60, Jugador_1.GetVida());

                            if(Jugador_1.GetVida()==0)
                            {
                                /// Gana el jugador 2
                                Musica_Juego.parar();

                                game.SetGanador(2);
                                game.SetEstado(2);
                                game.setTiempo();
                                break;
                            }
                        }
                    }
                }

                if(Bomba_J2.getEstado()!=0 && Bomba_J2.getmostrar()==true)
                {
                    if(Collision::PixelPerfectTest(Bomba_J2.getSpriteBomba(), Jugador_1.getSprite()))
                    {
                        if(Jugador_1.getTiempo()>=3 )
                        {
                            Jugador_1.Daniar();
                            Jugador_1.setTiempo();
                            Jugador_1.setScreenJug(960, 60, Jugador_1.GetVida());

                            if(Jugador_1.GetVida()==0)
                            {
                                /// Gana el jugador 2
                                Musica_Juego.parar();

                                game.SetGanador(2);
                                game.SetEstado(2);
                                game.setTiempo();
                                break;
                            }
                        }
                    }
                }

                /// Jugador 2 dañado por las 2 bombas
                if(Bomba_J1.getEstado()!=0 && Bomba_J1.getmostrar()==true)
                {
                    if(Collision::PixelPerfectTest(Bomba_J1.getSpriteBomba(), Jugador_2.getSprite()))
                    {
                        if(Jugador_2.getTiempo()>=3 )
                        {
                            Jugador_2.Daniar();
                            //cout<<endl<<endl<<" VIDA JUGADOR 2 ="<<Jugador_2.GetVida()<<endl<<endl;
                            Jugador_2.setTiempo();
                            Jugador_2.setScreenJug(960, 300, Jugador_2.GetVida());

                            if(Jugador_2.GetVida()==0)
                            {
                                /// Gana el jugador 1
                                Musica_Juego.parar();

                                game.SetGanador(1);
                                game.SetEstado(2);
                                game.setTiempo();
                                break;
                            }
                        }
                    }
                }

                if(Bomba_J2.getEstado()!=0 && Bomba_J2.getmostrar()==true)
                {
                    if(Collision::PixelPerfectTest(Bomba_J2.getSpriteBomba(), Jugador_2.getSprite()))
                    {
                        if(Jugador_2.getTiempo()>=3 )
                        {
                            Jugador_2.Daniar();
                            //cout<<endl<<endl<<" VIDA JUGADOR 2 ="<<Jugador_2.GetVida()<<endl<<endl;
                            Jugador_2.setTiempo();
                            Jugador_2.setScreenJug(960, 300, Jugador_2.GetVida());

                            if(Jugador_2.GetVida()==0)
                            {
                                /// Gana el jugador 1
                                Musica_Juego.parar();

                                game.SetGanador(1);
                                game.SetEstado(2);
                                game.setTiempo();
                                break;
                            }
                        }
                    }
                }

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

                if(Mouse_Habilitado)
                {
                    Mouse_Habilitado = false;
                }
                else
                {
                    Mouse_Habilitado = true;
                }
                if((Keyboard::isKeyPressed(Keyboard::Space)))
                {
                    if(Bomba_J2.getmostrar()==false)
                    {
                        //Sonido_ColocarBomba.encender();

                        VerificarPosicion(SpawnBombas,Jugador_2.getX(),Jugador_2.getY(),VecX,VecY);
                        Bomba_J2.Aparecer(VecX[SpawnBombas[0][0]]-29.5,VecY[SpawnBombas[1][0]]-29.5);
                        Bomba_J2.setmostrar(true);
                        Bomba_J2.setTiempo();
                    }
                }
                if(Bomba_J2.getTiempo()>=2)
                {
                    Bomba_J2.setEstado(1);
                }
                if(Bomba_J2.getTiempo()>=4)
                {
                    Bomba_J2.setmostrar(false);
                    Bomba_J2.setTiempo();
                }

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
                window.draw(Jugador_1.getScreenJug().getSprite());
                window.draw(Jugador_2.getScreenJug().getSprite());

                /// FIN DEL JUEGO
                break;

            case 2:
                /// ESTADO VICTORIA
                // Enciende la musica de victoria
                if(!Musica_Victoria.getEncendida())
                {
                    Musica_Victoria.reproducir();
                }

                //cout<<"ENTRE A LA VICTORIA"<<endl;
                //game.setTiempo();
                ///Borra

                window.clear();

                switch(game.GetGanador())
                {
                case 1:
                    /// Victoria del jugador 1
                    window.draw(Victoria_J1_S);
                    break;

                case 2:
                    /// Victoria del jugador 2
                    window.draw(Victoria_J2_S);
                    break;

                default:
                    /// Bugaso bro
                    game.SetEstado(0);
                    break;
                }
                if(game.getTiempo()>=3)
                {
                    Musica_Victoria.parar();
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
