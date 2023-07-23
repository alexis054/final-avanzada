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



void FiltroPaP::Contraste(Imagen &pImagen)
{
    Estadisticos stat;
    stat.setDatos(pImagen);
    int R,G,B;


    for(int i=0;i<pImagen.getAlto();++i)
    {
       for(int j=0;j<pImagen.getAncho();++j)
        {
          R=((pImagen.getPixel(i,j).getR()-stat.Min_R())/(stat.Max_R()-stat.Min_R()));
        //  G=((pImagen.getPixel(i,j).getG()-stat.Min_G()/(stat.Max_G()-stat.Min_G())));
        //  B=((pImagen.getPixel(i,j).getB()-stat.Min_B()/(stat.Max_B()-stat.Min_B())));
               // cout<<endl;
         cout<<"Valor Rojo contraste: "<<R<<endl;
         // cout<<(pImagen.getPixel(i,j).getR()-stat.Min_R());
        if( R<255 and R>0 )
//            and G<=255 and  B<=255and G>0 and B>0
          pImagen.ModificarPixelTerna(i,j,R,1,1);
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

