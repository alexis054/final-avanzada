#include "sistema.h"

Sistema::Sistema()
{
cout<<"AAAAA";
}

void Sistema::ejecutar(QApplication *pPtrApp)
{
  /*  unsigned int opcion=0;
    string raiz="../imagenes/";
//    Imagen img;
//    GestorDeArchivosPNM gda("../imagenes/grupo_imagenes_2/entre_rios_02.ppm");
//    img=gda.Cargar();

//    graf.setImagen(img);

//    graf.mostrar(img.getAncho(),img.getAlto(),pPtrApp);

    while(opcion <=4)
    {
        cout<<"Elija una opcion:  ";
        cin>>opcion;
        cout<<endl<<endl;

        switch (opcion){
        case 1:
        {
            Dir = raiz + "grupo_imagenes_1/";
            break;
        }
        case 2:
        {
            Dir = raiz + "grupo_imagenes_2/";
            break;
        }
        case 3:
        {
           Dir = raiz + "grupo_imagenes_3_corruptas/";
            break;
        }
        case 4:
        {
            Dir = raiz + "ij_image_samples/";
            break;
        }
        case 5:
        {
            Dir = raiz + "imagenes_Modificadas/";
            break;
        }
        case 6:
        {
            cout<< " Decidio Salir del programa! "<<endl;
            exit(0);
            break;
        }
     }
        setDir(Dir);*/

   Graficador graf;
    Imagen img;
       GestorDeArchivosPNM gda("../imagenes/grupo_imagenes_2/entre_rios_02.ppm");
       img=gda.Cargar();

       graf.setImagen(img);

       graf.mostrar(img.getAncho(),img.getAlto(),pPtrApp);

}

void Sistema::setDir(string pRutaDir)
{
    setSubDir(pRutaDir);

    listaRutasDeArchivos.resize(listaDeArchivos.size());

    for(int i=0; i< int(listaDeArchivos.size()); i++)
    {
     //listaDeArchivos va a tener: entre_rios_03.ppm
        listaRutasDeArchivos[i]= Dir + listaDeArchivos[i];
    }

   }

void Sistema::setSubDir(string pRutaDir)
{
    DIR *dir = opendir(pRutaDir.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                listaDeArchivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
}


vector<string> Sistema::getListaDeArchivos()
{
    return listaDeArchivos;
}

vector<string> Sistema::getListaRutasDeArchivos()
{
    return listaRutasDeArchivos;
}
