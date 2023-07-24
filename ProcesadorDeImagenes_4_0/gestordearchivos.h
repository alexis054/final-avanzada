/*!
 *  \class      GestorDeArchivos
 *  \brief      Clase abstracta creada para leer y guardar archivos de imagenes.
 *  \details    Es una clase virtual pura.
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <fstream>
#include <string>
#include <iostream>
#include "imagen.h"

using namespace std;

class GestorDeArchivos
{
public:
    /*!
    * \brief Constructor de la clase GestorDeArchivos
    */
    GestorDeArchivos();
    /*!
    * \brief Metodo virtual puro para guardar imagen
    */
    Imagen virtual Cargar()=0;
    /*!
    * \brief metodo virtual puro para guardar imagen
    * \param pNombre: string con el nombre de la imagen a guardar
    * \param pImagen: paso por referencia la imagen a guardar
    */
    void virtual Guardar(string pNombre,string pFormato, Imagen &pImagen)=0;

    /*!
    * \brief Destructor de la clase
    */

    virtual ~GestorDeArchivos(){};

 };

#endif // GESTORDEARCHIVOS_H
