#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Pixel
{
public:
    Pixel();

    int getB() const;
    int getR() const;
    int getG() const;

    float modulo();
    int intensidadRGB();
    int getIntensidadGris();


    void setR(int newR);
    void setG(int newG);
    void setB(int newB);

    int operator [](int pos);
    bool operator <(Pixel &pComp);
    Pixel operator +(Pixel &pPix);
    Pixel operator /(const int pConstante);

private:
    int R,G,B;
    vector<int> RGB;
};

#endif // PIXEL_H
