#include "gestordearchivospnm.h"

GestorDeArchivosPNM::GestorDeArchivosPNM(string pRuta)
{
    Ruta=pRuta;
}

Imagen GestorDeArchivosPNM::Cargar()
{
    //defino las variables
    Imagen aux;
    ifstream archi;
    string formato;
    string metadatos;

    int valorBool=0;

   int pos;
   int columnas=0;
   int filas=0;
   int M=0;


    //abro el archivo
    archi.open(Ruta);

    //pruebo si abre el archivo
    try
    {

        if(archi.is_open()!=true)

            throw runtime_error("Fallo en abrir archivo PNM");                        //si no lo abre se devuelve el valor 1



        else                                //caso contrario se entra al else
        {
           archi.seekg(0,ios::beg);

            getline(archi,formato,'\n');    //leo el formato hasta que encuetre final de linea
            aux.setFormato(formato);


            getline(archi,metadatos,'\n');  //leo metadatos
            aux.setMetadatos(metadatos);



            if(metadatos=="")
            {
                throw 2; //si los metadatos no se cargan arroja el valor 2
            }
            archi>>columnas;
            archi>>filas;
            //se carga los parametros de la imagen

            aux.setAlto(filas);
            aux.setAncho(columnas);

            if(filas==0||columnas==0)
            {
                throw 3;//si no se cargan las columnas se arroja el valor 3

            }

            aux.ReservarMemoria();//genera una matriz de pixeles de la dimension ancho x alto

            if(formato!="P1" && formato!="P4")//guardo el rango, los monos no tienen

            {

                archi>>M;

            }

            else
                M=1;

            aux.setM(M);//asigno rango dinamico

            if(formato == "P1")//monocromatica y txt
            {
                for(int i=0;i<filas ; ++i)

                {
                    for(int j=0;j<columnas;++j)
                    {
                        archi>>valorBool;

                        if(valorBool!=0)
                        {
                            valorBool=1;
                        }
                        aux.ModificarPixelTerna(i,j,valorBool,valorBool,valorBool);
                    }

                }
            }

            if(formato == "P2")//escala gris y txt
            {
                for(int i=0;i<filas ; ++i)

                {
                    for(int j=0;j<columnas;++j)
                    {

                      //  archi>>valorGrises;
                      //  aux.ModificarPixelTerna(i,j,valorGrises/M,valorGrises/M,valorGrises/M);

                    }

                }

            }
            if(formato == "P3")//rgb y txt
            {

                 int valorPixR=0;
                 int valorPixG=0;
                 int valorPixB=0;

                for(int i=0;i<filas ; ++i)

                {
                    for(int j=0;j<columnas;++j)
                    {
                        archi>>valorPixR>>valorPixG>>valorPixB;
                        aux.ModificarPixelTerna(i,j,valorPixR/M,valorPixB/M,valorPixG/M);
                    }

                }

            }



            if(formato=="P4"||formato=="P5"||formato=="P6")
            {

                pos=archi.tellg();
                ifstream archibin(Ruta,ios::in|ios::binary);

                if(archibin.is_open())
                {
                    archibin.seekg(pos+1,ios::beg);

                    if(formato== "P4")
                    {
                        for(int i=0;i<filas;++i)
                        {
                            for(int j=0;j<columnas;++j)
                            {
                                archibin.read((char*)& valorBool,sizeof (valorBool));

                                if(valorBool!=0)
                                {
                                    valorBool=1;
                                }
                                aux.ModificarPixelTerna(i,j,valorBool,valorBool,valorBool);
                            }
                        }
                    }
                    if(formato=="P5")
                    {
                       unsigned  char GrisesChr=0;
                         int Gris=0;

                        for(int i=0;i<filas ;++i)
                        {

                            for(int j=0;j<columnas;++j)
                            {
                                archibin.read((char*)& GrisesChr,sizeof (GrisesChr));
                                Gris=(int)GrisesChr;
                                aux.ModificarPixelTerna(i,j,Gris,Gris,Gris);

                            }

                        }
                    }

                    if(formato == "P6")
                    {
                        int rojo=0;
                        int verde=0;
                        int azul=0;

                        unsigned char valorPixR=0;
                        unsigned char valorPixG=0;
                        unsigned char valorPixB=0;

                        for(int i=0;i<filas;++i)
                        {
                            for(int j=0;j<columnas;++j)
                            {
                                archibin.read((char*)& valorPixR,sizeof (unsigned char));
                                archibin.read((char*)& valorPixG,sizeof (unsigned char));
                                archibin.read((char*)& valorPixB,sizeof (unsigned char));

                                rojo=(int)valorPixR;   //casteo de char a int
                                verde=(int)valorPixG;
                                azul=(int)valorPixB;

                                aux.ModificarPixelTerna(i,j,rojo,verde,azul);

                            }

                        }
                    }
                    archibin.close();
                }
                archi.close();
            }
        }

    }
    catch (int i)
    {
        if(i==1)

            cout<<"no se pudo abrir el archivo";

        if(i==2)

            cout<<"La imagen no cuenta con metadatos";

    }


    return aux;
}

void GestorDeArchivosPNM::Guardar()
{

}
