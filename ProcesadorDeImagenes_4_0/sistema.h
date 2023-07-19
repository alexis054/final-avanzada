#ifndef SISTEMA_H
#define SISTEMA_H
#include "gestordearchivospnm.h"
#include "graficador.h"
#include "interfaz.h"
#include <QApplication>
#include <iostream>
#include <dirent.h>

using namespace std;

class Sistema
{
public:
    Sistema();
   void ejecutar (QApplication* pPtrApp);//ejecuta el programa

    void setDir(string pRutaDir);//se encarga de obtener los nombres de los  archivos de un directorio

    void setSubDir(string pRuta);//hace un barrido de directorios y guarda los  archivos en esa ruta

    vector<string> getListaDeArchivos();//para acceder a lista de nombre de archivos

    vector<string> getListaRutasDeArchivos();//  me permite acceder a la lista de directorios


private:

  //  Graficador graf;
    vector <string> listaRutasDeArchivos;
    vector <string> listaDeArchivos;
    string Dir;
    Interfaz ui;

};

#endif // SISTEMA_H
