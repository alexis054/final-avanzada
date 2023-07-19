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
    map<float,int> Hist_G();
    map<float,int> Hist_B();


//Promedios
    float Promedio_Intensidad();
    float Promedio_R();
    float Promedio_G();
    float Promedio_B();

 //medidas de tendencia central
    Pixel Moda();
    Pixel Mediana();
    float MedianaR();
    float MedianaG();
    float MedianaB();
    vector<float> DesvioSTD();
    int IntenMediaTotal();



//maximos y minimos
    float Max_Intensidad();
    float Min_Intensidad();

    float Max_R();
    float Max_G();
    float Max_B();

    float Min_R();
    float Min_G();
    float Min_B();

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
