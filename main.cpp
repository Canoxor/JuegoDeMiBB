#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

#include "headers/Collision.hpp"
#include "headers/CargarPosiciones.h"
#include "cubo.h"
#include "cuboR.h"
#include "bomba.h"
#include "Jugador.h"
#include "InterfazJug.h"
#include "guardar.h"
#include "headers/Partida.h"
#include "headers/mapas.h"
#include "headers/Sonido.h"
#include "headers/funcGuardar.h"
#include "headers/Juego.h"

int main()
{
    FuncionJuego();

    return 0;
}
