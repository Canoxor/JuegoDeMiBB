#ifndef MAPAS_H_INCLUDED
#define MAPAS_H_INCLUDED

#include "cuboR.h"
#include "ctime"

void CargarMapa(cuboR Cubos[9][13], int Opcion)
{
    FILE *m;

    switch(Opcion)
    {
    case 1:
        m=fopen("mapa_1.dat","rb");
        if(m==NULL)
            exit(-6);
        break;
    case 2:
        m=fopen("mapa_2.dat","rb");
        if(m==NULL)
            exit(-6);
        break;
    case 3:
        m=fopen("mapa_3.dat","rb");
        if(m==NULL)
            exit(-6);
        break;
    default:
        break;
    }

    for(int y=1; y<10; y++)
    {
        for(int x=1; x<14; x++)
        {
            fread(&Cubos[y-1][x-1], sizeof(cuboR), 1, m);
            Cubos[y-1][x-1].setPos(Cubos[y-1][x-1].getPosX(),Cubos[y-1][x-1].getPosY());
        }
    }

    Cubos[0][0].setEstado(false);  ///estos se setean aparte para que no le ocupen el spawn
    Cubos[0][1].setEstado(false);
    Cubos[1][0].setEstado(false);

    Cubos[8][12].setEstado(false);
    Cubos[7][12].setEstado(false);
    Cubos[8][11].setEstado(false);

    fclose(m);
}


bool crearMapa3() ///aca creamos el archivo en WB (este es el mapa de siempre)
{

    srand((unsigned) time(0));

    cuboR vcuboR;


    FILE *m;
    m=NULL;
    m=fopen("mapa_3.dat","wb");
    if(m==NULL)
        return false;


    int xc=60;
    int yc=60;
    int x;
    int y;

    for(y=1; y< 10  ; y++)
    {

        for(x=1; x< 14  ; x++)
        {

            vcuboR.setPos((float)xc*x, (float) yc*y);
            vcuboR.setEstado(true);
            fwrite(&vcuboR, sizeof(cuboR), 1, m);

        }
    }


    fclose(m);
    return true;
}



bool crearMapa2() ///aca creamos el archivo en WB
{

    srand((unsigned) time(0));

    cuboR vcuboR;



    int randX[20];
    int randY[20];


    for(int z=0; z< 20; z++)
    {
        randX[z]=(rand() % 13) +1;
        cout<<randX[z]<<endl;

        randY[z]=(rand() % 9) +1;
        cout<<randY[z]<<endl;


    }



    FILE *m;
    m=NULL;
    m=fopen("mapa_2.dat","wb");
    if(m==NULL)
        return false;


    int xc=60;
    int yc=60;
    int x;
    int y;

    for(y=1; y< 10  ; y++)
    {

        for(x=1; x< 14  ; x++)
        {

            vcuboR.setPos((float)xc*x, (float) yc*y);
            vcuboR.setEstado(true);


            for(int k=0; k< 20; k++)  ///estos son cubos que no van a aparecer, ya que es un mapa RANDOM
            {

                if(x==randX[k] && y==randY[k])
                {
                    vcuboR.setEstado(false);

                }
            }

            fwrite(&vcuboR, sizeof(cuboR), 1, m);

        }
    }

    fclose(m);
    return true;
}





bool crearMapa1()  ///aca creamos el archivo en WB
{


    cuboR vcuboR;


    FILE *m;
    m=NULL;
    m=fopen("mapa_1.dat","wb");
    if(m==NULL)
        return false;


    int xc=60;
    int yc=60;
    int x;
    int y;

    for(y=1; y< 10  ; y++)
    {

        for(x=1; x< 14  ; x++)
        {

            vcuboR.setPos((float)xc*x, (float) yc*y);
            vcuboR.setEstado(true);

            if(y==3 && x==3)  ///estos son cubos que no van a aparecer porque es un mapa prediseñado:)
            {
                vcuboR.setEstado(false);
            }
            if(y==3 && x==5)
            {
                vcuboR.setEstado(false);
            }
            if(y==3 && x==7)
            {
                vcuboR.setEstado(false);
            }
            if(y==3 && x==9)
            {
                vcuboR.setEstado(false);
            }
            if(y==3 && x==11)
            {
                vcuboR.setEstado(false);
            }

///
            if(y==5 && x==3)
            {
                vcuboR.setEstado(false);
            }
            if(y==5 && x==5)
            {
                vcuboR.setEstado(false);
            }
            if(y==5 && x==7)
            {
                vcuboR.setEstado(false);
            }
            if(y==5 && x==9)
            {
                vcuboR.setEstado(false);
            }
            if(y==5 && x==11)
            {
                vcuboR.setEstado(false);
            }
///

            if(y==7 && x==3)
            {
                vcuboR.setEstado(false);
            }
            if(y==7 && x==5)
            {
                vcuboR.setEstado(false);
            }
            if(y==7 && x==7)
            {
                vcuboR.setEstado(false);
            }
            if(y==7 && x==9)
            {
                vcuboR.setEstado(false);
            }
            if(y==7 && x==11)
            {
                vcuboR.setEstado(false);
            }


            fwrite(&vcuboR, sizeof(cuboR), 1, m);

        }
    }

    fclose(m);
    return true;
}





#endif // MAPAS_H_INCLUDED
