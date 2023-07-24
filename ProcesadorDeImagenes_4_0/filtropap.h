/*!
 *  \class      FiltroPaP
 *  \brief      Clase creada con el fin de aplicar los filtros punto a punto a una imagen
 *  \details    aplica filtros de birllo, contraste y binarizado
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef FILTROPAP_H
#define FILTROPAP_H
#include "estadisticos.h"


class FiltroPaP
{
public:
    FiltroPaP();
    /*!
     * \brief AumentarBrillo es un metodo que moidifica los pixeles de la imagen permitiendo aumentarle el brillo
     * \param pImagen es una referencia a la imagen que se va a modificar
     */
    void AumentarBrillo(Imagen &pImagen);
    /*!
     * \brief DisminuirBrillo es un metodo que moidifica los pixeles de la imagen permitiendo disminuirle el brillo
     * \param pImagen es una referencia a la imagen que se va a modificar
     */
    void DisminuirBrillo(Imagen &pImagen);
    /*!
     * \brief Contraste es un metodo que modifica los pixeles de la imagen permitiendo aumentar el contraste de esta
     * \param pImagen es una referencia a la imagen que se va a modificar
     */
    void Contraste(Imagen &pImagen);
    /*!
     * \brief Binarizar es un metodo que moidifica los pixeles de la imagen permitiendo, a partir de una tolerancia, binarizar la imagen
     * en dos valores, o blanco o negro
     * \param pImagen es una referencia a la imagen que se va a modificar
     */
    void Binarizar (Imagen &pImagen);


private:
    /*!
     * \brief db es un valor arbitrario con el que se van a modificar los pixeles para el brillo
     */
    float db=10;//valor arbitrario, diferencial brillo


};

#endif // FILTROPAP_H
