#include "imagen.h"

Imagen::Imagen()
{



}

//getters
    int Imagen::getM() const
{
    return M;
}

    int Imagen::getAncho() const
{
    return ancho;
}

    void Imagen::setM(int newM)
{
    M = newM;
}

    int Imagen::getAlto() const
{
    return alto;
}

    const string &Imagen::getMetadatos() const
{
    return metadatos;
}

//setters
void Imagen::setAlto(int newAlto)
{
    alto = newAlto;
}

void Imagen::setAncho(int newAncho)
{
    ancho = newAncho;
}


void Imagen::setMetadatos(const string &newMetadatos)
{
    metadatos = newMetadatos;
}
//metodos

    void Imagen::ModificarPixel(int pPosF,int pPosC,Pixel pPix)
{
    Img[pPosF][pPosC].setR(pPix.getR());
    Img[pPosF][pPosC].setG(pPix.getG());
    Img[pPosF][pPosC].setB(pPix.getB());
    }

    void Imagen::ModificarPixelTerna(int pPosF, int pPosC, float pR, float pG, float pB)
    {
        Img[pPosF][pPosC].setR(pR);
        Img[pPosF][pPosC].setG(pG);
        Img[pPosF][pPosC].setB(pB);
    }

    void Imagen::ReservarMemoria()
    {
        Pixel aux;
        Img.resize(alto);

         for(auto&  fila: Img)
         {
             fila.resize(ancho,aux);
         }
    }

    Pixel Imagen::getPixel(int pPosF, int pPosC)
{

 return Img[pPosF][pPosC];
    }

    const string &Imagen::getFormato() const
    {
        return Formato;
    }

    void Imagen::setFormato(const string &newFormato)
    {
        Formato = newFormato;
    }

