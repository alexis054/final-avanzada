#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <math.h>

using namespace std;

class Pixel
{
public:
    Pixel();

    float getB() const;
    float getR() const;
    float getG() const;

    float modulo();
    float intensidadRGB();
    int getIntensidadGris();


    void setR(float newR);
    void setG(float newG);
    void setB(float newB);

    float operator [](int pos);
    bool operator <(Pixel &pComp);
    Pixel operator +(Pixel &pPix);
    Pixel operator /(const int pConstante);

private:
    float R,G,B;
    vector<float> RGB;
};

#endif // PIXEL_H
