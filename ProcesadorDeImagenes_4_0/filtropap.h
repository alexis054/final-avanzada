#ifndef FILTROPAP_H
#define FILTROPAP_H
#include "filtro.h"


class FiltroPaP : public Filtro
{
public:
    FiltroPaP();

    void Brillo(Imagen &pImagen);
    void Contraste(Imagen &pImagen);
    void Binarizar (Imagen &pImagen);


private:
    float db=10;//valor arbitrario, diferencial brillo
    int maximo= 254;

};

#endif // FILTROPAP_H
