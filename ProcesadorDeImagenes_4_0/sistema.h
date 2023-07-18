#ifndef SISTEMA_H
#define SISTEMA_H
#include "gestordearchivospnm.h"
#include "graficador.h"
#include "dirent.h"
#include "interfaz.h"
#include <QApplication>
#include <iostream>

using namespace std;

class Sistema
{
public:
    Sistema();
    void ejecutar (QApplication* pPtrApp);
    void setDir(string pRutaDir);
    void setSubDir(string pRuta);

    vector<string> setListaDeArchivos;
    vector<string> getListaDeArchivos;

    const vector<string> &getGetListaDeArchivos() const;
    void setGetListaDeArchivos(const vector<string> &newGetListaDeArchivos);


private:

    Graficador graf;
    vector<string> listaRutasDeArchivos;
    vector<string> listadearchivos;
    string Dir;
    Interfaz inter;

};

#endif // SISTEMA_H
