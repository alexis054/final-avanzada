#include "gestordearchivosaic.h"

GestorDeArchivosAIC::GestorDeArchivosAIC(string pRuta)
{
 Ruta=pRuta;
}

Imagen GestorDeArchivosAIC::Cargar()
{

    Imagen aux;
    ifstream archi;
    string formato;
    string metadatos;
    int M=0;
    int columnas=0;
    int filas=0;
    int Gris=0;
    int Repeticiones=0;

    archi.open(Ruta);
    if(archi.is_open())
    {
        getline(archi, formato, '\n');
        aux.setFormato(formato);

        getline(archi,metadatos,'\n');
        aux.setMetadatos(metadatos);

        archi>>columnas>>filas;
        aux.setAlto(filas);
        aux.setAncho(columnas);
        aux.ReservarMemoria();

        archi>>M;
        aux.setM(M);

        int col=0;

        for(int i=0;i<filas;++i)
        {
            while(col<columnas)
            {
                archi>>Gris>>Repeticiones;


                for(int j=0;j<Repeticiones;++j)
                {
                    aux.ModificarPixelTerna(i,col+j,Gris,Gris,Gris);
                }

            col=col+Repeticiones;

            }

            col=0;
        }

    archi.close();
    }

    return aux;
}


void GestorDeArchivosAIC::Guardar(string pNombre,string pFormato, Imagen &pImagen)
{
   ofstream archi;
   int filas=pImagen.getAlto();
   int columnas=pImagen.getAncho();
   int count=1;
   int Gris1;
   int Gris2;

   archi.open("../ProcesadorDeImagenes_4_0/Nuevas/"+pNombre);
   if(archi.is_open())
   {
       archi<<pFormato<<"\n";
       archi<<pImagen.getMetadatos()<<"\n";
       archi<<columnas<<" "<<filas<<"\n";
       archi<<pImagen.getM()<<"\n";

       for(int i=0;i<filas;++i)
       {
           for(int j=0;j<columnas;++j)
           {
               Gris1=pImagen.getPixel(i,j).intensidad();

               if(count == 1)
                   archi<<Gris1<<" ";


               if(j+1<columnas)
                   Gris2=pImagen.getPixel(i,j+1).intensidad();

               else
                   Gris2=Gris1+1;

               if(Gris1==Gris2)
                   ++count;
               else
               {
                   archi<<count<<" ";
                   count=1;
               }
           }
           archi<<"\n";
           count=1;
       }
   archi.close();
   }


}
