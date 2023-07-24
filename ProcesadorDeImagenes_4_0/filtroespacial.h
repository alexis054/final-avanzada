/*!
 *  \class      FiltroEspacial
 *  \brief      Clase creada con el fin de aplicar los filtros espaciales a una imagen
 *  \details    aplica filtros de mediana y suavizado
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef FILTROESPACIAL_H
#define FILTROESPACIAL_H
#include "estadisticos.h"

using namespace std;

class FiltroEspacial
{
public:
    FiltroEspacial();
    /*!
     * \brief filtradoMediana es un metodo que se encarga de aplicar el filtro de mediana a la imagen
     * \param pImagen es la imagen que va a ser modificada
     */
    void filtradoMediana(Imagen &pImagen);
    /*!
     * \brief filtradoMediana es un metodo que se encarga de aplicar el filtro de mediana a la imagen
     * \param pImagen es la imagen que va a ser modificada
     */
    void filtradoSuavizado(Imagen &pImagen);

};

#endif // FILTROESPACIAL_H
