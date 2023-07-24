/*!
 *  \class      GestorDeArchivosAIC
 *  \brief      Clase Encargada de escribir y leer archivos con imagenes tipo AIC
 *  \details    Es una clase hija de GestorDeArchivos.
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef GESTORDEARCHIVOSAIC_H
#define GESTORDEARCHIVOSAIC_H
#include "gestordearchivos.h"

class GestorDeArchivosAIC:public GestorDeArchivos
{
public:
    /*!
         * \brief Constructor de la clase
         * \param pRuta es un string que contiene la direccion donde se va leer el archivo
         */
    GestorDeArchivosAIC(string pRuta);
    /*!
         * \brief Cargar es un metodo redefinido que lee los datos de archivos AIC y los carga a
         * la imagen
         * \return El metodo devuelve un objeto de tipo Imagen en el que se cargaron los datos leidos
         */
    Imagen virtual Cargar() override;
    /*!
         * \brief guardar es un metodo redefinido que se encarga de guardar archivos aic
         * \param pNombre es el nombre del archivo en el cual se van a guardar los datos
         * \param pFormato el el formato de archivo en el cual se van a guardar los datos
         * \param pImagen es una referencia a un objeto imagen que sera guardado.
         */
    void  virtual Guardar(string pNombre,string pFormato, Imagen &pImagen) override;


private:
    /*!
      * \brief Ruta almacena la ruta donde se lee el archivo
      */
    string Ruta;

};

#endif // GESTORDEARCHIVOSAIC_H
