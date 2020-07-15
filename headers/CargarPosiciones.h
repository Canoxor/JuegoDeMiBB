#ifndef CARGARPOSICIONES_H_INCLUDED
#define CARGARPOSICIONES_H_INCLUDED

void CargarPosiciones(float *vecX, float *vecY){
    vecX[0]=89.5;
    for(int x=1;x<13;x++){
        vecX[x]=vecX[x-1]+60;
    }

    vecY[0]=89.5;
    for(int y=1;y<9;y++){
        vecY[y]=vecY[y-1]+60;
    }
}

void VerificarPosicion(int Spawn[2][2],float PosicionXJ,float PosicionYJ,float *vecX,float *vecY){

    //60-89.5=29.5 diferencia
    PosicionXJ = PosicionXJ + 29.5;
    PosicionYJ = PosicionYJ + 29.5;

    ///DIFERENCIA DE X
    float MenorDiferenciaX;
    int PosicionDiferenciaX = 0;
    float DiferenciaEvaluandoX;

    MenorDiferenciaX = vecX[0] - PosicionXJ;
    if(MenorDiferenciaX < 0)
    {
        MenorDiferenciaX = MenorDiferenciaX*(-1);
    }

    for(int x=1; x<13; x++)
    {
        DiferenciaEvaluandoX = vecX[x]-PosicionXJ;
        if(DiferenciaEvaluandoX < 0)
        {
            DiferenciaEvaluandoX = DiferenciaEvaluandoX*(-1);
        }

        if(DiferenciaEvaluandoX < MenorDiferenciaX)
        {
            MenorDiferenciaX = DiferenciaEvaluandoX;
            PosicionDiferenciaX = x;
        }
    }


    ///NUEVO SPAWN X
    Spawn[0][0]=PosicionDiferenciaX;
    Spawn[0][1]=PosicionDiferenciaX;

/// /////////////////////////////////////////////////////////////////////////////////////////////////

    ///DIFERENCIA DE X
    float MenorDiferenciaY;
    int PosicionDiferenciaY = 0;
    float DiferenciaEvaluandoY;

    MenorDiferenciaY = vecY[0] - PosicionYJ;
    if(MenorDiferenciaY < 0)
    {
        MenorDiferenciaY = MenorDiferenciaY*(-1);
    }


    for(int y=1; y<9; y++)
    {
        DiferenciaEvaluandoY = vecY[y]-PosicionYJ;
        if(DiferenciaEvaluandoY < 0)
        {
            DiferenciaEvaluandoY = DiferenciaEvaluandoY*(-1);
        }

        if(DiferenciaEvaluandoY < MenorDiferenciaY)
        {
            MenorDiferenciaY = DiferenciaEvaluandoY;
            PosicionDiferenciaY = y;
        }
    }

    ///NUEVO SPAWN X
    Spawn[1][0]=PosicionDiferenciaY;
    Spawn[1][1]=PosicionDiferenciaY;


}


#endif // CARGARPOSICIONES_H_INCLUDED
