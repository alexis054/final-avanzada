#include "pixel.h"

Pixel::Pixel()
{
    R=0;
    G=0;
    B=0;

    RGB.resize(3);
}
//________________________________________________________________________________________________________________________
//                                             Getters
//-------------------------------------------------------------------------------------------------------------------------


int Pixel::getB() const
{
    return B;
}

int Pixel::getR() const
{
    return R;
}

int Pixel::getG() const
{
    return G;
}


//_________________________________________________________________________________________________________________________
//                                             Setters
//-------------------------------------------------------------------------------------------------------------------------

void Pixel::setR(int newR)
{
    R = newR;
    RGB[0]=R;
}

void Pixel::setG(int newG)
{
    G = newG;
    RGB[1]=G;
}

void Pixel::setB(int newB)
{
    B = newB;
    RGB[2]=B;
}

int Pixel::operator [](int pos)
{
    return RGB[pos];
}
Pixel Pixel::operator +(Pixel &pPix)
{
    Pixel aux;

    aux.setR(this->R+pPix.getR());
    aux.setG(this->G+pPix.getG());
    aux.setB(this->B+pPix.getB());

   return aux;
}

 Pixel Pixel::operator /(const int pConstante)
 {
     Pixel aux;

     aux.setR(this->R/pConstante);
     aux.setG(this->G/pConstante);
     aux.setB(this->B/pConstante);

     return aux;
 }
//--------------------------------------------------------------------------------------------------------------------------

float Pixel::modulo()
{
    float modulo;

        modulo=sqrt((R*R)+(G*G)+(B*B));

        return modulo;
}

int Pixel::intensidadRGB()
{


    int acum=0;
    int val;

    for(int k=0;k<3;k++){
     acum=acum+RGB[k];
    }
    val=(acum/3);

    return val;


}

int Pixel::getIntensidadGris()
{

    return RGB[0];
}


bool Pixel:: operator <(Pixel &pComp)

{
   return this->intensidadRGB()<pComp.intensidadRGB();
}
