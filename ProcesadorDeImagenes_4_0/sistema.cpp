#include "sistema.h"

Sistema::Sistema()
{

}

void Sistema::ejecutar(QApplication *pPtrApp)
{
    Imagen img;
    GestorDeArchivosPNM gda("../ProcesadorDeImagenes_4_0/grupo_imagenes_1/test_01.pgm");
    img=gda.Cargar();

    graf.setImagen(img);

    graf.mostrar(img.getAncho(),img.getAlto(),pPtrApp);

}

void Sistema::setDir(string pRutaDir)
{

}

void Sistema::setSubDir(string pRuta)
{

}

const vector<string> &Sistema::getGetListaDeArchivos() const
{
    return getListaDeArchivos;
}

void Sistema::setGetListaDeArchivos(const vector<string> &newGetListaDeArchivos)
{
    if (getListaDeArchivos == newGetListaDeArchivos)
        return;
    getListaDeArchivos = newGetListaDeArchivos;

}
