#include "filtropap.h"

FiltroPaP::FiltroPaP()
{

}

void FiltroPaP::Brillo(Imagen &pImagen)
{
    float R,G,B;

    for(int i=0;i<pImagen.getAlto();++i)
    {
        for(int j=0;j<pImagen.getAncho();++j)
        {
            if((pImagen.getPixel(i,j).getR()+db)<=1)
            R=pImagen.getPixel(i,j).getR()+db;
            else
                R=pImagen.getPixel(i,j).getR();

            if(pImagen.getPixel(i,j).getG()+db<=1)
            G=pImagen.getPixel(i,j).getG()+db;
            else
                 G=pImagen.getPixel(i,j).getG();

            if(pImagen.getPixel(i,j).getB()+db<=1)
            B=pImagen.getPixel(i,j).getB()+db;
            else
                B=pImagen.getPixel(i,j).getB();

            pImagen.ModificarPixelTerna(i,j,R,G,B);
        }
    }
}



void FiltroPaP::Contraste(Imagen &pImagen)
{
    Estadisticos stat;
    stat.setDatos(pImagen);
    float R,G,B;


    for(int i=0;i<pImagen.getAlto();++i)
    {
       for(int j=0;j<pImagen.getAncho();++j)
        {
          R=((pImagen.getPixel(i,j).getR()-stat.Min_R()));//(stat.Max_R()-stat.Min_R()))*pImagen.getM());
          //G=((pImagen.getPixel(i,j).getG()-stat.Min_G()/(stat.Max_G()-stat.Min_G()))*pImagen.getM());
         // B=((pImagen.getPixel(i,j).getB()-stat.Min_B()/(stat.Max_B()-stat.Min_B()))*pImagen.getM());

          pImagen.ModificarPixelTerna(i,j,R,0,0);
       }
    }
}

void FiltroPaP::Binarizar(Imagen &pImagen)
{

}

