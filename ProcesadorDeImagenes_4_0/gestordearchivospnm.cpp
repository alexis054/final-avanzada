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

            throw runtime_error("Fallo en abrir archivo PNM");  //si no lo abre se devuelve el valor 1



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
                int valorBool=0;

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
                int Gris=0;

                for(int i=0;i<filas ; ++i)
                {
                    for(int j=0;j<columnas;++j)
                    {
                        archi>>Gris;
                        aux.ModificarPixelTerna(i,j,Gris,Gris,Gris);
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
                archi.close();
                ifstream archi(Ruta,ios::binary);

                if(archi.is_open())
                {
                    archi.seekg(pos+1,ios::beg);

                    if(formato== "P4")
                    {
                        int valorBool=0;

                        for(int i=0;i<filas;++i)
                        {
                            for(int j=0;j<columnas;++j)
                            {
                                archi.read((char*)& valorBool,sizeof (valorBool));

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
                                archi.read((char*)& GrisesChr,sizeof (GrisesChr));
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
                                archi.read((char*)& valorPixR,sizeof (unsigned char));
                                archi.read((char*)& valorPixG,sizeof (unsigned char));
                                archi.read((char*)& valorPixB,sizeof (unsigned char));

                                rojo=(int)valorPixR;   //casteo de char a int
                                verde=(int)valorPixG;
                                azul=(int)valorPixB;

                                aux.ModificarPixelTerna(i,j,rojo,verde,azul);

                            }
                        }
                    }
                }
            }
            archi.close();
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

void GestorDeArchivosPNM::Guardar(string pNombre,string pFormato, Imagen &pImagen)
{
    ofstream archi;
    string metadatos;

    archi.open(pNombre);

    if(archi.is_open())
    {
        archi<<pFormato<<endl;
        archi<<pImagen.getMetadatos()<<endl;
        archi<<pImagen.getAncho()<<" "<<pImagen.getAlto()<<endl;
        archi<<pImagen.getM();

    }
    if(pFormato=="P1")
    {
        int auxMono;

        for(int i=0;i<pImagen.getAlto();++i)
        {
            for(int j=0;j<pImagen.getAncho();++j)
            {
                auxMono=pImagen.getPixel(i,j).intensidad();

                if(auxMono!=0)
                {
                    auxMono=1;//Normalizo los valores monocromáticos a 0 y 1 únicamente
                }
                archi<<auxMono<<" ";
            }
            archi<<"\n";
        }
    }

    if(pFormato=="P2")
    {
        for(int i=0;i<pImagen.getAlto();++i)
        {
            for(int j=0;j<pImagen.getAncho();++j)
            {
                archi<<pImagen.getPixel(i,j).intensidad()<<" ";
                archi<<"\n";
            }
        }
        archi.close();
    }


    if(pFormato=="P3")
    {
        for(int i=0;i<pImagen.getAlto();++i)
        {
            for(int j=0;j<pImagen.getAncho();++j)
            {
                archi<<pImagen.getPixel(i,j).getR()<<" ";
                archi<<pImagen.getPixel(i,j).getG()<<" ";
                archi<<pImagen.getPixel(i,j).getB()<<" ";
            }

            archi<<"\n";
        }
        archi.close();
    }



    if(pFormato=="P4" or pFormato=="P5" or pFormato=="P6")
    {
        int pos=0;
        pos=archi.tellp();
        archi.close();

        archi.open(pNombre, ios::binary);
        archi.seekp(pos);


        if(pFormato=="P4")
        {
            char valorCanal;
            int auxMono;

            for (int i=0; i < pImagen.getAlto(); ++i)
            {
                for (int j=0; j<pImagen.getAncho(); ++j)
                {
                    auxMono=pImagen.getPixel(i,j).intensidad();

                    if(auxMono!=0)
                    {
                        auxMono=1; //Normalizo los valores monocromáticos a 0 y 1 únicamente
                    }

                    valorCanal=auxMono;
                    archi.write((char*)&valorCanal, sizeof(valorCanal));
                }
            }
        }



        if(pFormato=="P5")
        {
            char valorCanal;

            for (int i = 0; i < pImagen.getAlto(); ++i)
            {
                for (int j = 0; j < pImagen.getAncho(); ++j)
                {
                    valorCanal=pImagen.getPixel(i,j).intensidad();
                    archi.write((char*)&valorCanal, sizeof(valorCanal));
                }
            }
        }

        if(pFormato=="P6")
        {
            char valorCanalR,valorCanalG,valorCanalB;

            for (int i = 0; i < pImagen.getAlto(); ++i)
            {
                for (int j= 0; j < pImagen.getAncho(); ++j)
                {

                    valorCanalR=pImagen.getPixel(i,j).getR();
                    valorCanalR=pImagen.getPixel(i,j).getG();
                    valorCanalR=pImagen.getPixel(i,j).getB();

                    archi.write((char*)&valorCanalR, sizeof(valorCanalR));
                    archi.write((char*)&valorCanalG, sizeof(valorCanalG));
                    archi.write((char*)&valorCanalB, sizeof(valorCanalB));
                }
            }
        }
    }
    archi.close();
}
