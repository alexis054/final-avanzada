/*!
 *  \class      Lut
 *  \brief      Clase encargada de modificar los pixeles de una imagen a partir de las tablas de lut
 *  \details    Modifica pixeles segun las tablas de lut
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef LUT_H
#define LUT_H
#include "imagen.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Lut
{
public:
    Lut();
    /*!
     * \brief cargar es une metodo que lee los datos de lut y las carga
     * \param pNum representa el numero de tabla que se desea leer
     */
    void cargar(int pNum);
    /*!
     * \brief modificarImg es un metodo que modifica la imagen segun la tabla de lut
     * \param pImagen es una referecia a un objeto Imagen a modificar
     */
    void modificarimg(Imagen &pImagen);
private:
    /*!
     * \brief lut es una matriz que almacena la tabla de lut
     */
    vector<vector<float>> lut;
};

#endif // LUT_H
