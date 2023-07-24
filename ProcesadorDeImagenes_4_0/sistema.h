/*!
 *  \class      Sistema
 *  \brief      Clase encargada de ejecutar el programa
 *  \details
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef SISTEMA_H
#define SISTEMA_H
#include "graficador.h"
#include "interfaz.h"
#include <QApplication>
#include <dirent.h>

using namespace std;

class Sistema
{
public:
    Sistema();
    /*!
     * \brief ejecutar es un metodo que se encarga de la ejecucion del programa.
     * \param pPtrApp es un puntero a un objeto QApplication encargado de la lanzar la ejecucion.
     */
    void ejecutar (QApplication* pPtrApp);
     /*!
    * \brief setDir es un metodo que obtiene los nombres de los archivos en el direcotio
    * \param pRutaDir contiene la ruta del directorio
    */
    void setDir(string pRutaDir);
    /*!
     * \brief setListadoDeArchivos es un metodo que obtiene la ruta de archivos en un directorio
     * \param pRuta representa la ruta de directorio.
     */
    void setListadoDeArchivos(string pRuta);
    /*!
     * \brief getListaDeArchivos me permite acceder a la lista de nombres de archivos.
     * \return Devuelve un vector de string que contiene la lista de nombres de archivos.
     */
    vector<string> getListaDeArchivos();
    /*!
     * \brief getListaRutasDeArchivos me permite acceder a la lista de rutas de archivos.
     * \return Devuelve un vector de string que contiene la lista de rutas de archivos.
     */
    vector<string> getListaRutasDeArchivos();


private:
    /*!
     * \brief listaRutasDeArchivos es un vector que almacena los nombres de archivos en el directorio
     */
    vector <string> listaRutasDeArchivos;
    /*!
     * \brief listaDeArchivos es un vector que almacena los nombres de la lista de archivos
     */
    vector <string> listaDeArchivos;
    /*!
     * \brief Dir almacena el directorio de la Carpeta
     */
    string Dir;
    /*!
     * \brief ui interacciona con el usuario
     */
    Interfaz ui;
    /*!
     * \brief graf es un objeto de tipo graficador encargado de la graficación del programa
     */
    Graficador graf;

};

#endif // SISTEMA_H
