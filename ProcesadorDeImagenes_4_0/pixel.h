#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Pixel
{
public:
    Pixel();

    int getB() const;
    int getR() const;
    int getG() const;

    float modulo();
    int intensidad();



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
