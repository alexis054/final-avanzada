#include "filtroespacial.h"

FiltroEspacial::FiltroEspacial()
{

}

void FiltroEspacial::filtradoMediana(Imagen &pImagen)
{
    Imagen imgGuardar = pImagen;//Guardo la imagen sin filtrar


    vector<int> auxR;
    vector<int> auxG;
    vector<int> auxB;

    int R,G,B;


    for(int i=1;i<pImagen.getAlto()-1;++i)
    {
        for(int j=1;j<pImagen.getAncho()-1;++j)
        {
         auxR.clear();

         auxR.push_back(pImagen.getPixel(i-1,j+1).getR());
         auxR.push_back(pImagen.getPixel(i,j+1).getR());
         auxR.push_back(pImagen.getPixel(i+1,j+1).getR());
         auxR.push_back(pImagen.getPixel(i+1,j).getR());
         auxR.push_back(pImagen.getPixel(i+1,j-1).getR());
         auxR.push_back(pImagen.getPixel(i,j-1).getR());
         auxR.push_back(pImagen.getPixel(i-1,j-1).getR());
         auxR.push_back(pImagen.getPixel(i-1,j).getR());
         auxR.push_back(pImagen.getPixel(i,j).getR());



         auxG.clear();

         auxG.push_back(pImagen.getPixel(i-1,j+1).getG());
         auxG.push_back(pImagen.getPixel(i,j+1).getG());
         auxG.push_back(pImagen.getPixel(i+1,j+1).getG());
         auxG.push_back(pImagen.getPixel(i+1,j).getG());
         auxG.push_back(pImagen.getPixel(i+1,j-1).getG());
         auxG.push_back(pImagen.getPixel(i,j-1).getG());
         auxG.push_back(pImagen.getPixel(i-1,j-1).getG());
         auxG.push_back(pImagen.getPixel(i-1,j).getG());
         auxG.push_back(pImagen.getPixel(i,j).getG());


         auxB.clear();

         auxB.push_back(pImagen.getPixel(i-1,j+1).getB());
         auxB.push_back(pImagen.getPixel(i,j+1).getB());
         auxB.push_back(pImagen.getPixel(i+1,j+1).getB());
         auxB.push_back(pImagen.getPixel(i+1,j).getB());
         auxB.push_back(pImagen.getPixel(i+1,j-1).getB());
         auxB.push_back(pImagen.getPixel(i,j-1).getB());
         auxB.push_back(pImagen.getPixel(i-1,j-1).getB());
         auxB.push_back(pImagen.getPixel(i-1,j).getB());
         auxB.push_back(pImagen.getPixel(i,j).getB());

         sort(auxR.begin(),auxR.end());
         sort(auxG.begin(),auxG.end());
         sort(auxB.begin(),auxB.end());

         R=auxR[auxR.size()/2];
         G=auxG[auxG.size()/2];
         B=auxB[auxB.size()/2];



         pImagen.ModificarPixelTerna(i,j,R,G,B);
        }
    }



}

void FiltroEspacial::filtradoSuavizado(Imagen &pImagen)
{
    int R,G,B;

    for(int i=1;i<pImagen.getAlto()-1;++i)
    {
        for(int j=1;j<pImagen.getAncho()-1;++j)
        {
            R=(pImagen.getPixel(i-1,j+1).getR()+pImagen.getPixel(i,j+1).getR()+ pImagen.getPixel(i+1,j+1).getR()+pImagen.getPixel(i+1,j).getR()
               +pImagen.getPixel(i+1,j-1).getR()+pImagen.getPixel(i,j-1).getR()+pImagen.getPixel(i-1,j-1).getR()+pImagen.getPixel(i-1,j).getR()
               +pImagen.getPixel(i,j).getR())*(1.0/9);


            G=(pImagen.getPixel(i-1,j+1).getG()+pImagen.getPixel(i,j+1).getG()+pImagen.getPixel(i+1,j+1).getG()+pImagen.getPixel(i+1,j).getG()
              +pImagen.getPixel(i+1,j-1).getG()+pImagen.getPixel(i,j-1).getG()+pImagen.getPixel(i-1,j-1).getG()+pImagen.getPixel(i-1,j).getG()
              +pImagen.getPixel(i,j).getG())*(1.0/9);


            B=(pImagen.getPixel(i-1,j+1).getB()+pImagen.getPixel(i,j+1).getB()+pImagen.getPixel(i+1,j+1).getB()+pImagen.getPixel(i+1,j).getB()
              +pImagen.getPixel(i+1,j-1).getB()+pImagen.getPixel(i,j-1).getB()+pImagen.getPixel(i-1,j-1).getB()+pImagen.getPixel(i-1,j).getB()
               +pImagen.getPixel(i,j).getB())*(1.0/9);


            pImagen.ModificarPixelTerna(i,j,R,G,B);

        }
    }
}
