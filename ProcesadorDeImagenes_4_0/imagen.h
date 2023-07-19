#ifndef IMAGEN_H
#define IMAGEN_H
#include "pixel.h"
#include <vector>
#include <string>

using namespace std;

class Imagen
{
public:
    Imagen();

//Getters

    int getM() const;
    int getAlto() const;
    int getAncho() const;
    const string &getMetadatos() const;

//Setters

    void setM(int newM);
    void setAlto(int newAlto);
    void setAncho(int newAncho);
    void setMetadatos(const string &newMetadatos);

 //metodos

    void ModificarPixel(int pPosF,int pPosC, Pixel pPix);
    void ModificarPixelTerna(int pPosF, int pPosC, int pR, int pG, int pB);
    void ReservarMemoria();
    Pixel getPixel(int pPosF,int pPosC);


    const string &getFormato() const;
    void setFormato(const string &newFormato);

private:
    vector<vector<Pixel>> Img;
    int M;
    int alto;
    int ancho;
    string metadatos;
    string Formato;


};

#endif // IMAGEN_H
