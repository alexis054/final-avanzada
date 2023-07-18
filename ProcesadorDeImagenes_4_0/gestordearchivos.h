#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <fstream>
#include <string>
#include "imagen.h"
#include <iostream>

using namespace std;

class GestorDeArchivos
{
public:
    GestorDeArchivos();

//metodos virtuales

    Imagen virtual Cargar();
    void virtual Guardar();
    virtual ~GestorDeArchivos(){};

 };

#endif // GESTORDEARCHIVOS_H
