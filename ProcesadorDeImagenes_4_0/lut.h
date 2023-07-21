#ifndef LUT_H
#define LUT_H
#include "imagen.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class Lut
{
public:
    Lut();
    void cargar(int pNum);
    void modificarimg(Imagen &pImagen);
private:

    vector<vector<float>> lut;
};

#endif // LUT_H
