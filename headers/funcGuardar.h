#ifndef FUNCGUARDAR_H_INCLUDED
#define FUNCGUARDAR_H_INCLUDED

#include "guardar.h"
#include "cuboR.h"

bool guardarPartida  (float posXj1, float posYj1, float posXj2, float posYj2, int vidaj1, int vidaj2, cuboR m[9][13]){

guardar nuev;

FILE *p;
p=NULL;
p=fopen("partida.dat", "wb");
if(p==NULL) return false;

nuev.setPosXj1(posXj1);
nuev.setPosYj1(posYj1);

nuev.setPosXj2(posXj2);
nuev.setPosYj2(posYj2);

nuev.setVidaj1(vidaj1);
nuev.setVidaj2(vidaj2);

nuev.setCubos(m);

fwrite(&nuev, sizeof(guardar), 1, p);

fclose(p);
}


guardar cargarPartida(){

guardar nuev;

FILE *p;
p=NULL;
p=fopen("partida.dat", "rb");
if(p==NULL) exit(-3);



fread(&nuev, sizeof(guardar), 1, p);

fclose(p);
return nuev;
}






#endif // FUNCGUARDAR_H_INCLUDED
