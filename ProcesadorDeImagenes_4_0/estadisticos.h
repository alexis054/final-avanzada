#ifndef ESTADISTICOS_H
#define ESTADISTICOS_H
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include "imagen.h"

using namespace std;

class Estadisticos
{
public:
    Estadisticos();
//histogramas
    map<int,int> Hist_intensidad();
    map<int,int> Hist_R();
    map<int,int> Hist_G();
    map<int,int> Hist_B();


//Promedios
    int Promedio_Intensidad();
    int Promedio_R();
    int Promedio_G();
    int Promedio_B();

 //medidas de tendencia central
    Pixel Moda();
    Pixel Mediana();
    int MedianaR();
    int MedianaG();
    int MedianaB();
    vector<float> DesvioSTD();
    int IntenMediaTotal();



//maximos y minimos
    int Max_Intensidad();
    int Min_Intensidad();

    int Max_R();
    int Max_G();
    int Max_B();

    int Min_R();
    int Min_G();
    int Min_B();

//metodos miscelaneos
    void setDatos(const Imagen &newDatos);
    void Ordenar();

    void setVec(const vector<Pixel> &newVec);

    const vector<Pixel> &getVec() const;




    const pair<unsigned int, unsigned int> &getMF_R() const;

private:
    Imagen Datos;
    vector<Pixel> Vec;
    pair<unsigned int, unsigned int> MF_R;
    pair<unsigned int, unsigned int> MF_G;
    pair<unsigned int, unsigned int> MG_B;

};

#endif // ESTADISTICOS_H
