#ifndef GUARDAR_H
#define GUARDAR_H

#include <SFML/Graphics.hpp>

using namespace sf;

#include "cuboR.h"

class guardar
{
        private:

        float posXj1;
        float posYj1;

        float posXj2;
        float posYj2;
        int vidaj1;
        int vidaj2;

        cuboR c[9][13];


    public:
        guardar();
        virtual ~guardar();




    void setPosXj1(float posXj1) {
        this->posXj1 = posXj1;
    }

    float getPosXj1() {
        return posXj1;
    }
    float getPosYj1() {
        return posYj1;
    }
    void setPosYj1(float posYj1) {
        this->posYj1 = posYj1;
    }
    float getPosXj2() {
        return posXj2;
    }
    void setPosXj2(float posXj2) {
        this->posXj2 = posXj2;
    }
    float getPosYj2() {
        return posYj2;
    }
    void setPosYj2(float posYj2) {
        this->posYj2 = posYj2;
    }
    int getVidaj1() {
        return vidaj1;
    }
    void setVidaj1(int vidaj1) {
        this->vidaj1 = vidaj1;
    }
   int getVidaj2() {
        return vidaj2;
    }
    void setVidaj2(int vidaj2) {
        this->vidaj2 = vidaj2;
    }


void setCubos(cuboR m[9][13]){
    for(int y=0; y<9; y++)
                {
                    for(int x=0; x<13; x++){

                            c[y][x]=m[y][x];

}

}
}

cuboR getCubos(int x, int y){return c[y][x];}




};

#endif // GUARDAR_H
