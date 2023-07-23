#include "filtropap.h"

FiltroPaP::FiltroPaP()
{

}

void FiltroPaP::AumentarBrillo(Imagen &pImagen)
{
    float R,G,B;

    for(int i=0;i<pImagen.getAlto();++i)
    {
        for(int j=0;j<pImagen.getAncho();++j)
        {
            if((pImagen.getPixel(i,j).getR()+db)<255)
            R=pImagen.getPixel(i,j).getR()+db;
            else
                R=pImagen.getPixel(i,j).getR();

            if(pImagen.getPixel(i,j).getG()+db<=255)
            G=pImagen.getPixel(i,j).getG()+db;
            else
                 G=pImagen.getPixel(i,j).getG();

            if(pImagen.getPixel(i,j).getB()+db<=255)
            B=pImagen.getPixel(i,j).getB()+db;
            else
                B=pImagen.getPixel(i,j).getB();

            pImagen.ModificarPixelTerna(i,j,R,G,B);
        }
    }
}

void FiltroPaP::DisminuirBrillo(Imagen &pImagen)
{
    float R,G,B;

    for(int i=0;i<pImagen.getAlto();++i)
    {
        for(int j=0;j<pImagen.getAncho();++j)
        {
            if((pImagen.getPixel(i,j).getR()-db)>=0)
            R=pImagen.getPixel(i,j).getR()-db;
            else
                R=pImagen.getPixel(i,j).getR();

            if(pImagen.getPixel(i,j).getG()-db>=0)
            G=pImagen.getPixel(i,j).getG()-db;
            else
                 G=pImagen.getPixel(i,j).getG();

            if(pImagen.getPixel(i,j).getB()-db>=0)
            B=pImagen.getPixel(i,j).getB()-db;
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
    int R_max;
    int G_max;
    int B_max;
    int R_min;
    int G_min;
    int B_min;
    int M;

     M=pImagen.getM();

    R_max=stat.Max_R();
    G_max=stat.Max_G();
    B_max=stat.Max_B();

    R_min=stat.Min_R();
    G_min=stat.Min_G();
    B_min=stat.Min_B();

    for(int i=0;i<pImagen.getAlto();++i)
    {
       for(int j=0;j<pImagen.getAncho();++j)
      {
         R=(float)(((float)(pImagen.getPixel(i,j).getR()-R_min)/(float)(R_max-R_min))*M);
         G=(float)(((float)(pImagen.getPixel(i,j).getG()-G_min)/(float)(G_max-G_min))*M);
         B=(float)(((float)(pImagen.getPixel(i,j).getB()-B_min)/(float)(B_max-B_min))*M);


        if( R<255 and R>0  and G<=255 and  B<=255 and G>0 and B>0)
          pImagen.ModificarPixelTerna(i,j,R,G,B);

       }
    }

}

void FiltroPaP::Binarizar(Imagen &pImagen)
{
    int valor;
   int intenUmbral=255/2;

  for(int i=0;i<pImagen.getAlto();++i)
  {
      for(int j=0; j<pImagen.getAncho();++j)
      {
          if(pImagen.getPixel(i,j).intensidad()>intenUmbral)
          {
              valor=pImagen.getM();
          }
          else
              valor=0;
        pImagen.ModificarPixelTerna(i,j,valor,valor,valor);
      }
  }
}

