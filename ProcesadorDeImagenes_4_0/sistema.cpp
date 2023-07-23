#include "sistema.h"

Sistema::Sistema()
{

}

void Sistema::ejecutar(QApplication *pPtrApp)
{
    unsigned int opcion=1;
    string raiz="../ProcesadorDeImagenes_4_0/";

    while(opcion <=4)
    {
        ui.mostrarDir();
        opcion=ui.getOpcion();

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
            Dir = raiz + "Nuevas/";
            break;
        }
        case 6:
        {
            cout<< " Decidio Salir del programa! "<<endl;
            exit(0);
            break;
        }
        }

      setDir(Dir);
      ui.mostrarListaImagenes(getListaDeArchivos());

      graf.setListaDeArchivos(listaDeArchivos);
      graf.setListaRutas(listaRutasDeArchivos);
      graf.setImagen();

      ui.getKeyBindings();
      graf.mostrar(pPtrApp);

      opcion=0;
      listaDeArchivos.clear();
      listaRutasDeArchivos.clear();





//   Graficador graf;
//    Imagen img;
//       GestorDeArchivosPNM gda("../imagenes/grupo_imagenes_2/entre_rios_01.pgm");
//       img=gda.Cargar();

//       graf.setImagen(img);

//       graf.mostrar(img.getAncho(),img.getAlto(),pPtrApp);

    }
}

void Sistema::setDir(string pRutaDir)
{
    setListadoDeArchivos(pRutaDir);//cargo el vector

    listaRutasDeArchivos.resize(listaDeArchivos.size());// dimensiono el vector de rutas de imagenes

    for(int i=0; i< int(listaDeArchivos.size()); i++)
    {

        listaRutasDeArchivos[i]= Dir + listaDeArchivos[i];//asigno la ruta a cada imagen

    }

   }

void Sistema::setListadoDeArchivos(string pRutaDir) // carga el vector listaDeArchivos con strings de los nombres de imagens
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
