#ifndef FILTROESPACIAL_H
#define FILTROESPACIAL_H
#include "filtro.h"

using namespace std;

class FiltroEspacial :  public Filtro
{
public:
    FiltroEspacial();
    void filtradoMediana(Imagen &pImagen);
    void filtradoSuavizado(Imagen &pImagen);

};

#endif // FILTROESPACIAL_H
